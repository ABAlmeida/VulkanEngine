#include "renderer.hpp"

#include <iostream>

extern "C" VE_RENDERER_API void InitRenderer()
{
	std::cout << "[Renderer] Vulkan renderer initialized." << std::endl;
}

extern "C" VE_RENDERER_API void RenderFrame()
{
	std::cout << "[Renderer] Rendering frame..." << std::endl;
}

extern "C" VE_RENDERER_API void ShutdownRenderer()
{
	std::cout << "[Renderer] Vulkan renderer shutdown." << std::endl;
}
