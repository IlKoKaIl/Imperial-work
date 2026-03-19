#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <sycl/ext/intel/fpga_extensions.hpp>
#include <sycl/sycl.hpp>

#include "exception_handler.hpp"

namespace {

constexpr int kInputBytes = 1024;
constexpr int kBlockBytes = 16;
constexpr int kRounds = 10;
constexpr int kParallelLanes = 1;

// This is a structural full-round compile test. It integrates all four AES
// round steps inside a CTR-style pipeline, but it intentionally reuses the same
// 16-byte round key at each round. That makes it useful for FPGA pipeline and
// compile experiments, but it is not a standards-accurate AES-128 or AES-256
// key schedule implementation yet.

constexpr std::uint8_t kShiftRowsSourceIndex[kBlockBytes] = {
    0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11};

constexpr std::uint8_t kAesSBox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b,
    0xfe, 0xd7, 0xab, 0x76, 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
    0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 0xb7, 0xfd, 0x93, 0x26,
    0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2,
    0xeb, 0x27, 0xb2, 0x75, 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
    0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, 0x53, 0xd1, 0x00, 0xed,
    0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f,
    0x50, 0x3c, 0x9f, 0xa8, 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
    0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, 0xcd, 0x0c, 0x13, 0xec,
    0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14,
    0xde, 0x5e, 0x0b, 0xdb, 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
    0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, 0xe7, 0xc8, 0x37, 0x6d,
    0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f,
    0x4b, 0xbd, 0x8b, 0x8a, 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
    0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, 0xe1, 0xf8, 0x98, 0x11,
    0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f,
    0xb0, 0x54, 0xbb, 0x16};

class AesCtrEncryptKernelID;
class AesCtrDecryptKernelID;

std::uint64_t GetKernelDurationNs(const sycl::event &event) {
  const auto start =
      event.get_profiling_info<sycl::info::event_profiling::command_start>();
  const auto end =
      event.get_profiling_info<sycl::info::event_profiling::command_end>();
  return static_cast<std::uint64_t>(end - start);
}

inline std::uint8_t Xtime(std::uint8_t x) {
  return static_cast<std::uint8_t>((x << 1) ^ ((x >> 7) * 0x1b));
}

inline void AddRoundKey(const std::uint8_t in[kBlockBytes],
                        const std::uint8_t key[kBlockBytes],
                        std::uint8_t out[kBlockBytes]) {
#pragma unroll
  for (int idx = 0; idx < kBlockBytes; ++idx) {
    out[idx] = static_cast<std::uint8_t>(in[idx] ^ key[idx]);
  }
}

inline void SubBytesShiftRowsFused(const std::uint8_t in[kBlockBytes],
                                   std::uint8_t out[kBlockBytes]) {
  for (int out_idx = 0; out_idx < kBlockBytes; ++out_idx) {
    const int src_idx = kShiftRowsSourceIndex[out_idx];
    out[out_idx] = kAesSBox[in[src_idx]];
  }
}

inline void MixColumns(const std::uint8_t in[kBlockBytes],
                       std::uint8_t out[kBlockBytes]) {
#pragma unroll
  for (int col = 0; col < 4; ++col) {
    const std::uint8_t a = in[col * 4 + 0];
    const std::uint8_t b = in[col * 4 + 1];
    const std::uint8_t c = in[col * 4 + 2];
    const std::uint8_t d = in[col * 4 + 3];
    const std::uint8_t e = static_cast<std::uint8_t>(a ^ b ^ c ^ d);

    out[col * 4 + 0] =
        static_cast<std::uint8_t>(a ^ e ^ Xtime(static_cast<std::uint8_t>(a ^ b)));
    out[col * 4 + 1] =
        static_cast<std::uint8_t>(b ^ e ^ Xtime(static_cast<std::uint8_t>(b ^ c)));
    out[col * 4 + 2] =
        static_cast<std::uint8_t>(c ^ e ^ Xtime(static_cast<std::uint8_t>(c ^ d)));
    out[col * 4 + 3] =
        static_cast<std::uint8_t>(d ^ e ^ Xtime(static_cast<std::uint8_t>(d ^ a)));
  }
}

