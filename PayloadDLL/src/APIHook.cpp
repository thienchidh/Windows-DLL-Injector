#include "APIHook.h"

typedef BOOL(WINAPI *TerminateProcess_Func)(HANDLE, UINT);

TerminateProcess_Func originTerminateProcess = NULL;


BOOL WINAPI TerminateProcessHook(_In_ HANDLE hProcess, _In_ UINT uExitCode) {

    // originTerminateProcess(hProcess, uExitCode);

    MessageBoxA(NULL, "call TerminateProcessHook", "title", MB_ICONINFORMATION);
    return TRUE;
}

// use library Detour
void Hook::initFunction() {
#ifdef ENABLE_HOOK

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    originTerminateProcess = (TerminateProcess_Func) DetourFindFunction("kernel32.dll", "TerminateProcess");


    DetourTransactionCommit();

#endif
}


void Hook::addHook() {
#ifdef ENABLE_HOOK

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourAttach(&(PVOID &) originTerminateProcess, (PVOID) TerminateProcessHook);


    DetourTransactionCommit();

#endif

}

void Hook::removeHook() {
#ifdef ENABLE_HOOK

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourDetach(&(PVOID &) originTerminateProcess, (PVOID) TerminateProcessHook);

    DetourTransactionCommit();

#endif
}

