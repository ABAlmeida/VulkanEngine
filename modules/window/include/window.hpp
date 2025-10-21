#pragma once

#include "platform.hpp"

#if defined(Window_EXPORTS)
#define VE_WINDOW_API VE_EXPORT
#else
#define VE_WINDOW_API VE_IMPORT
#endif

extern "C" VE_WINDOW_API bool CreateEngineWindow(const char* title, int width, int height);
extern "C" VE_WINDOW_API void PollWindowEvents();
extern "C" VE_WINDOW_API void DestroyEngineWindow();
