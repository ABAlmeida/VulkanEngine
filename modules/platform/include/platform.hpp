#pragma once

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
#define VE_PLATFORM_WINDOWS 1
#else
#define VE_PLATFORM_WINDOWS 0
#endif

#if defined(__linux__)
#define VE_PLATFORM_LINUX 1
#else
#define VE_PLATFORM_LINUX 0
#endif

#if defined(__APPLE__)
#define VE_PLATFORM_MAC 1
#else
#define VE_PLATFORM_MAC 0
#endif

// Compiler detection
#if defined(_MSC_VER)
#define VE_COMPILER_MSVC 1
#else
#define VE_COMPILER_MSVC 0
#endif

#if defined(__clang__)
#define VE_COMPILER_CLANG 1
#else
#define VE_COMPILER_CLANG 0
#endif

#if defined(__GNUC__) && !defined(__clang__)
#define VE_COMPILER_GCC 1
#else
#define VE_COMPILER_GCC 0
#endif

// DLL export macros
#if VE_PLATFORM_WINDOWS
#define VE_EXPORT __declspec(dllexport)
#define VE_IMPORT __declspec(dllimport)
#else
#define VE_EXPORT __attribute__((visibility("default")))
#define VE_IMPORT
#endif

#if defined(Platform_EXPORTS)
#define VE_PLATFORM_API VE_EXPORT
#else
#define VE_PLATFORM_API VE_IMPORT
#endif