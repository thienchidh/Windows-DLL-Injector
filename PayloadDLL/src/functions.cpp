#include "functions.h"


void Functions::eat1ToWin() {
    auto hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, GetCurrentProcessId());

    // Pokemon.exe+A8866 - 66 C7 05 78604B00 9000 - mov word ptr [Pokemon.exe+B6078],0090 { (144),144 }
    int addressToPatch = 0X004A8866; // byte array len 9 (mov word ptr [Pokemon.exe+B6078],0090)
    int addressRemain = addressToPatch + 7; // default value 90, change to 2

    unsigned char cNumberConst = 2;
    WriteProcessMemory(hProcess, (int *) addressRemain, &cNumberConst, 1, NULL);

    CloseHandle(hProcess);

    MessageBoxA(NULL, "an 1 con, win", "title", MB_ICONINFORMATION);
}

