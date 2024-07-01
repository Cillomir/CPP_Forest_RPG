/* 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Program Name: Forest.cpp
Author: Joel Leckie
Date: 2024-06-17
Description:	This file contains the 'main' function. 
				Program execution begins and ends there.

Versions:
    0.1.0 - 2024-06-20: Initial program creation and design

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
To-Do:
    Fix classes not showing in other modules (missing prototypes?)
    Add Quest [B]oard
        Add pertinant quests (e.g. Armor shop requests 3 deer hide: kill 3 deer)
    Add [T]reasury
    Add colors to text
    Add weapon stats (e.g. hit roll, damage roll, damage types)
    Add armor stats (e.g. AC for bludge, pierce, slash, magic resist)
    Add monsters (lvl 0 - 10 + boss) current level or previous level can be encountered)
	Add non-monster encounters 
    Make shop calculations a common static procedure (e.g. buy item, sell item, list items)
	Add [G]uild Hall (to turn in quests, earn gold, gain levels, get training, etc.)
	Add battle maneuvers (per class, e.g. warrior, rogue, ranger) that use stamina
		(e.g. vital shot, power attack, trip, kick, etc.)
	Add combat spells (per class, e.g. warrior, rogue, ranger) that use spirit/mana
		(e.g. second wind, boost, protection, etc.)
	Add spellcasting (per class, e.g. mage, cleric) that use spirit/mana
		(e.g. dart, missile, healing, protection, weakening, etc.)
    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <windows.h>
#include "internals.h"
#include "console.cpp"
#include "menu.cpp"
#include "creature.cpp"
#include "shops.cpp"
//#include "dForest.cpp"
//#include "internals.h"

Console screen = Console();
Menu townMenu1 = Menu();

Player introduction() 
{
	//testKey(KEY_ARR_UP);
	screen.clear();
	screen.cursorReset();
	std::string playerName;
    std::cout << "Please enter your name: ";
    std::cin >> playerName;
	playerName = IT::toCapitalize(playerName);
	std::cout << "Welcome, " << playerName << "\n";
    Player player = Player(playerName);
	//player.viewStats(screen);
	return player;
}

static void townInit()
{
	std::string header = "Welcome to the town!";
	std::string prompt = "Select a destination:";
	std::vector<std::tuple<char, std::string>> options;
	//armorShopInit();
	options.push_back(std::make_tuple('A', "rmor Shop"));
	//weaponShopInit();
	options.push_back(std::make_tuple('W', "eapon Shop"));
	//healersHutInit();
	options.push_back(std::make_tuple('H', "ealer's Hut"));
	//forestInit();
	options.push_back(std::make_tuple('F', "orest"));
	options.push_back(std::make_tuple('V', "iew Your Stats"));
	options.push_back(std::make_tuple('Q', "uit"));
	townMenu1 = Menu(header, options, prompt);
	// Menu m = Menu(header, options, prompt);
	// Menu::addMenu("Town", m);
	// Menu::addMenu("Town", Menu(header, options, prompt));
}
void townMain(Player player)
{
//	Menu::getMenu("Town").display(screen);
	//screen.clear();
	//screen.cursorReset();
	townMenu1.display(screen);
	char cmd;
	do {
		cmd = getKey();
        switch (cmd) {
        case 'A':
            armorShop(screen, player);
            break;
        case 'W':
            weaponShop(screen, player);
            break;
        case 'H':
            healersHut(screen, player);
            break;
        //case 'F':
        //    Forest::menu(screen);
        //    break;
		//case 'V':
		//	player.viewStats(screen);
		//	break;
        }
    } while (cmd != 'Q');
}

int main()
{
    Player p = introduction();
	townInit();
	//Item::init();
    townMain(p);
    screen.restore();
}
