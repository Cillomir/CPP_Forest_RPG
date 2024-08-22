#pragma once
#ifndef INTERNALS_H
#define INTERNALS_H

#include <string>
#include <algorithm>
#include <conio.h>
#include "Console.h"

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
	static char getCommand()
	{
		unsigned char key;
		key = _getch();
		if (key > 0)
		{
			return key;
		}
		key = _getch();
		return (key + 128);
	}
	static char getKey()
	{
		char key;
		key = _getch();
		if (key > 0 && key != ' ')
		{
			return key;
		}
		key = _getch();
		return key;
	}
	static void pressKey()
	{
		char key;
		key = _getch();
		if (key > 0) return;
		key = _getch();
		return;
	}
	//static void testKey()
	//{
	//	do 
	//	{
	//		char test;
	//		test = getKey();
	//		if (test == CSL_Key::KEY_RETURN)
	//			Print "Return\n";
	//		if (test == CSL_Key::KEY_ARR_LEFT)
	//			Print "Left\n";
	//		if (test == CSL_Key::KEY_ARR_RIGHT)
	//			Print "Right\n";
	//		if (test == CSL_Key::KEY_ARR_UP)
	//			Print "Up\n";
	//		if (test == CSL_Key::KEY_ARR_DOWN)
	//			Print "Down\n";
	//		if (test == CSL_Key::KEY_F1)
	//			Print "F1\n";
	//		if (test == CSL_Key::KEY_F2)
	//			Print "F2\n";
	//		if (test == CSL_Key::KEY_F3)
	//			Print "F3\n";
	//		if (test == CSL_Key::KEY_F4)
	//			Print "F4\n";
	//		if (test == CSL_Key::KEY_ESC)
	//			Print "Escape\n";
	//	} while (1);
	//}

};
#endif