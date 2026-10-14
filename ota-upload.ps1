<#
  OTA-opplasting til klokka (ESP32) - bruk fra VS Code-terminalen eller Task.

  Eksempler:
    .\ota-upload.ps1                        # laster opp build\sketch.ino.bin til klokke-esp32.local
    .\ota-upload.ps1 -Compile               # kompilerer forst, deretter opplasting
    .\ota-upload.ps1 -Target 192.168.30.110 # bruk IP i stedet for navn (hvis mDNS ikke virker)
    .\ota-upload.ps1 -Password hemmelig     # hvis du har satt ArduinoOTA.setPassword(...)
#>
param(
  [string]$Target   = "klokke-esp32.local",
  [string]$Password = "",
  [int]$Port        = 3232,
  [switch]$Compile
)

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
$bin  = Join-Path $root "build\sketch.ino.bin"

# 1) Kompiler ved behov
if ($Compile -or -not (Test-Path $bin)) {
  Write-Host "==> Kompilerer..." -ForegroundColor Cyan
  arduino-cli compile --fqbn esp32:esp32:esp32 --build-path (Join-Path $root "build") (Join-Path $root "sketch")
  if ($LASTEXITCODE -ne 0) { throw "Kompilering feilet." }
}
if (-not (Test-Path $bin)) { throw "Fant ikke $bin - kompiler sketchen forst (bruk -Compile)." }

# 2) Finn espota.exe i nyeste installerte ESP32-pakke
$pkgRoot = Join-Path $env:LOCALAPPDATA "Arduino15\packages\esp32\hardware\esp32"
$espota = Get-ChildItem $pkgRoot -Directory |
  Sort-Object { [version]($_.Name -replace '[^0-9.].*$','') } -Descending |
  ForEach-Object { Join-Path $_.FullName "tools\espota.exe" } |
  Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $espota) { throw "Fant ikke espota.exe under $pkgRoot (er ESP32-pakken installert?)." }

# 3) Finn IP-adressen (espota vil ha en IP; .local-navn loses via mDNS)
$ip = $Target
if ($Target -notmatch '^\d{1,3}(\.\d{1,3}){3}$') {
  try {
    $ip = ([System.Net.Dns]::GetHostAddresses($Target) |
      Where-Object AddressFamily -eq 'InterNetwork' | Select-Object -First 1).IPAddressToString
  } catch {
    throw "Kunne ikke finne '$Target'. Sjekk at klokka er pa nett (se Serial Monitor) og bruk -Target <IP>."
  }
}
Write-Host "==> Laster opp til $Target ($ip) ..." -ForegroundColor Cyan

# 4) Last opp
$argsList = @("-i", $ip, "-p", $Port, "-f", $bin, "-r")
if ($Password) { $argsList += @("-a", $Password) }
& $espota @argsList
if ($LASTEXITCODE -ne 0) { throw "OTA-opplasting feilet (kode $LASTEXITCODE)." }
Write-Host "==> Ferdig! Klokka restarter med ny kode." -ForegroundColor Green

