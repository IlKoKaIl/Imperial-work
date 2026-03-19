#include <stdint.h>
#include <stdio.h>
#include <string.h>

// ================= FPGA SYCL HEADERS =================
#include <sycl/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>

using sycl::ext::intel::fpga_reg;

// Forward-declare kernel ID (FPGA best practice)
class AESCTRKernelEncrypt;
class AESCTRKernelDecrypt;

#define N           1024
#define AES_BLOCK   16
#define AES_ROUNDS  10

// Parallelization engines parameters
#define PAR   1
#define BLOCK 16

// ------------------------------------------------------------
// AES SBOX (256 entries)
// ------------------------------------------------------------
[[intel::numbanks(16)]]
[[intel::bankwidth(1)]]
static const uint8_t sbox[256] = {
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
};

// ------------------------------------------------------------
// GF(2^8) multiplication by x
// ------------------------------------------------------------
static inline uint8_t xtime(uint8_t x) {
    return (uint8_t)((x << 1) ^ ((x >> 7) * 0x1b));
}

// ---- SubBytes ----
static inline void subbytes_pl(const uint8_t in[16], uint8_t out[16]) {
  #pragma unroll
  for (int i = 0; i < 16; i++)
    out[i] = sbox[in[i]];
}

// ---- ShiftRows ----
static inline void shiftrows_pl(const uint8_t in[16], uint8_t out[16]) {
  out[0]=in[0];  out[1]=in[5];  out[2]=in[10]; out[3]=in[15];
  out[4]=in[4];  out[5]=in[9];  out[6]=in[14]; out[7]=in[3];
  out[8]=in[8];  out[9]=in[13]; out[10]=in[2]; out[11]=in[7];
  out[12]=in[12];out[13]=in[1]; out[14]=in[6]; out[15]=in[11];
}

// ---- MixColumns ----
static inline void mixcolumns_pl(const uint8_t in[16], uint8_t out[16]) {
  #pragma unroll
  for (int c = 0; c < 4; c++) {
    uint8_t a  = in[c*4+0];
    uint8_t b  = in[c*4+1];
    uint8_t c1 = in[c*4+2];
    uint8_t d  = in[c*4+3];
    uint8_t e  = (uint8_t)(a ^ b ^ c1 ^ d);
    out[c*4+0] = (uint8_t)(a ^ e ^ xtime((uint8_t)(a ^ b)));
    out[c*4+1] = (uint8_t)(b ^ e ^ xtime((uint8_t)(b ^ c1)));
    out[c*4+2] = (uint8_t)(c1 ^ e ^ xtime((uint8_t)(c1 ^ d)));
    out[c*4+3] = (uint8_t)(d ^ e ^ xtime((uint8_t)(d ^ a)));
  }
}

// ---- AddRoundKey ----
static inline void addroundkey_pl(const uint8_t in[16], const uint8_t key[16], uint8_t out[16]) {
  #pragma unroll
  for (int i = 0; i < 16; i++)
    out[i] = (uint8_t)(in[i] ^ key[i]);
}

// ---- One AES round (last==true → no MixColumns) ----
static inline void aes_round_pl(const uint8_t in[16], uint8_t out[16],
                                const uint8_t key[16], bool last) {
  uint8_t s1[16], s2[16];
  subbytes_pl(in, s1);
  shiftrows_pl(s1, s2);
  if (!last) {
    uint8_t s3[16];
    mixcolumns_pl(s2, s3);
    addroundkey_pl(s3, key, out);
  } else {
    addroundkey_pl(s2, key, out);
  }
}

