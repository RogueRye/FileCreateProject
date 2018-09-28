#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

int main() {


	HANDLE hFile;
	char DataBuffer[] = "My example text testing the Win32 API WriteFile()";
	char filePath[] = "myFile.txt";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = false;
	


	hFile = CreateFileA((LPCSTR)filePath, //name of the write
		GENERIC_WRITE, //open for writing
		0, //do not share
		NULL, //default security
		CREATE_NEW, //Create a new file only
		FILE_ATTRIBUTE_NORMAL, // normal file
		NULL  // no attr. template
	);

	printf("Writing %d bytes to %s.\n", dwBytesToWrite, filePath);

	bErrorFlag = WriteFile(
		hFile,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{		
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
		}
		else
		{
			printf("Wrote %d bytes to %s successfully.\n", dwBytesWritten, filePath);
		}
	}

	CloseHandle(hFile);
}