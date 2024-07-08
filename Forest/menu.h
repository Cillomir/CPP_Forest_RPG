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
using namespace CSL_Console;
using namespace CSL_Cursor;

static void pressAnyKey();

class Menu
{
#define Print std::cout <<
protected:
	const std::string def_Header = "Please make a selection:";
	const std::string def_Prompt = "Your command? ";
	const std::vector<std::tuple<char, std::string>> def_Option;
	static const int def_NumColumns = 1;
	static const int def_OptionWidth = 30;
	static const int def_MaxOptionRows = 10;
	static const int def_StartRow = 20;
	static const int def_HeaderFromBottom = 14;
	static const int def_PromptFromBottom = 3;
	static const int def_HeaderColumn = 5;
	static const int def_OptionColumn = 9;
	static const int def_PromptColumn = 5;


private:
	std::string _header;
	std::string _prompt;
	std::vector<std::tuple<char, std::string>> _options;

	int _numColumns;
	int _startRow;
	int _optionWidth;
	int _selIndex;
	int _selColumn;
	std::vector<int> _colBreaks;
	std::vector<int> _optionPerCol;

	static int _headerFromBottom;
	static int _promptFromBottom;
	static int _headerCol;
	static int _optionCol;
	static int _promptCol;
	static COORD _screenSize;
	static std::map<std::string, Menu> _allMenus;

	void setDefaults();
	void calcOptionColumns();

public:
	Menu()
	{
		Menu::setDefaults();
	};
	Menu(std::vector<std::tuple<char, std::string>> vOptions)
	{
		Menu::setDefaults();
		_options = vOptions;
		calcOptionColumns();
	}
	Menu(std::string sHeader, std::vector<std::tuple<char, std::string>> vOptions)
	{
		Menu::setDefaults();
		_header = sHeader;
		_options = vOptions;
		calcOptionColumns();
	}
	Menu(std::vector<std::tuple<char, std::string>> vOptions, std::string sPrompt)
	{
		Menu::setDefaults();
		_prompt = sPrompt;
		_options = vOptions;
		calcOptionColumns();
	}
	Menu(std::string sHeader, std::vector<std::tuple<char, std::string>> vOptions, std::string sPrompt)
	{
		Menu::setDefaults();
		_header = sHeader;
		_prompt = sPrompt;
		_options = vOptions;
		calcOptionColumns();
	}

	std::string getHeader() { return _header; }
	void setHeader(std::string sHeader) { _header = sHeader; }

	std::string getPrompt() { return _prompt; }
	void setPrompt(std::string sPrompt) { _prompt = sPrompt; }

	void display();

	void arrUp();
	void arrDown();
	void arrLeft();
	void arrRight();
	char select();
};
