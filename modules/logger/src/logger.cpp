#include <iostream>

extern "C" __declspec(dllexport) void Log(const char* message) 
{
	std::cout << "[Logger] " << message << std::endl;
}
