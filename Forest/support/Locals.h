#pragma once
#include <iostream>
#include <string>
#include "support/Console.h"
#include "support/Internals.h"
using namespace CSL_Color;

#ifndef LOCALS_H
#define INTERNALS_H

#define Print std::cout <<

static void pressAnyKey()
{
	Print CSL_Cursor::CUR_HIDE;
	std::string message = "Press any key to continue...";
	COORD size = CSL_Console::CSL::getWindowSize();
	CSL_Cursor::Cursor::setPos(size.X - (int)message.size() - 2, size.Y - 1);
	Print WHITE << message;
	IT::pressKey();
}
#endif