// Accepts one input block per iteration; produces one output block per iteration after fill.
// II=1 expected if memory allows one 16B load/store per cycle.
//
// Inputs:
//   in_blk[16]  : new block at this cycle (valid if in_valid)
//   out_blk[16] : ciphertext at this cycle (valid when out_valid)
//   key[16]     : fixed per call (demo)
//   in_valid    : assert when feeding a new block
//   out_valid   : asserted by core when output is valid (after initial fill)
//
// Notes:
//   This core is *stateful* across calls inside the t-loop (stage registers persist).
//
struct AesStreamCore {
  // 11 stage registers
  uint8_t r0[16], r1[16], r2[16], r3[16], r4[16], r5[16], r6[16], r7[16], r8[16], r9[16], r10[16];

  AesStreamCore() {
    #pragma unroll
    for (int i = 0; i < 16; i++)
      r0[i]=r1[i]=r2[i]=r3[i]=r4[i]=r5[i]=r6[i]=r7[i]=r8[i]=r9[i]=r10[i]=0;
  }

  inline void step(const uint8_t in_blk[16], uint8_t out_blk[16],
                   const uint8_t key[16], bool in_valid) {

    // Stage 0: new input (or bubble = keep previous r0)
    uint8_t n0[16];
    if (in_valid) {
      addroundkey_pl(in_blk, key, n0);
    } else {
      #pragma unroll
      for (int i = 0; i < 16; i++) n0[i] = r0[i];
    }

    // Compute next values for stages 1..10 from current r0..r9
    uint8_t n1[16], n2[16], n3[16], n4[16], n5[16], n6[16], n7[16], n8[16], n9[16], n10[16];
    aes_round_pl(r0, n1,   key, false);
    aes_round_pl(r1, n2,   key, false);
    aes_round_pl(r2, n3,   key, false);
    aes_round_pl(r3, n4,   key, false);
    aes_round_pl(r4, n5,   key, false);
    aes_round_pl(r5, n6,   key, false);
    aes_round_pl(r6, n7,   key, false);
    aes_round_pl(r7, n8,   key, false);
    aes_round_pl(r8, n9,   key, false);
    aes_round_pl(r9, n10,  key, true);

    // Commit next state
    #pragma unroll
    for (int i = 0; i < 16; i++) {
      r10[i]=n10[i]; r9[i]=n9[i]; r8[i]=n8[i]; r7[i]=n7[i]; r6[i]=n6[i];
      r5[i]=n5[i]; r4[i]=n4[i]; r3[i]=n3[i]; r2[i]=n2[i]; r1[i]=n1[i]; r0[i]=n0[i];
      out_blk[i] = r10[i];
    }
  }
};

// Adds 'inc' to big-endian 128-bit counter in place
static inline void add_to_counter_be(uint8_t ctr[16], unsigned inc) {
  unsigned carry = inc;
  for (int i = 15; i >= 0; i--) {
    unsigned sum = (unsigned)ctr[i] + (carry & 0xFFu);
    ctr[i] = (uint8_t)sum;
    carry  = sum >> 8;
    if (!carry) break;
  }
}

