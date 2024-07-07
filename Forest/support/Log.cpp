#include "Log.h"

void Log::SetLevel(Level level)
{
	_logLevel = level;
}

void Log::Error(const char* message)
{
	if (_logLevel >= Level::warning)
		std::cout << "[ERROR] " << message << std::endl;
}

void Log::Warning(const char* message)
{
	if (_logLevel >= Level::warning)
		std::cout << "[WARNING] " << message << std::endl;
}

void Log::Info(const char* message)
{
	if (_logLevel >= Level::info)
		std::cout << "[Info] " << message << std::endl;
}