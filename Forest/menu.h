#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <tuple>
#include <vector>
//#include <map>
//#include <unordered_map>
//#include <unordered_set>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
#include "support/Console.h"
#include "support/Internals.h"
using namespace CSL_Color;

#pragma region Key Definitions
#define KEY_CR			'\x0D'
#define KEY_LF			'\x0A'
#define KEY_BKSP		'\x08'
#define KEY_TAB			'\x09'
#define KEY_ESC			'\x1B'
#define KEY_SHFT_TAB	'\x0F'
#define KEY_BELL		'\x07'
#define KEY_F1			'\x3B'
#define KEY_F2			'\x3C'
#define KEY_F3			'\x3D'
#define KEY_F4			'\x3E'
#define KEY_F5			'\x3F'
#define KEY_F6			'\x40'
#define KEY_F7			'\x41'
#define KEY_F8			'\x42'
#define KEY_F9			'\x43'
#define KEY_F10			'\x44'
#define KEY_F11			'\x57'
#define KEY_F12			'\x58'
#define KEY_HOME		'\x47'
#define KEY_END			'\x4F'
#define KEY_PG_UP		'\x49'
#define KEY_PG_DOWN		'\x51'
#define KEY_ARR_UP		'\x48'
#define KEY_ARR_DOWN	'\x50'
#define KEY_ARR_LEFT	'\x4B'
#define KEY_ARR_RIGHT	'\x4D'
#define KEY_CENTER		'\x4C'
#define KEY_INS			'\x52'
#define KEY_DEL			'\x53'
#pragma endregion

static void pressAnyKey();

class Menu
{
#define Print std::cout <<
protected:
	std::string defHeader = "Please make a selection:";
	std::string defPrompt = "Your command?";
	std::vector<std::tuple<char, std::string>> defOption;
	int defCol = 1;
	int defSpace = 30;
	int defMaxPerCol = 10;
	int defStartRow = 20;
	int defStartCol = 12;

private:
	int columns;
	int startRow;
	int startCol;
	int spacing;
	int curOption;
	std::vector<int> colBreaks;

	std::string header;
	std::string prompt;
	std::vector<std::tuple<char, std::string>> options;

	void setDefaults()
	{
		header = defHeader;
		prompt = defPrompt;
		options = defOption;

		columns = Menu::defCol;
		if (options.size() > defMaxPerCol) columns = 2;
		//if (columns == 2) 
		//{
		//	colBreaks.push_back(0);
		//	colBreaks.push_back(static_cast<int>(std::floor(options.size() / 2.0)));
		//}
		startRow = Menu::defStartRow;
		startCol = Menu::defStartCol;
		spacing = Menu::defSpace;
		curOption = 0;
	}

public:
	Menu()
	{
		Menu::setDefaults();
	};
	Menu(std::vector<std::tuple<char, std::string>> vOptions)
	{
		Menu::setDefaults();
		options = vOptions;
	}
	Menu(std::string sHeader, std::vector<std::tuple<char, std::string>> vOptions)
	{
		Menu::setDefaults();
		header = sHeader;
		options = vOptions;
	}
	Menu(std::vector<std::tuple<char, std::string>> vOptions, std::string sPrompt)
	{
		Menu::setDefaults();
		prompt = sPrompt;
		options = vOptions;
	}
	Menu(std::string sHeader, std::vector<std::tuple<char, std::string>> vOptions, std::string sPrompt)
	{
		Menu::setDefaults();
		header = sHeader;
		prompt = sPrompt;
		options = vOptions;
	}
	std::string getHeader() { return header; }
	void setHeader(std::string sHeader) { header = sHeader; }
	std::string getPrompt() { return prompt; }
	void setPrompt(std::string sPrompt) { prompt = sPrompt; }

	void display()
	{
		CSL_Console::CSL::clear();
		Print WHITE << header << std::endl;
		for (std::tuple<char, std::string> tup : options)
		{
			Print BLUE << "[";
			Print CYAN << std::get<0>(tup);
			Print BLUE << "]";
			Print BLUE_BR << std::get<1>(tup) << std::endl;
		}
		Print WHITE << prompt << " ";
	}

	void arrUp()
	{
		if (curOption < 0) {
			curOption--;
		}
		else {
			curOption = (int)options.size() - 1;
		}
	}
	void arrDown()
	{
		if (curOption == options.size() - 1) {
			curOption = 0;
		}
		else {
			curOption++;
		}
	}
	//void arrLeft()
	//{
	//	if (columns > 1 && curOption >= colBreaks[1]) curOption += colBreaks[1];
	//	if (columns > 1 && curOption < colBreaks[1]) curOption -= colBreaks[1];
	//}
	//void arrRight()
	//{
	//	if (columns > 1 && curOption < colBreaks[1]) curOption += colBreaks[1];
	//	if (columns > 1 && curOption > colBreaks[1]) curOption -= colBreaks[1];
	//}
	char select()
	{
		//std::tuple <char,std::string> tup = options[curOption];
		//return std::get<0>(tup);

		return std::get<0>(options[curOption]);
	}
};
