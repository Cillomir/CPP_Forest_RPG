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
#include "creature.h"
#include "town.h"
//#include "dForest.cpp"

//Console screen = Console();

Player introduction() 
{
	Console::screen.clear();
	Console::screen.cursorReset();
	std::string playerName;
    std::cout << "Please enter your name: ";
    std::cin >> playerName;
	playerName = IT::toCapitalize(playerName);
	std::cout << "Welcome, " << playerName << "\n";
	Player player = Player(playerName);
	Player::player.setName(playerName);
	//player.viewStats();
	return player;
}

int main()
{
	Player p = introduction();
	//Town::townInit();
	//Item::init();
	Town::townMain();
	//Console::screen.restore();
}