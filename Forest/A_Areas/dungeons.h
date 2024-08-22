#pragma once
#ifndef DUNGEONS_H
#define DUNGEONS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <windows.h>
#include "../support/Internals.h"
#include "../support/Console.h"
#include "../support/Locals.h"
#include "../Menu.h"
#include "../C_Classes/Creatures.h"
#include "../C_Classes/Items.h"

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
	static std::unordered_map<std::string, Menus::Menu> menus;
	static std::unordered_map<std::string, Creatures::Beast> beasts;

	static void init();
	static void generate();
	static void mainMenu();

	static void encounterMenu();
	static void battleMenu();
};

#endif
