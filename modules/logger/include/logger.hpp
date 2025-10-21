#pragma once

#include "platform.hpp"

#if defined(Logger_EXPORTS)
#define VE_LOGGER_API VE_EXPORT
#else
#define VE_LOGGER_API VE_IMPORT
#endif

extern "C" VE_LOGGER_API void Log(const char* message);
