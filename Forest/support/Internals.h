#pragma once
#include <string>
#include <algorithm>
#include <conio.h>

#ifndef INTERNALS_H
#define INTERNALS_H
#define Print std::cout <<

namespace IT
{
	static std::string toUpper(std::string s)
	{
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) {return std::toupper(c); });
		return s;
	}
	static std::string toLower(std::string s)
	{
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) {return std::tolower(c); });
		return s;
	}
	static std::string toCapitalize(std::string s)
	{
		s = IT::toLower(s);
		s[0] = std::toupper(s[0]);
		return s;
	}
	static char getKey()
	{
		char key;
		key = _getch();
		if (key != 0) return std::toupper(key);
		key = _getch();
		return key;
	}
	static void pressKey()
	{
		char key;
		key = _getch();
		if (key != 0) return;
		key = _getch();
		return;
	}
};
#endif