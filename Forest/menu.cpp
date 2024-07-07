#pragma once
#include "menu.h"

static void pressAnyKey()
{
	Print CSL_Cursor::CUR_HIDE;
	std::string message = "Press any key to continue...";
	COORD size = CSL_Console::CSL::getWindowSize();
	CSL_Cursor::Cursor::setPos(size.X - message.size() - 2, size.Y - 1);
	Print WHITE << message;
	IT::pressKey();
}
