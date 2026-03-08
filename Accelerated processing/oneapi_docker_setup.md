# oneAPI FPGA Container Setup (Docker Desktop + VS Code)

## Option 1: VS Code Dev Container (recommended)

1. Start Docker Desktop.
2. Open `Accelerated processing` in VS Code.
3. Install the VS Code extension `Dev Containers` (if missing).
4. Run: `Dev Containers: Reopen in Container`.
5. Wait for image build + container startup.

The post-create step clones:

`https://github.com/altera-fpga/hls-samples` into `./hls-samples`.

### Quick smoke test in the VS Code terminal

```bash
icpx --version
cd hls-samples/Tutorials/GettingStarted/fpga_compile
mkdir -p build && cd build
cmake .. -DPART=2
make fpga_emu
./vector_add.fpga_emu
```

If you ever see linker errors like `cannot find -ldspba_mpir`, run:

```bash
source /opt/intel/oneapi/setvars.sh --force
```

## Option 2: Plain Docker Desktop CLI

From PowerShell in `Accelerated processing`:

```powershell
docker build -t oneapi-fpga-dev:2025 .
docker run --rm -it `
  -v "${PWD}:/workspaces/accelerated-processing" `
  -w /workspaces/accelerated-processing `
  oneapi-fpga-dev:2025
```

Then inside the container:

```bash
source /opt/intel/oneapi/setvars.sh --force
git clone --depth 1 https://github.com/altera-fpga/hls-samples.git
cd hls-samples/Tutorials/GettingStarted/fpga_compile
mkdir -p build && cd build
cmake .. -DPART=2
make fpga_emu
./vector_add.fpga_emu
```

## Notes

- `setvars.sh` is sourced automatically for interactive shells through `/etc/profile.d/oneapi.sh`.
- Emulation (`fpga_emu`) works in this container setup for development.
- Full hardware compile/runtime needs Quartus, BSP/device files, and target board access that are usually set up outside a lightweight dev container.
