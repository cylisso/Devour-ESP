#include "include.h"

int vBindPresent(void** _original, void* _function)
{
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.cbClsExtra = NULL;
	windowClass.cbWndExtra = NULL;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = NULL;
	windowClass.hCursor = NULL;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = L"H8fhJg";
	windowClass.hIconSm = NULL;

	RegisterClassEx(&windowClass);
	HWND window = CreateWindowExW(0L, windowClass.lpszClassName, L"Fj4314f", WS_OVERLAPPEDWINDOW,
		NULL, NULL, 100, 100, NULL, NULL, windowClass.hInstance, NULL);

	HMODULE libD3D11;
	if ((libD3D11 = GetModuleHandleW(L"d3d11.dll")) == NULL)
	{
		DestroyWindow(window);
		UnregisterClassW(windowClass.lpszClassName, windowClass.hInstance);
		return NULL;
	}

	void* d11func;
	if ((d11func = GetProcAddress(libD3D11, "D3D11CreateDeviceAndSwapChain")) == NULL)
	{
		DestroyWindow(window);
		UnregisterClassW(windowClass.lpszClassName, windowClass.hInstance);
		return NULL;
	}

	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0 };

	DXGI_RATIONAL refreshRate;
	refreshRate.Numerator = 60;
	refreshRate.Denominator = 1;

	DXGI_MODE_DESC bufferDesc;
	bufferDesc.Width = 100;
	bufferDesc.Height = 100;
	bufferDesc.RefreshRate = refreshRate;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	DXGI_SAMPLE_DESC sampleDesc;
	sampleDesc.Count = 1;
	sampleDesc.Quality = 0;

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc = sampleDesc;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = window;
	swapChainDesc.Windowed = 1;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	IDXGISwapChain* swapChain;
	ID3D11Device* device;
	ID3D11DeviceContext* context;

	HRESULT(*D3D11CreateDeviceAndSwapChainFunc)(
		IDXGIAdapter*,
		D3D_DRIVER_TYPE,
		HMODULE,
		UINT,
		const D3D_FEATURE_LEVEL*,
		UINT,
		UINT,
		const DXGI_SWAP_CHAIN_DESC*,
		IDXGISwapChain**,
		ID3D11Device**,
		D3D_FEATURE_LEVEL*,
		ID3D11DeviceContext**) = reinterpret_cast<decltype(D3D11CreateDeviceAndSwapChain)*>(d11func);

	if (D3D11CreateDeviceAndSwapChainFunc(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, featureLevels, 2, D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel, &context) < NULL) {
		DestroyWindow(window);
		UnregisterClassW(windowClass.lpszClassName, windowClass.hInstance);
		return NULL;
	}

	uint64_t* g_methodsTable = (uint64_t*)calloc(205, sizeof(uint64_t));
	memcpy(g_methodsTable, *(uint64_t**)swapChain, 18 * sizeof(uint64_t));
	memcpy(g_methodsTable + 18, *(uint64_t**)device, 43 * sizeof(uint64_t));
	memcpy(g_methodsTable + 18 + 43, *(uint64_t**)context, 144 * sizeof(uint64_t));

	swapChain->Release();
	context->Release();
	device->Release();

	DestroyWindow(window);
	UnregisterClassW(windowClass.lpszClassName, windowClass.hInstance);

	{
		if (!g_methodsTable[0])
			return FALSE;

		void* target = (void*)g_methodsTable[8];
		if (MH_CreateHook(target, _function, _original) != 0 || MH_EnableHook(target) != 0)
			return FALSE;
	}

	return TRUE;
}

bool init_functions()
{
	uintptr_t tmpAddr;

	if (!(tmpAddr = find_method("get_main", "Camera", "UnityEngine"))) return FALSE;
	oCamera__get_main = *reinterpret_cast<tCamera__get_main*>(tmpAddr);

	if (!(tmpAddr = find_method("get_transform", "GameObject", "UnityEngine"))) return FALSE;
	oGameObject__get_transform = *reinterpret_cast<tGameObject__get_transform*>(tmpAddr);

	if (!(tmpAddr = find_method("get_position", "Transform", "UnityEngine"))) return FALSE;
	oTransform__get_position = *reinterpret_cast<tTransform__get_position*>(tmpAddr);

	if (!(tmpAddr = find_method("WorldToScreenPoint", "Camera", "UnityEngine", 1, "UnityEngine.Vector3", 0))) return FALSE;
	oWorldToScreenPoint = *reinterpret_cast<tWorldToScreenPoint*>(tmpAddr);

	if (!(tmpAddr = find_method("FindObjectOfType", "Object", "UnityEngine", 1, "System.Type", 0))) return FALSE;
	oFindObjectOfType = *reinterpret_cast<tFindObjectOfType*>(tmpAddr);

	if (!(tmpAddr = find_method("FindGameObjectWithTag", "GameObject", "UnityEngine"))) return FALSE;
	oFindGameObjectWithTag = *reinterpret_cast<tFindGameObjectWithTag*>(tmpAddr);

	if (!(tmpAddr = find_method("IsEndingPlaying", "Survival"))) return FALSE;
	oSurvival_IsEndingPlaying = *reinterpret_cast<tSurvival_IsEndingPlaying*>(tmpAddr);

	if (!(tmpAddr = find_method("IsJumpScarePlaying", "Survival"))) return FALSE;
	oSurvival_IsJumpScarePlaying = *reinterpret_cast<tSurvival_IsEndingPlaying*>(tmpAddr);

	if (!(tmpAddr = find_method("StartingToPlayFailEnding", "Survival"))) return FALSE;
	oSurvival_StartingToPlayFailEnding = *reinterpret_cast<tSurvival_IsEndingPlaying*>(tmpAddr);

	return TRUE;
}

DWORD WINAPI MainThread(LPVOID lp)
{
	AllocConsole();
	freopen_s((_iobuf**)(__acrt_iob_func(0)), "conin$", "r", (_iobuf*)(__acrt_iob_func(0)));
	freopen_s((_iobuf**)(__acrt_iob_func(1)), "conout$", "w", (_iobuf*)(__acrt_iob_func(1)));

	cil2cpp_init();

	if (init_functions())
	{
		MH_Initialize();

		vBindPresent((void**)&oPresent, &hkPresent);

		MH_EnableHook(NULL);
	}

	while (!GetAsyncKeyState(VK_F5)) Sleep(500);
	FreeConsole();
	MH_DisableHook(NULL);
	MH_Uninitialize();
	SetWindowLongPtrW(dwDraw::window, GWLP_WNDPROC, (LONG_PTR)dwDraw::oWndProc);
	FreeLibraryAndExitThread((HMODULE)lp, NULL);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hModule, uint32_t dwReason, LPVOID)
{
	if (dwReason != DLL_PROCESS_ATTACH)
		return FALSE;

	DisableThreadLibraryCalls(hModule);
	CreateThread(nullptr, NULL, MainThread, hModule, NULL, nullptr);

	return TRUE;
}