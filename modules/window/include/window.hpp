#pragma once

extern "C" __declspec(dllimport) bool CreateEngineWindow(const char* title, int width, int height);
extern "C" __declspec(dllimport) void PollWindowEvents();
extern "C" __declspec(dllimport) void DestroyEngineWindow();
