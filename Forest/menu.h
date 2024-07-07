#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <tuple>
#include <vector>
#include <map>
//#include <unordered_map>
//#include <unordered_set>
#include <algorithm>
#include <conio.h>
#include <ctype.h>
#include "support/Console.h"
#include "support/Internals.h"
using namespace CSL_Color;

static void pressAnyKey();

class Menu
{
#define Print std::cout <<
protected:
	static const std::string def_Header = "Please make a selection:";
	static const std::string def_Prompt = "Your command?";
	std::vector<std::tuple<char, std::string>> def_Option;
	static const int def_NumColumns = 1;
	static const int def_Spacing = 30;
	static const int def_MaxPerCol = 10;
	static const int def_StartRow = 20;
	static const int def_HeaderFromBottom = 14;
	static const int def_HeaderColumn = 5;
	static const int def_OptionColumn = 9;
	static const int def_PromptColumn = 5;


private:
	std::string _header;
	std::string _prompt;
	std::vector<std::tuple<char, std::string>> _options;

	int _numColumns;
	int _startRow;
	int _startCol;
	int _spacing;
	int _curOption;
	std::vector<int> _colBreaks;

	static int _headerFromBottom;
	static int _headerCol;
	static int _optionCol;
	static int _promptCol;
	static COORD _screenSize;
	static std::map<std::string, Menu> _allMenus;

	void setDefaults();

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