// One CTR lane: processes 'lane_blocks' blocks spaced by 'stride' bytes.
// Expects memory to sustain one 16B load + one 16B store per cycle.
__attribute__((always_inline))
static void aes_ctr_lane_stream(const uint8_t *in_base,
                                uint8_t       *out_base,
                                int lane_blocks,
                                const uint8_t key[16],
                                const uint8_t ctr_start[16],
                                int stride_bytes) {

  // Local rolling counter for this lane
  uint8_t ctr[16];
  #pragma unroll
  for (int i = 0; i < 16; i++) ctr[i] = ctr_start[i];

  // Delay buffers to align plaintext with the Stage-10 keystream
  uint8_t pt_fifo[AES_ROUNDS][16];
  int     addr_fifo[AES_ROUNDS];

  AesStreamCore core;

  // II=1 iteration over "virtual cycles" for this lane
  #pragma ii 1
  for (int t = 0; t < lane_blocks + AES_ROUNDS; t++) {

    const int slot = t % AES_ROUNDS;  // the slot to POP (old) then PUSH (new)

    // Prepare inputs for this cycle (but do NOT write FIFO yet)
    const bool in_valid = (t < lane_blocks);

    uint8_t in_counter[16] = {0};   // only read when in_valid==true
    uint8_t pt_new[16];       // new plaintext block
    int     addr_new = 0;     // byte offset for the new block

    if (in_valid) {
      const uint8_t *p_in  = in_base + t * stride_bytes;
      #pragma unroll
      for (int i = 0; i < 16; i++) pt_new[i] = p_in[i];
      addr_new = t * stride_bytes;

      #pragma unroll
      for (int i = 0; i < 16; i++) in_counter[i] = ctr[i];

      // Prepare counter for the next cycle (advance by PAR for this lane)
      add_to_counter_be(ctr, (unsigned)PAR);
    }

    // Advance AES pipeline one step; produce keystream for (t - AES_ROUNDS)
    uint8_t ks[16];
    core.step(in_counter, ks, key, in_valid);

    // --- POP: use the keystream with the plaintext from AES_ROUNDS cycles ago ---
    if (t >= AES_ROUNDS) {
      const uint8_t *pt_old = pt_fifo[slot];       // the oldest entry
      uint8_t *p_out = out_base + addr_fifo[slot]; // matching destination
      #pragma unroll
      for (int i = 0; i < 16; i++)
        p_out[i] = (uint8_t)(pt_old[i] ^ ks[i]);
    }

    // --- PUSH: store the new plaintext/address into the same slot ---
    if (in_valid) {
      #pragma unroll
      for (int i = 0; i < 16; i++) pt_fifo[slot][i] = pt_new[i];
      addr_fifo[slot] = addr_new;
    }
  }
}

// Parallel CTR using PAR streaming lanes (each lane: II=1).
void aes_ctr_parallel_streamed(uint8_t *in,
                               uint8_t *out,
                               int size,
                               const uint8_t key[16],
                               uint8_t counter[16]) {

  const int total_blocks = size / 16;      // full blocks
  const int stride_bytes = PAR * 16;

  // Prepare lane starting counters = counter + p
  uint8_t ctr_lane[PAR][16];
  #pragma unroll
  for (int p = 0; p < PAR; p++) {
    #pragma unroll
    for (int j = 0; j < 16; j++)
      ctr_lane[p][j] = counter[j];
    add_to_counter_be(ctr_lane[p], (unsigned)p);
  }

  // Number of blocks per lane (last lanes may process one fewer)
  int lane_blocks[PAR];
  #pragma unroll
  for (int p = 0; p < PAR; p++) {
    // Blocks handled by lane p: indices p, p+PAR, p+2*PAR, ...
    int remaining = (total_blocks - p > 0) ? (total_blocks - p) : 0;
    lane_blocks[p] = (remaining + PAR - 1) / PAR;
  }

  // Instantiate PAR lanes in parallel
  #pragma unroll
  for (int p = 0; p < PAR; p++) {
    const uint8_t *in_base  = in  + p*16;
    uint8_t       *out_base = out + p*16;
    aes_ctr_lane_stream(in_base, out_base, lane_blocks[p],
                        key, ctr_lane[p], stride_bytes);
  }

  // Tail (partial final block < 16 bytes), if any
  const int tail_bytes = size - total_blocks * 16;
  if (tail_bytes > 0) {
    // Process last partial block with scalar reference (pipeline ok for one block)
    uint8_t ks[16];
    uint8_t ctr_tail[16];
    // counter advanced by total_blocks overall:
    #pragma unroll
    for (int j = 0; j < 16; j++) ctr_tail[j] = counter[j];
    add_to_counter_be(ctr_tail, (unsigned)total_blocks);

    // Run one block through AES (reusing stream core once is overkill; do scalar)
    // Minimal scalar AES using the same round helpers:
    uint8_t st[16];
    #pragma unroll
    for (int i = 0; i < 16; i++) st[i] = ctr_tail[i];
    // Initial ARK
    uint8_t tmp0[16];
    addroundkey_pl(st, key, tmp0);
    // 10 rounds (final without MixColumns)
    for (int r = 0; r < AES_ROUNDS; r++) {
      uint8_t tmp1[16];
      aes_round_pl(tmp0, tmp1, key, r == AES_ROUNDS - 1);
      #pragma unroll
      for (int i = 0; i < 16; i++) tmp0[i] = tmp1[i];
    }
    #pragma unroll
    for (int i = 0; i < 16; i++) ks[i] = tmp0[i];

    // XOR last partial
    uint8_t *pin  = in  + total_blocks * 16;
    uint8_t *pout = out + total_blocks * 16;
    for (int j = 0; j < tail_bytes; j++) pout[j] = (uint8_t)(pin[j] ^ ks[j]);
  }

  // Advance global counter by total_blocks (CTR's logical position)
  add_to_counter_be(counter, (unsigned)total_blocks);
}

