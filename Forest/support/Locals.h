#pragma once
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "support/Console.h"
#include "support/Internals.h"
using namespace CSL_Color;

#ifndef LOCALS_H
#define LOCALS_H

#define Print std::cout <<
#define RND_DIST std::uniform_int_distribution<std::mt19937::result_type>

static unsigned int timeSeed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
static std::mt19937 rng(timeSeed);
static RND_DIST dist2(1, 2);
static RND_DIST dist4(1, 4);
static RND_DIST dist6(1, 6);
static RND_DIST dist8(1, 8);
static RND_DIST dist10(1, 10);
static RND_DIST dist12(1, 12);
static RND_DIST dist14(1, 14);
static RND_DIST dist16(1, 16);
static RND_DIST dist18(1, 18);
static RND_DIST dist20(1, 20);
static RND_DIST dist25(1, 25);
static RND_DIST dist50(1, 50);
static RND_DIST dist100(1, 100);
static RND_DIST dist1000(1, 1000);

static void pressAnyKey()
{
	Print CSL_Cursor::CUR_HIDE;
	std::string message = "Press any key to continue...";
	COORD size = CSL_Console::CSL::getWindowSize();
	CSL_Cursor::Cursor::setPos(size.X - (int)message.size() - 2, size.Y - 1);
	Print WHITE << message;
	IT::pressKey();
}
class Dice
{
public:
	enum die
	{
		d0 = 0, d2 = 2, d4 = 4, d6 = 6, d8 = 8, d10 = 10, 
		d12 = 12, d14 = 14, d16 = 16, d18 = 18,
		d20 = 20, d25 = 25, d50 = 50, d100 = 100, d1000 = 1000
	};
public:
	static int Roll(Dice::die dice)
	{
		switch (dice)
		{
		case Dice::d2:
			return dist2(rng);
			break;
		case Dice::d4:
			return dist4(rng);
			break;
		case Dice::d6:
			return dist6(rng);
			break;
		case Dice::d8:
			return dist8(rng);
			break;
		case Dice::d10:
			return dist10(rng);
			break;
		case Dice::d12:
			return dist12(rng);
			break;
		case Dice::d14:
			return dist14(rng);
			break;
		case Dice::d16:
			return dist16(rng);
			break;
		case Dice::d18:
			return dist18(rng);
			break;
		case Dice::d20:
			return dist20(rng);
			break;
		case Dice::d50:
			return dist50(rng);
			break;
		case Dice::d100:
			return dist100(rng);
			break;
		case Dice::d1000:
			return dist1000(rng);
			break;
		default:
			return 0;
			break;
		}
	}
};
#endif