inline void AesRound(const std::uint8_t in[kBlockBytes],
                     std::uint8_t out[kBlockBytes],
                     const std::uint8_t round_key[kBlockBytes], bool last_round) {
  std::uint8_t transformed[kBlockBytes];
  SubBytesShiftRowsFused(in, transformed);

  if (!last_round) {
    std::uint8_t mixed[kBlockBytes];
    MixColumns(transformed, mixed);
    AddRoundKey(mixed, round_key, out);
  } else {
    AddRoundKey(transformed, round_key, out);
  }
}

struct AesCtrStreamCore {
  std::uint8_t stage0[kBlockBytes];
  std::uint8_t stage1[kBlockBytes];
  std::uint8_t stage2[kBlockBytes];
  std::uint8_t stage3[kBlockBytes];
  std::uint8_t stage4[kBlockBytes];
  std::uint8_t stage5[kBlockBytes];
  std::uint8_t stage6[kBlockBytes];
  std::uint8_t stage7[kBlockBytes];
  std::uint8_t stage8[kBlockBytes];
  std::uint8_t stage9[kBlockBytes];
  std::uint8_t stage10[kBlockBytes];

  AesCtrStreamCore() {
#pragma unroll
    for (int idx = 0; idx < kBlockBytes; ++idx) {
      stage0[idx] = 0;
      stage1[idx] = 0;
      stage2[idx] = 0;
      stage3[idx] = 0;
      stage4[idx] = 0;
      stage5[idx] = 0;
      stage6[idx] = 0;
      stage7[idx] = 0;
      stage8[idx] = 0;
      stage9[idx] = 0;
      stage10[idx] = 0;
    }
  }

  inline void Step(const std::uint8_t input_counter[kBlockBytes],
                   std::uint8_t keystream_out[kBlockBytes],
                   const std::uint8_t round_key[kBlockBytes], bool input_valid) {
    std::uint8_t next0[kBlockBytes];
    if (input_valid) {
      AddRoundKey(input_counter, round_key, next0);
    } else {
#pragma unroll
      for (int idx = 0; idx < kBlockBytes; ++idx) {
        next0[idx] = stage0[idx];
      }
    }

    std::uint8_t next1[kBlockBytes];
    std::uint8_t next2[kBlockBytes];
    std::uint8_t next3[kBlockBytes];
    std::uint8_t next4[kBlockBytes];
    std::uint8_t next5[kBlockBytes];
    std::uint8_t next6[kBlockBytes];
    std::uint8_t next7[kBlockBytes];
    std::uint8_t next8[kBlockBytes];
    std::uint8_t next9[kBlockBytes];
    std::uint8_t next10[kBlockBytes];

    AesRound(stage0, next1, round_key, false);
    AesRound(stage1, next2, round_key, false);
    AesRound(stage2, next3, round_key, false);
    AesRound(stage3, next4, round_key, false);
    AesRound(stage4, next5, round_key, false);
    AesRound(stage5, next6, round_key, false);
    AesRound(stage6, next7, round_key, false);
    AesRound(stage7, next8, round_key, false);
    AesRound(stage8, next9, round_key, false);
    AesRound(stage9, next10, round_key, true);

#pragma unroll
    for (int idx = 0; idx < kBlockBytes; ++idx) {
      stage10[idx] = next10[idx];
      stage9[idx] = next9[idx];
      stage8[idx] = next8[idx];
      stage7[idx] = next7[idx];
      stage6[idx] = next6[idx];
      stage5[idx] = next5[idx];
      stage4[idx] = next4[idx];
      stage3[idx] = next3[idx];
      stage2[idx] = next2[idx];
      stage1[idx] = next1[idx];
      stage0[idx] = next0[idx];
      keystream_out[idx] = stage10[idx];
    }
  }
};

inline void AddToCounterBe(std::uint8_t counter[kBlockBytes], unsigned increment) {
  unsigned carry = increment;
  for (int idx = kBlockBytes - 1; idx >= 0; --idx) {
    const unsigned sum = static_cast<unsigned>(counter[idx]) + (carry & 0xffu);
    counter[idx] = static_cast<std::uint8_t>(sum);
    carry = sum >> 8;
    if (carry == 0) {
      break;
    }
  }
}

