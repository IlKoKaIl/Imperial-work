#!/usr/bin/env bash
set -euo pipefail

if [[ ! -d hls-samples/.git ]]; then
  git clone --depth 1 https://github.com/altera-fpga/hls-samples.git hls-samples
fi

echo "oneAPI FPGA dev container is ready."
echo "Smoke test:"
echo "  cd hls-samples/Tutorials/GettingStarted/fpga_compile"
echo "  mkdir -p build && cd build"
echo "  cmake .. -DPART=2 && make fpga_emu"
echo "  ./vector_add.fpga_emu"
