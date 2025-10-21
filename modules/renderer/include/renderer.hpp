#pragma once

#include "platform.hpp"

#if defined(Renderer_EXPORTS)
#define VE_RENDERER_API VE_EXPORT
#else
#define VE_RENDERER_API VE_IMPORT
#endif

extern "C" VE_RENDERER_API void InitRenderer();
extern "C" VE_RENDERER_API void RenderFrame();
extern "C" VE_RENDERER_API void ShutdownRenderer();