inline void AesCtrLaneStream(const std::uint8_t *input_base,
                             std::uint8_t *output_base, int lane_blocks,
                             const std::uint8_t round_key[kBlockBytes],
                             const std::uint8_t counter_start[kBlockBytes],
                             int stride_bytes) {
  std::uint8_t counter[kBlockBytes];
#pragma unroll
  for (int idx = 0; idx < kBlockBytes; ++idx) {
    counter[idx] = counter_start[idx];
  }

  std::uint8_t plaintext_fifo[kRounds][kBlockBytes];
  int address_fifo[kRounds];
#pragma unroll
  for (int round = 0; round < kRounds; ++round) {
    address_fifo[round] = 0;
#pragma unroll
    for (int idx = 0; idx < kBlockBytes; ++idx) {
      plaintext_fifo[round][idx] = 0;
    }
  }

  AesCtrStreamCore core;

  [[intel::initiation_interval(1)]]
  for (int cycle = 0; cycle < lane_blocks + kRounds; ++cycle) {
    const int slot = cycle % kRounds;
    const bool input_valid = cycle < lane_blocks;

    std::uint8_t input_counter[kBlockBytes] = {0};
    std::uint8_t plaintext_new[kBlockBytes] = {0};
    int address_new = 0;

    if (input_valid) {
      const std::uint8_t *plaintext_ptr =
          input_base + cycle * stride_bytes;
#pragma unroll
      for (int idx = 0; idx < kBlockBytes; ++idx) {
        plaintext_new[idx] = plaintext_ptr[idx];
        input_counter[idx] = counter[idx];
      }
      address_new = cycle * stride_bytes;
      AddToCounterBe(counter, static_cast<unsigned>(kParallelLanes));
    }

    std::uint8_t keystream[kBlockBytes];
    core.Step(input_counter, keystream, round_key, input_valid);

    if (cycle >= kRounds) {
      const std::uint8_t *plaintext_old = plaintext_fifo[slot];
      std::uint8_t *output_ptr = output_base + address_fifo[slot];
#pragma unroll
      for (int idx = 0; idx < kBlockBytes; ++idx) {
        output_ptr[idx] =
            static_cast<std::uint8_t>(plaintext_old[idx] ^ keystream[idx]);
      }
    }

    if (input_valid) {
#pragma unroll
      for (int idx = 0; idx < kBlockBytes; ++idx) {
        plaintext_fifo[slot][idx] = plaintext_new[idx];
      }
      address_fifo[slot] = address_new;
    }
  }
}

inline void AesCtrStructuralTest(std::uint8_t *input, std::uint8_t *output,
                                 int size,
                                 const std::uint8_t round_key[kBlockBytes],
                                 std::uint8_t counter[kBlockBytes]) {
  const int total_blocks = size / kBlockBytes;
  const int stride_bytes = kParallelLanes * kBlockBytes;

  std::uint8_t lane_counters[kParallelLanes][kBlockBytes];
  int lane_blocks[kParallelLanes];

#pragma unroll
  for (int lane = 0; lane < kParallelLanes; ++lane) {
#pragma unroll
    for (int idx = 0; idx < kBlockBytes; ++idx) {
      lane_counters[lane][idx] = counter[idx];
    }
    AddToCounterBe(lane_counters[lane], static_cast<unsigned>(lane));

    const int remaining = (total_blocks - lane > 0) ? (total_blocks - lane) : 0;
    lane_blocks[lane] = (remaining + kParallelLanes - 1) / kParallelLanes;
  }

#pragma unroll
  for (int lane = 0; lane < kParallelLanes; ++lane) {
    AesCtrLaneStream(input + lane * kBlockBytes, output + lane * kBlockBytes,
                     lane_blocks[lane], round_key, lane_counters[lane],
                     stride_bytes);
  }

  AddToCounterBe(counter, static_cast<unsigned>(total_blocks));
}

}  // namespace

