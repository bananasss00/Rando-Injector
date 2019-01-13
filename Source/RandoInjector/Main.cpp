#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#define walisson std::cout << "\nXing code desliga sexta-feira !!\n"

// And you need:
// 1. Modifique todos os bytes(0x00, 0x01, 0x03....)
#define JUNKS \
__asm _emit 0x00 \
__asm _emit 0x01 \
__asm _emit 0x03 \
__asm _emit 0x04 \
__asm _emit 0x05 \
__asm _emit 0x06 \
__asm _emit 0x07 \
__asm _emit 0x08 \


// Não mude isso!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

char dll[30];
char processo[30];

/////////////////////////////////////////////////////////////////////////////////////
//                                 INJECTOR CODE                                   //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	std::cout << "\n Injectado com sucesso!!\n";
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
system("PAUSE");
}

int main()
{
	SetConsoleTitle("Injector Code Building");
	std::cout << " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ " << std::endl;
	std::cout << "//  ######   #######  ########  ########    #### ##    ##       ##  ######  ########  #######  ########    // " << std::endl;
	std::cout << "// ##    ## ##     ## ##     ## ##           ##  ###   ##       ## ##    ##    ##    ##     ## ##     ##   // " << std::endl;
	std::cout << "// ##       ##     ## ##     ## ##           ##  ####  ##       ## ##          ##    ##     ## ##     ##   // " << std::endl;
	std::cout << "// ##       ##     ## ##     ## ######       ##  ## ## ##       ## ##          ##    ##     ## ########    // " << std::endl;
	std::cout << "// ##       ##     ## ##     ## ##           ##  ##  #### ##    ## ##          ##    ##     ## ##   ##     // " << std::endl;
	std::cout << "// ##    ## ##     ## ##     ## ##           ##  ##   ### ##    ## ##    ##    ##    ##     ## ##    ##    // " << std::endl;
	std::cout << "// ######   #######  ########  ########    #### ##    ##  ######   ######     ##     #######  ##     ##    // " << std::endl;
	std::cout << " ///////////////////////////////////////////////////////////////////////////////////////////////////////////"<< std::endl;
	walisson;
	

	std::cout << "\nDigite o nome da dll: \n";
	std::cin >> dll;
	std::cout << "Digite o nome do processo: \n";
	std::cin >> processo;

	_JUNK_BLOCK(jmp_label11)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label12)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label13)
	GetFullPathName(dll, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label4)
	dwProcess = Process(processo);
	
	_JUNK_BLOCK(jmp_label15)
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)

	return 0;
	
	_JUNK_BLOCK(jmp_label21)
}
