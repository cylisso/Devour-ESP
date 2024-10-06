#pragma once
#include "include.h"

namespace dwDraw
{
	bool init = false;
	HWND window = NULL;
	WNDPROC oWndProc;
	ID3D11Device* pDevice = NULL;
	ID3D11DeviceContext* pContext = NULL;
	ID3D11RenderTargetView* mainRenderTargetView;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(dwDraw::oWndProc, hWnd, uMsg, wParam, lParam);
}

void MainLogix();

HRESULT(*oPresent) (IDXGISwapChain*, UINT, UINT);
HRESULT hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!dwDraw::init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&dwDraw::pDevice)))
		{
			dwDraw::pDevice->GetImmediateContext(&dwDraw::pContext);

			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			dwDraw::window = sd.OutputWindow;

			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			dwDraw::pDevice->CreateRenderTargetView(pBackBuffer, NULL, &dwDraw::mainRenderTargetView);
			pBackBuffer->Release();

			dwDraw::oWndProc = (WNDPROC)SetWindowLongPtrA(dwDraw::window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			dwDraw::init = true;
		}
		else
		{
			return oPresent(pSwapChain, SyncInterval, Flags);
		}

		{
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.IniFilename = NULL;
			io.LogFilename = NULL;
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
			ImGui::StyleColorsDark();
			ImGui_ImplWin32_Init(dwDraw::window);
			ImGui_ImplDX11_Init(dwDraw::pDevice, dwDraw::pContext);
		}
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	MainLogix();

	ImGui::Render();
	dwDraw::pContext->OMSetRenderTargets(1, &dwDraw::mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(pSwapChain, SyncInterval, Flags);
}