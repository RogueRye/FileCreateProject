// For Windows XP or 7
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>

int main2()
{
	// The STARTUPINFO structure is used with the CreateProcess function to specify 
	// main window properties if a new window is created for the new process.
	STARTUPINFO si;
	// Contains information about a newly created process and its primary thread.
	PROCESS_INFORMATION pi;
	// 
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// Start the child process. If not OK...
	if (!CreateProcess(TEXT("C:\\Windows\\notepad.exe"), // module name.
		NULL,    // Command line.
		NULL,    // Process handle not inheritable.
		NULL,    // Thread handle not inheritable.
		FALSE,   // Set handle inheritance to FALSE.
		0,       // No creation flags.
		NULL,    // Use parent's environment block.
		NULL,    // Use parent's starting directory.
		&si,     // Pointer to STARTUPINFO structure.
		&pi)     // Pointer to PROCESS_INFORMATION structure.
		)

		// Then, give some prompt...
		printf("\nSorry! CreateProcess() failed.\n\n");
	//else, give some prompt...
	else
	{
		printf("\nWell, CreateProcess() looks OK.\n");
		printf("exit after 5000 ms...\n\n");
	}

	// Wait until child process exits after 5000 ms.
	WaitForSingleObject(pi.hProcess, 5000);
	printf("\n");
	// Close process and thread handles.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}