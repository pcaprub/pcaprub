$ErrorActionPreference = 'Stop'

# 1) Install the winpcap developer files for compiling the pcaprub_c.so file - this happens when rake is run
choco install -y --limitoutput 7zip
$wpdPcapZip = 'C:\Windows\Temp\WpdPack_4_1_2.zip'
(New-Object System.Net.WebClient).DownloadFile('https://www.winpcap.org/install/bin/WpdPack_4_1_2.zip', $wpdPcapZip)
Get-ChildItem $wpdPcapZip
C:\ProgramData\chocolatey\bin\7z.exe x $wpdPcapZip -aoa -o"C:\"
Get-ChildItem C:\

if (!(Test-Path -Path C:\WpdPack\Lib\x64\wpcap.lib)) {
    throw "failed extracting wpcap.lib for compilation"
}

# 2) Install the winpcap dll - required at runtime when tests are being run as part of 'bundle exec rake'
# Note that a minimal autohotkey install file is used for now as the current choco package is broken
choco install -y --limitoutput autohotkey.portable
$winPcapExe = "c:\Windows\Temp\WinPcap_4_1_3.exe"
(New-Object System.Net.WebClient).DownloadFile('https://www.winpcap.org/install/bin/WinPcap_4_1_3.exe', $winPcapExe)

$installScript = "$($env:GITHUB_WORKSPACE)\script\installwinpcap.ahk"
Get-Content $installScript
AutoHotkey /ErrorStdOut $installScript $winPcapExe 2>&1 | more
Get-Content "$($env:GITHUB_WORKSPACE)\script\installwinpcap_debug.txt"

if (!(Test-Path -Path C:\Windows\System32\wpcap.dll)) {
    throw "failed installing wpcap.dll for runtime tests"
}
