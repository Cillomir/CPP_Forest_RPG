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
	Add SQLLite (for character / game state storage)
    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <windows.h>
#include "support/Console.h"
#include "support/Internals.h"
#include "support/Locals.h"
#include "Menu.h"
#include "A_Areas/Town.h"
#include "C_Classes/Creatures.h"
using namespace CSL_Console;
using namespace Creatures;

#define Print std::cout <<
#define Input std::cin >>

static void introduction()
{
	CSL::clear();
	std::string playerName;
    Print "Please enter your name: ";
    Input playerName;
	playerName = IT::toCapitalize(playerName);
	Print "Welcome, " << playerName << "\n";
	pressAnyKey();
	player.SetName(playerName);
}

static void CharacterCreation()
{
	char cmd = ' ';
	do {
		CSL::clear();
		Print "Select a Race: ";
		Print "Human - the most common and most balanced. A human has an easier time learning skills and spells.";
		Print "Elf - long lived and wise. An elf has enhanced magic power with boosted agility and wisdom.";
		Print "Dwarf - sturdy and enduring. A dwarf has increased physical power with boosted strength and fortitude.";
		Print "Gnome - spiritual and energetic. A gnome has the highest magic power, but low physical abilities.";
		Print "Orc - fierce and well-built. An orc has the highest combative power, but low magical abilities.";

		std::vector<Menus::Option> options;
		options.push_back({ 'H', "Human" });
		options.push_back({ 'E', "Elf" });
		options.push_back({ 'D', "Dwarf" });
		options.push_back({ 'G', "Gnome" });
		options.push_back({ 'O', "Orc" });
		Menus::Menu createRace("Select a Race: ", options, "Your decision?");
		cmd = ' ';
		do {
			cmd = createRace.select();
			switch (cmd) {
			case 'H': player.SetRace(Race::Human);
				break;
			case 'E': player.SetRace(Race::Elf);
				break;
			case 'D': player.SetRace(Race::Dwarf);
				break;
			case 'G': player.SetRace(Race::Gnome);
				break;
			case 'O': player.SetRace(Race::Orc);
				break;
			}
		} while (cmd != 'H' && cmd != 'E' && cmd != 'D' && cmd != 'G' && cmd != 'O');

		options.clear();
		options.push_back({ 'F', "Fighter" });
		options.push_back({ 'R', "Rogue" });
		options.push_back({ 'W', "Wizard" });
		Menus::Menu createClass("Select a Class: ", options, "Your decision?");
		cmd = ' ';
		do {
			cmd = createClass.select();
			switch (cmd) {
			case 'F': player.SetSchool(School::Fighter);
				break;
			case 'R': player.SetSchool(School::Rogue);
				break;
			case 'W': player.SetSchool(School::Wizard);
				break;
			}
		} while (cmd != 'F' && cmd != 'R' && cmd != 'W');

		player.createNew(&player);
		player.viewStats(&player);

		options.clear();
		options.push_back({ 'Y', "Yes" });
		options.push_back({ 'N', "No" });
		Menus::Menu YesNo("Is this correct? ", options, "");
		cmd = ' ';
		cmd = YesNo.select();
	} while (cmd != 'Y');
}

int main()
{
	CSL::enableVTMode();
	introduction();
	CharacterCreation();
	player.viewStats(&player);

	//Town::townInit();
	//Item::init();
	RPG::Town::townMain();
	
	//Console::screen.restore();
}
