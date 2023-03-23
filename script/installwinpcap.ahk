; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode "Input"  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir A_ScriptDir  ; Ensures a consistent starting directory.
SetTitleMatchMode "RegEx"

Print(string) {
	fd := FileOpen("installwinpcap_debug.txt", "a")
	fd.Write(string)
	fd.Write("`r`n")
	fd.Close()
}

print("Running install...")
ProgramFilesX86 := A_ProgramFiles . (A_PtrSize=8 ? " (x86)" : "")

winpcapInstaller := A_Args[1]
Run(winpcapInstaller)

print("Waiting for setup window")
WinWait("WinPcap [\d\.]+ Setup", , 30)

Loop 3
{
	print("SetupFoward")
	SetupForward()
}

print("Waiting for installation to finish")
WinWait("WinPcap [\d\.]+ Setup", "has been installed", 30)
If (WinExist)
{
	BlockInput True
	Sleep 250
	WinActivate
	Send "{Enter}"
	BlockInput False
}

print("Install finished")

ExitApp

SetupForward() {
	If (WinExist)
	{
		BlockInput True
		Sleep 250
		WinActivate
		Send "{Enter}"
		BlockInput False
	}
}
return
