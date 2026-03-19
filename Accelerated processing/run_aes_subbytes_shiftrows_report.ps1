param(
    [string]$ImageName = "oneapi-fpga-dev:2025",
    [string]$UserFlags = "",
    [switch]$RebuildImage
)

$ErrorActionPreference = "Stop"

$workspaceRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$projectRoot = Join-Path $workspaceRoot "aes_subbytes_shiftrows_mvp"

if (-not (Test-Path $projectRoot)) {
    throw "Project not found at '$projectRoot'."
}

& docker image inspect $ImageName *> $null
if ($LASTEXITCODE -ne 0 -or $RebuildImage) {
    Write-Host "Building Docker image $ImageName"
    & docker build -t $ImageName $workspaceRoot
    if ($LASTEXITCODE -ne 0) {
        throw "docker build failed."
    }
}

$cmakeFlags = "-DCMAKE_BUILD_TYPE=Release"
if ($UserFlags) {
    $cmakeFlags += " -DUSER_FLAGS='$UserFlags'"
}

$containerCommand = @"
set -euo pipefail

source /opt/intel/oneapi/setvars.sh --force >/dev/null 2>&1
cd /workspaces/accelerated-processing/aes_subbytes_shiftrows_mvp
rm -rf build
mkdir build
cd build
cmake .. $cmakeFlags
make report
"@

$dockerArgs = @(
    "run",
    "--rm",
    "-v", "${workspaceRoot}:/workspaces/accelerated-processing",
    "-w", "/workspaces/accelerated-processing",
    $ImageName,
    "bash",
    "-c",
    $containerCommand
)

$savedErrorActionPreference = $ErrorActionPreference
$ErrorActionPreference = "Continue"
$dockerOutput = & docker @dockerArgs 2>&1
$dockerExitCode = $LASTEXITCODE
$ErrorActionPreference = $savedErrorActionPreference

if ($dockerExitCode -ne 0) {
    $dockerOutput | ForEach-Object { Write-Host "$_" }
    throw "docker run failed."
}

$reportHtml = Join-Path $projectRoot "build\\aes_subbytes_shiftrows.report.prj\\reports\\report.html"
$reportZip = Join-Path $projectRoot "build\\aes_subbytes_shiftrows.report.prj\\reports\\aes_subbytes_shiftrows_report.zip"

if (-not (Test-Path $reportHtml)) {
    $dockerOutput | ForEach-Object { Write-Host "$_" }
    throw "Build finished but '$reportHtml' was not created."
}

$dockerOutput |
    Where-Object { $_ -notmatch "^Segmentation fault" } |
    ForEach-Object { Write-Host "$_" }

$reportHtml = (Resolve-Path $reportHtml).Path
$reportZip = (Resolve-Path $reportZip).Path

Write-Host ""
Write-Host "Report HTML: $reportHtml"
Write-Host "Report ZIP:  $reportZip"
