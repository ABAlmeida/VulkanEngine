#pragma once

extern "C" __declspec(dllimport) void InitRenderer();
extern "C" __declspec(dllimport) void RenderFrame();
extern "C" __declspec(dllimport) void ShutdownRenderer();
