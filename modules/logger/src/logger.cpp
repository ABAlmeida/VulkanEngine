#include "logger.hpp"

#include <iostream>

extern "C" VE_LOGGER_API void Log(const char* message)
{
	std::cout << "[Logger] " << message << std::endl;
}
