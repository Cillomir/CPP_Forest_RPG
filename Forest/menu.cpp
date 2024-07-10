#pragma once
#include "menu.h"

int Menu::_headerFromBottom = Menu::def_HeaderFromBottom;
int Menu::_promptFromBottom = Menu::def_PromptFromBottom;
int Menu::_headerCol = Menu::def_HeaderColumn;
int Menu::_optionCol = Menu::def_OptionColumn;
int Menu::_promptCol = Menu::def_PromptColumn;
COORD Menu::_screenSize = { 120, 30 };
std::map<std::string, Menu> Menu::_allMenus;

void Menu::setDefaults()
{
	_header = Menu::def_Header;
	_prompt = Menu::def_Prompt;
	_options = Menu::def_Option;

	_numColumns = Menu::def_NumColumns;
	_startRow = Menu::_screenSize.Y - Menu::_headerFromBottom;
	_optionWidth = Menu::def_OptionWidth;
	_selIndex = 0;
	_selColumn = 0;
	_colBreaks.push_back(_optionCol);
	_optionPerCol.push_back(Menu::def_MaxOptionRows);
}

void Menu::calcOptionColumns()
{
	_numColumns = def_NumColumns;
	if (_options.size() > Menu::def_MaxOptionRows)
	{
		_numColumns = (int)std::ceill((int)_options.size() / Menu::def_MaxOptionRows);
	}
	_colBreaks.clear();
	_colBreaks.push_back(_optionCol);
	for (int i = 1; i < _numColumns; ++i)
	{
		_colBreaks.push_back(_optionCol + (_optionWidth * i));
	}
	_optionPerCol.clear();
	if (_numColumns = 1)
		_optionPerCol.push_back((int)_options.size());
	else
	{
		for (int i = 1; i < _numColumns; ++i)
		{
			int c = (int)std::ceill((int)_options.size() / _numColumns);
			if (c > 0)
				_optionPerCol.push_back(c);
		}
	}
}

void Menu::display()
{
	CSL::clear();
	COORD size = CSL::getWindowSize();
	Menu::_screenSize = size;
	Cursor::setPos(_headerCol, size.Y - _headerFromBottom);
	Print WHITE << _header << std::endl;
	int idx = 0;
	for (std::tuple<char, std::string> tup : _options)
	{
		Cursor::setHor(_optionCol);
		if (idx == _selIndex) 
			Print B_YELLOW << BOLD;
		Print BLUE << "[";
		Print CYAN << std::get<0>(tup);
		Print BLUE << "]";
		Print BLUE_BR << std::get<1>(tup) << SGR_RESET << std::endl;
		idx++;
	}
	Cursor::setPos(_promptCol, size.Y - _promptFromBottom);
	Print WHITE << _prompt;
}

void Menu::arrUp()
{
	if (_selIndex <= _options.size() - 1) {
		_selIndex--;
	}
	else {
		_selIndex = (int)_options.size() - 1;
	}
}
void Menu::arrDown()
{
	if (_selIndex >= _options.size()) {
		_selIndex = 0;
	}
	else {
		_selIndex++;
	}
}
void Menu::arrLeft()
{
	if (_numColumns > 1)
	{
		if (_selColumn - 1 < 0)
		{
			if (_selIndex > _optionPerCol[_numColumns])
				_selIndex = ((int)_options.size() - 1);
			else
			{
				int r = _optionPerCol[_selColumn] - _selIndex;
			}
			_selColumn = _numColumns - 1;
		}
		else
		{
			_selIndex -= _optionPerCol[_selColumn];
			_selColumn -= 1;
		}
	}
}
void Menu::arrRight()
{
	if (_numColumns > 1)
	{
		if (_selColumn + 1 >= _numColumns)
		{
			if (_selIndex > _optionPerCol[_numColumns])
				_selIndex = ((int)_options.size() - 1);
			else
			{
				int r = _optionPerCol[_selColumn] - _selIndex;
			}
			_selColumn = _numColumns - 1;
		}
		else
		{
			_selIndex = 1;
			_selColumn = 1;
		}
	}
}
char Menu::select()
{
	unsigned char cmd;
	do
	{
		cmd = IT::getCommand();
		if (cmd == CSL_Key::KEY_ARR_UP + 128)
		{
			arrUp(); 
			cmd = ' ';
		}
		if (cmd == CSL_Key::KEY_ARR_DOWN + 128)
		{
			arrDown(); 
			cmd = ' ';
		}
		if (cmd == CSL_Key::KEY_ARR_LEFT + 128)
		{
			arrLeft(); 
			cmd = ' ';
		}
		if (cmd == CSL_Key::KEY_ARR_RIGHT + 128)
		{
			arrRight(); 
			cmd = ' ';
		}
		if (cmd == CSL_Key::KEY_RETURN + 128)
		{
			cmd = std::get<0>(_options[_selIndex]);
		}
	} while (cmd == ' ' && cmd != CSL_Key::KEY_ESC);
	return toupper(cmd);
}