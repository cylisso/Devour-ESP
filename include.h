#pragma once
#include <windows.h>
#include <d3d11.h>
#include <string>

#pragma comment(lib, "d3d11.lib")

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

#include "minhook/MinHook.h"

#include "il2cpp-init.h"
#include "draw.h"
#include "structs.h"
#include "funcs-identf.h"
#include "il2cpp-helper.h"
#include "funcs.h"
#include "present.h"