#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

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
};