#pragma once

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <iostream>
#include "functions.h"

__declspec(dllexport) void LogMessage(const char *message);

extern "C" __declspec(dllexport) void HookProcedure();

typedef NTSTATUS (WINAPI *pNtTerminateProcess)(

        IN    NTSTATUS ExitStatus

);