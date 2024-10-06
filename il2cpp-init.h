#pragma once
#include <windows.h>

#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API

inline void cil2cpp_init()
{
	HMODULE moduleHandle = GetModuleHandleW(L"GameAssembly.dll");
#define DO_API(r, n, p) n = (r (*) p)(GetProcAddress(moduleHandle, #n))
#include "il2cpp-api-functions.h"
#undef DO_API
}