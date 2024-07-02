#pragma once
#include "menu.h"

static void pressAnyKey()
{
	std::cout << WHITE << "Press any key to continue...";
	std::cin.ignore();
}

static void testKey(char escape)
{
	char key;
	do
	{
		key = _getch();
		if (key != 0)
		{
			std::cout << key;
			switch (key)
			{
				case KEY_ARR_LEFT:
					std::cout << "Left Arrow";
					break;
				case KEY_ARR_RIGHT:
					std::cout << "Right Arrow";
					break;
				case KEY_ARR_UP:
					std::cout << "Up Arrow";
					break;
				case KEY_ARR_DOWN:
					std::cout << "Down Arrow";
					break;
				case KEY_CR:
					std::cout << "Enter" << KEY_LF << KEY_CR;
					break;
				case KEY_ESC:
					std::cout << "Escape";
					//key = escape;
					break;
			}
			continue;
		}
		key = _getch();
		std::cout << KEY_LF << key << KEY_LF;
		switch (key)
		{
		case KEY_ARR_LEFT: 
			std::cout << "Left Arrow";
			break;
		case KEY_ARR_RIGHT:
			std::cout << "Right Arrow";
			break;
		case KEY_ARR_UP:
			std::cout << "Up Arrow";
			break;
		case KEY_ARR_DOWN:
			std::cout << "Down Arrow";
			break;
		case KEY_CR:
			std::cout << "Enter" << KEY_LF << KEY_CR;
			break;
		case KEY_ESC:
			std::cout << "Escape";
			//key = escape;
			break;
		}
	} while (key != escape);
}