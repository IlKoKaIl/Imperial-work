param(
    [string]$ImageName = "oneapi-fpga-dev:2025",
    [switch]$RebuildImage
)

$ErrorActionPreference = "Stop"

$workspaceRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$sampleRoot = Join-Path $workspaceRoot "hls-samples\\Tutorials\\GettingStarted\\fpga_template"

if (-not (Test-Path $sampleRoot)) {
    throw "Sample not found at '$sampleRoot'. Clone hls-samples into '$workspaceRoot' first."
}

& docker image inspect $ImageName *> $null
if ($LASTEXITCODE -ne 0 -or $RebuildImage) {
    Write-Host "Building Docker image $ImageName"
    & docker build -t $ImageName $workspaceRoot
    if ($LASTEXITCODE -ne 0) {
        throw "docker build failed."
    }
}

$containerCommand = @'
set -euo pipefail

source /opt/intel/oneapi/setvars.sh --force >/dev/null 2>&1
cd /workspaces/accelerated-processing/hls-samples/Tutorials/GettingStarted/fpga_template
rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make report
'@

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

$reportHtml = Join-Path $sampleRoot "build\\fpga_template.report.prj\\reports\\report.html"
$reportZip = Join-Path $sampleRoot "build\\fpga_template.report.prj\\reports\\fpga_template_report.zip"

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
