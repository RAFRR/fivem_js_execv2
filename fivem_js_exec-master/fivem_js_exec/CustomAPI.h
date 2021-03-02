#pragma once
#include <Windows.h>
#include <stdio.h>
#include <cstdint>
#include <functional>

namespace CustomAPI {
	extern DWORD64 WINAPI GetModuleA(_In_opt_ LPCSTR lpModuleName);
	extern DWORD64 WINAPI GetModuleBySize(_In_opt_ ULONG sizeStart, _In_opt_ ULONG sizeEnd);
	extern FARPROC WINAPI GetExportAddress(_In_ HMODULE hModule, _In_ LPCSTR lpProcName, _In_ BOOLEAN MappedAsImage);
}