// ------------------------------------------------------------
// Test harness
// ------------------------------------------------------------

int main() {

    // -------------------------------------------------------
    // choose FPGA device: emulator by default
    // -------------------------------------------------------
    #if FPGA_SIMULATOR
    auto selector = sycl::ext::intel::fpga_simulator_selector_v;
    #elif FPGA_HARDWARE
    auto selector = sycl::ext::intel::fpga_selector_v;
    #else
    auto selector = sycl::ext::intel::fpga_emulator_selector_v;
    #endif

    sycl::queue q(selector);

    printf("Running on: %s\n",
           q.get_device()
           .get_info<sycl::info::device::name>()
           .c_str());

    // -------------------------------------------------------
    // Allocate USM shared memory for FPGA access
    // -------------------------------------------------------
    uint8_t *plaintext  = sycl::malloc_shared<uint8_t>(N, q);
    uint8_t *ciphertext = sycl::malloc_shared<uint8_t>(N, q);
    uint8_t *decrypted  = sycl::malloc_shared<uint8_t>(N, q);

    uint8_t *key     = sycl::malloc_shared<uint8_t>(16, q);
    uint8_t *counter = sycl::malloc_shared<uint8_t>(16, q);
    uint8_t *counter2 = sycl::malloc_shared<uint8_t>(16, q);

    // initialize
    for (int i = 0; i < N; i++)
        plaintext[i] = (uint8_t)(i & 0xFF);

    for (int i = 0; i < 16; i++) {
        key[i] = i;
        counter[i] = 0;
        counter2[i] = 0;
    }

    // -------------------------------------------------------
    // FPGA KERNEL #1 : Encrypt using aes_ctr_parallel
    // -------------------------------------------------------
    q.single_task<AESCTRKernelEncrypt>([=]() [[intel::kernel_args_restrict]]{
        aes_ctr_parallel_streamed(plaintext, ciphertext, N, key, counter);
    }).wait();

    // -------------------------------------------------------
    // FPGA KERNEL #2 : Decrypt (CTR mode is symmetric)
    // -------------------------------------------------------
    q.single_task<AESCTRKernelDecrypt>([=]() [[intel::kernel_args_restrict]]{
        aes_ctr_parallel_streamed(ciphertext, decrypted, N, key, counter2);
    }).wait();

    // -------------------------------------------------------
    // verify correctness
    // -------------------------------------------------------
    int pass = 1;
    for (int i = 0; i < N; i++) {
        if (plaintext[i] != decrypted[i]) {
            pass = 0;
            break;
        }
    }

    printf(pass ? "PASSED\n" : "FAILED\n");

    sycl::free(plaintext, q);
    sycl::free(ciphertext, q);
    sycl::free(decrypted, q);
    sycl::free(key, q);
    sycl::free(counter, q);
    sycl::free(counter2, q);

    return pass ? 0 : 1;
}
