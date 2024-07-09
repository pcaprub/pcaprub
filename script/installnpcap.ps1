$ErrorActionPreference = 'Stop'

# 1) Install the npcap developer files for compiling the pcaprub_c.so file - this happens when rake is run
choco install -y --limitoutput 7zip
$wpdPcapZip = 'C:\Windows\Temp\npcap-sdk-1.13.zip'
(New-Object System.Net.WebClient).DownloadFile('https://npcap.com/dist/npcap-sdk-1.13.zip', $wpdPcapZip)
Get-ChildItem $wpdPcapZip
C:\ProgramData\chocolatey\bin\7z.exe x $wpdPcapZip -aoa -o"C:\npcap-sdk\"
Get-ChildItem C:\

if (!(Test-Path -Path C:\npcap-sdk\Lib\x64\wpcap.lib)) {
    throw "failed extracting wpcap.lib for compilation"
}

# 2) Install the winpcap dll - required at runtime when tests are being run as part of 'bundle exec rake'
$npcapExe = "C:\Windows\Temp\npcap-0.90.exe"
(New-Object System.Net.WebClient).DownloadFile('https://nmap.org/npcap/dist/npcap-0.90.exe', $npcapExe)
Start-Process -FilePath "C:\Windows\Temp\npcap-0.90.exe" -ArgumentList "/S" -wait

if (!(Test-Path -Path C:\Windows\System32\Npcap\wpcap.dll)) {
    throw "failed installing wpcap.dll for runtime tests"
}
