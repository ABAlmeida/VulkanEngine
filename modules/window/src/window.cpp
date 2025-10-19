#include <windows.h>
#include <iostream>

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

extern "C" __declspec(dllexport) bool CreateEngineWindow(const char* title, int width, int height) 
{
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
}

extern "C" __declspec(dllexport) void PollWindowEvents() 
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


extern "C" __declspec(dllexport) void DestroyEngineWindow() {
	if (g_hWnd) 
	{
		DestroyWindow(g_hWnd);
		g_hWnd = nullptr;
		std::cout << "[Window] Window destroyed." << std::endl;
	}
}
