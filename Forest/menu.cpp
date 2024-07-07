#pragma once
#include "menu.h"

int Menu::_headerFromBottom = Menu::def_HeaderFromBottom;
int Menu::_headerCol = Menu::def_HeaderColumn;
int Menu::_optionCol = Menu::def_OptionColumn;
int Menu::_promptCol = Menu::def_PromptColumn;
COORD Menu::_screenSize = { 120, 30 };
std::map<std::string, Menu> Menu::_allMenus;

static void pressAnyKey()
{
	Print CSL_Cursor::CUR_HIDE;
	std::string message = "Press any key to continue...";
	COORD size = CSL_Console::CSL::getWindowSize();
	CSL_Cursor::Cursor::setPos(size.X - message.size() - 2, size.Y - 1);
	Print WHITE << message;
	IT::pressKey();
}

void Menu::setDefaults()
{
	_header = def_Header;
	_prompt = def_Prompt;
	_options = def_Option;

	_numColumns = def_numColumns;
	_startRow = def_StartRow;
	_startCol = def_StartCol;
	_spacing = def_Space;
	_curOption = 0;

	_colBreaks.push_back(_startCol);
	_colBreaks.push_back(_startCol + _spacing);

	//if (_options.size() > def_MaxPerCol) columns = 2;
	//if (columns == 2) 
	//{
	//	colBreaks.push_back(0);
	//	colBreaks.push_back(static_cast<int>(std::floor(options.size() / 2.0)));
	//}
}

