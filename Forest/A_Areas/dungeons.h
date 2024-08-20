#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "../support/Console.h"
//#include "menu.h"
//#include "creature.h"
#include <unordered_map>
#include "support/Internals.h"
#include "support/Console.h"
#include "support/Locals.h"
#include "Menu.h"
#include "Creatures.h"
#include "Items.h"

class Forest 
{
private:
	static void generateClear();
	static void generateLevel1();
	static void generateLevel2();
	static void generateLevel3();
	static void generateLevel4();
	static void generateLevel5();

public:
	static std::unordered_map<std::string, Menu> menus;
	static std::unordered_map<std::string, Creatures::Beast> beasts;

	static void init();
	static void generate();
	static void mainMenu();

	static void encounterMenu();
	static void battleMenu();
};