int main() {
  bool passed = false;

  try {
#if FPGA_SIMULATOR
    auto selector = sycl::ext::intel::fpga_simulator_selector_v;
#elif FPGA_HARDWARE
    auto selector = sycl::ext::intel::fpga_selector_v;
#else
    auto selector = sycl::ext::intel::fpga_emulator_selector_v;
#endif

    sycl::queue q(selector, fpga_tools::exception_handler,
                  sycl::property::queue::enable_profiling{});

    auto device = q.get_device();
    auto *plaintext = sycl::malloc_shared<std::uint8_t>(kInputBytes, q);
    auto *ciphertext = sycl::malloc_shared<std::uint8_t>(kInputBytes, q);
    auto *decrypted = sycl::malloc_shared<std::uint8_t>(kInputBytes, q);
    auto *round_key = sycl::malloc_shared<std::uint8_t>(kBlockBytes, q);
    auto *encrypt_counter = sycl::malloc_shared<std::uint8_t>(kBlockBytes, q);
    auto *decrypt_counter = sycl::malloc_shared<std::uint8_t>(kBlockBytes, q);

    for (int idx = 0; idx < kInputBytes; ++idx) {
      plaintext[idx] = static_cast<std::uint8_t>((idx * 17 + 11) & 0xff);
      ciphertext[idx] = 0;
      decrypted[idx] = 0;
    }
    for (int idx = 0; idx < kBlockBytes; ++idx) {
      round_key[idx] = static_cast<std::uint8_t>(idx);
      encrypt_counter[idx] = 0;
      decrypt_counter[idx] = 0;
    }

    std::cout << "Running on device: "
              << device.get_info<sycl::info::device::name>() << '\n';
    std::cout << "Running full CTR structural compile test over " << kInputBytes
              << " bytes" << std::endl;
    std::cout << "Note: this kernel integrates all four AES round steps but "
                 "uses a fixed round key each round for compile testing."
              << std::endl;

    sycl::event encrypt_event =
        q.single_task<AesCtrEncryptKernelID>([=]() [[intel::kernel_args_restrict]] {
          AesCtrStructuralTest(plaintext, ciphertext, kInputBytes, round_key,
                               encrypt_counter);
        });
    encrypt_event.wait();

    sycl::event decrypt_event =
        q.single_task<AesCtrDecryptKernelID>([=]() [[intel::kernel_args_restrict]] {
          AesCtrStructuralTest(ciphertext, decrypted, kInputBytes, round_key,
                               decrypt_counter);
        });
    decrypt_event.wait();

    passed = true;
    for (int idx = 0; idx < kInputBytes; ++idx) {
      if (plaintext[idx] != decrypted[idx]) {
        std::cout << "Mismatch at byte " << idx << ": got "
                  << static_cast<int>(decrypted[idx]) << ", expected "
                  << static_cast<int>(plaintext[idx]) << std::endl;
        passed = false;
        break;
      }
    }

    try {
      const double encrypt_ms =
          static_cast<double>(GetKernelDurationNs(encrypt_event)) / 1.0e6;
      const double decrypt_ms =
          static_cast<double>(GetKernelDurationNs(decrypt_event)) / 1.0e6;
      std::cout << "Encrypt kernel profiling time: " << encrypt_ms << " ms"
                << std::endl;
      std::cout << "Decrypt kernel profiling time: " << decrypt_ms << " ms"
                << std::endl;
      std::cout << "Use the FPGA report for meaningful II / throughput "
                   "interpretation."
                << std::endl;
    } catch (const sycl::exception &) {
      std::cout << "Profiling info unavailable on this target." << std::endl;
    }

    std::cout << (passed ? "PASSED" : "FAILED") << std::endl;

    sycl::free(plaintext, q);
    sycl::free(ciphertext, q);
    sycl::free(decrypted, q);
    sycl::free(round_key, q);
    sycl::free(encrypt_counter, q);
    sycl::free(decrypt_counter, q);
  } catch (const sycl::exception &e) {
    std::cerr << "Caught a SYCL host exception:\n" << e.what() << '\n';
    std::terminate();
  }

  return passed ? EXIT_SUCCESS : EXIT_FAILURE;
}
