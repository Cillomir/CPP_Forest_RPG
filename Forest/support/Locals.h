#pragma once
#include <iostream>
#include <string>
#include <vector>
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

static std::vector<std::string> splitText(std::string text, char delim = ' ')
{
	std::stringstream str(text);
	std::string s;
	std::vector<std::string> v;
	while (std::getline(str, s, delim))
	{
		v.push_back(s);
	}
	return v;
}


static void textBoxBorder(int x, int y, int width, int height)
{
	CSL_Line::Line::lineDrawingOn();
	CSL_Cursor::Cursor::setPos(x, y);
	CSL_Line::Line::lineDraw(CSL_Line::Line::TL);
	for (int i = 1; i < width - 1; ++i)
		CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
	CSL_Line::Line::lineDraw(CSL_Line::Line::TR);
	for (int i = 1; i < height; ++i)
	{
		CSL_Cursor::Cursor::setPos(x, y + i);
		CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
		CSL_Cursor::Cursor::setHor(x + width - 1);
		CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
	}
	CSL_Cursor::Cursor::setPos(x, y + height - 1);
	CSL_Line::Line::lineDraw(CSL_Line::Line::BL);
	for (int i = 1; i < width - 1; ++i)
		CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
	CSL_Line::Line::lineDraw(CSL_Line::Line::BR);
	CSL_Line::Line::lineDrawingOff();
}
static void textBoxBorder(COORD pos, int width, int height)
{
	textBoxBorder(pos.X, pos.Y, width, height);
}

static void tbNewLine(COORD pos, int &width, int &height)
{
	width = 0;
	height++;
	CSL_Cursor::Cursor::setPos(pos.X, pos.Y + height);
}
static void textBox(COORD pos, int maxWidth, int maxHeight, std::string text, bool border = false)
{
	std::vector<std::string> words = splitText(text);
	if (border) textBoxBorder(pos.X - 1, pos.Y - 1, maxWidth + 1, maxHeight + 1);
	CSL_Cursor::Cursor::setPos(pos.X, pos.Y);
	int curWidth = 0;
	int curHeight = 0;
	for (std::string w : words)
	{
		if ((int)w.length() + curWidth < maxWidth)
		{
			curWidth += (int)w.length();
			Print w;
			if (curWidth + 1 < maxWidth)
			{
				curWidth++;
				Print " ";
			}
			else tbNewLine(pos, curWidth, curHeight);
		}
		else
		{
			if (curHeight >= maxHeight)
				break;
			else
			{
				if ((int)w.length() < (int)std::floor(maxWidth / 4))
				{
					curHeight++;
					CSL_Cursor::Cursor::setPos(pos.X, pos.Y + curHeight);
					curWidth = (int)w.length();
					Print w;
					if (curWidth + 1 < maxWidth)
					{
						curWidth++;
						Print " ";
					}
					else tbNewLine(pos, curWidth, curHeight);
				}
				else
				{
					int max = maxWidth - curWidth - 2;
					if (max < (int)std::ceil(maxWidth / 10))
					for (int i = 0; i < max; ++i)
						Print w[i];
					Print "-";
					tbNewLine(pos, curWidth, curHeight);
					for (int i = max; i < w.length(); ++i)
						Print w[i];
				}
			}
		}
	}
};

#endif