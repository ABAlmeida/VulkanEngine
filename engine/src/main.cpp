#include <iostream>
#include "core/engine.hpp"
#include "logger.hpp"
#include "window.hpp"
#include "renderer.hpp"

int main() 
{
	Log("[Engine] Vulkan Engine initializing...");

	if (!CreateEngineWindow("Vulkan Engine", 800, 600))
	{
		Log("[Engine] Failed to create window!");
		return -1;
	}

	InitRenderer();

	Log("[Engine] Entering main loop...");
	for (int i = 0; i < 3; ++i) {
		PollWindowEvents();
		RenderFrame();
	}

	ShutdownRenderer();
	DestroyEngineWindow();
	Log("[Engine] Shutdown complete.");
	return 0;
}
