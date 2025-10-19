#include <iostream>

extern "C" __declspec(dllexport) void InitRenderer() 
{
	std::cout << "[Renderer] Vulkan renderer initialized." << std::endl;
}

extern "C" __declspec(dllexport) void RenderFrame() 
{
	std::cout << "[Renderer] Rendering frame..." << std::endl;
}

extern "C" __declspec(dllexport) void ShutdownRenderer() 
{
	std::cout << "[Renderer] Vulkan renderer shutdown." << std::endl;
}
