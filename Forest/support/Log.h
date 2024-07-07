#pragma once
#include <iostream>
#ifndef LOG_H
#define LOG_H

class Log
{
private:
	int _logLevel;

public:
	enum Level 
	{
		trace, info, warning, error
	};
	void SetLevel(Level level);
	void Error(const char* message);
	void Warning(const char* message);
	void Info(const char* message);
};
#endif

