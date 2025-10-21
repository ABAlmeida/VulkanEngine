#include "window.hpp"

#include <iostream>
#if VE_PLATFORM_WINDOWS
#include <windows.h>
#endif

#if VE_PLATFORM_WINDOWS
static HWND g_hWnd = nullptr;
static HINSTANCE g_hInstance = nullptr;
static const char CLASS_NAME[] = { "VulkanEngineWindowClass" };

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg) 
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif

extern "C" VE_WINDOW_API bool CreateEngineWindow(const char* title, int width, int height)
{
#if VE_PLATFORM_WINDOWS
	g_hInstance = GetModuleHandle(nullptr);

	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = g_hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	g_hWnd = CreateWindowExA(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		"Vulkan Engine",               // Window text (use wide string)
		WS_OVERLAPPEDWINDOW,            // Window style
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		nullptr, nullptr, g_hInstance, nullptr
	);

	if (!g_hWnd) 
	{
		std::cerr << "[Window] Failed to create window." << std::endl;
		return false;
	}

	ShowWindow(g_hWnd, SW_SHOW);
	std::cout << "[Window] Window created successfully." << std::endl;
	return true;
#else
	return false;
#endif
}

extern "C" VE_WINDOW_API void PollWindowEvents()
{
#if VE_PLATFORM_WINDOWS
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#endif
}


extern "C" VE_WINDOW_API void DestroyEngineWindow()
{
#if VE_PLATFORM_WINDOWS
	if (g_hWnd) 
	{
		DestroyWindow(g_hWnd);
		g_hWnd = nullptr;
		std::cout << "[Window] Window destroyed." << std::endl;
	}
#endif
}
