/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Program Name: Forest.cpp
Author: Joel Leckie
Date: 
Description: This file contains the 'main' function. Program execution begins and ends there.

Versions:
    0.1.0 - 2024-06-20: Initial program creation and design

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
    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//#pragma once
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
#include "dForest.cpp"
//#include "internals.h"

Console screen = Console();
Menu townMenu1 = Menu();

/*
#pragma region Equipment
enum ItemType : int { weapon = 1, armor, potion, gear, misc };

class Item
{
public:
	//static void init(void);
	static std::vector<Item> allEquip()
	{
		return Item::_allEquipment;
	};
	static std::vector<Item> allWeapons()
	{
		return Item::_allWeapons;
	}
	static std::vector<Item> allArmors()
	{
		return Item::_allArmors;
	}
	static std::vector<Item> allPotions()
	{
		return Item::_allPotions;
	}
	static std::vector<Item> allGear()
	{
		return Item::_allGear;
	}
	static std::vector<Item> allMisc()
	{
		return Item::_allMisc;
	}

//	Item() {};

	Item(std::string name, int value, ItemType type) {
		_name = name;
		_value = value;
		_type = type;
		_allEquipment.emplace_back(this);

		switch (_type) {
		case weapon:
			_allWeapons.emplace_back(this);
			break;
		case armor:
			_allArmors.emplace_back(this);
			break;
		case potion:
			_allPotions.emplace_back(this);
			break;
		case gear:
			_allGear.emplace_back(this);
			break;
		case misc:
			_allMisc.emplace_back(this);
			break;
		}
	};

	std::string name() { return _name; }
	int value() { return _value; }
	std::string type() {
		switch (_type) {
		case weapon: return "weapon";
			break;
		case armor: return "armor";
			break;
		case potion: return "potion";
			break;
		case gear: return "gear";
			break;
		case misc: return "miscellaneous";
			break;
		};
	};
private:
	std::string _name;
	int _value;
	ItemType _type;

	static std::vector<Item> _allEquipment;
	static std::vector<Item> _allWeapons;
	static std::vector<Item> _allArmors;
	static std::vector<Item> _allPotions;
	static std::vector<Item> _allGear;
	static std::vector<Item> _allMisc;

	//static void sortEquipment(void)
	//{
	//	std::sort(_allWeapons.begin(), _allWeapons.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allArmors.begin(), _allArmors.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allPotions.begin(), _allPotions.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allGear.begin(), _allGear.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allMisc.begin(), _allMisc.end(), [](Item a, Item b) {return a._name < b._name; });
	//	_allEquipment.clear();
	//	_allEquipment.emplace_back(_allWeapons);
	//	_allEquipment.emplace_back(_allArmors);
	//	_allEquipment.emplace_back(_allPotions);
	//	_allEquipment.emplace_back(_allGear);
	//	_allEquipment.emplace_back(_allMisc);
	//}
};

//static bool initComplete = false;
//static void init(void) {
//	if (!initComplete) {
//		Item t;
//		t = Item("Fists", 0, ItemType::misc);
//		t = Item("Dagger", 0, ItemType::weapon);
//		t = Item("Iron Shortsword", 0, ItemType::weapon);
//		t = Item("Iron Longsword", 0, ItemType::weapon);
//		t = Item("Steel Shortsword", 0, ItemType::weapon);
//		t = Item("Steel Longsword", 0, ItemType::weapon);
//		t = Item("Tunic", 0, ItemType::armor);
//		t = Item("Leather", 0, ItemType::armor);
//		t = Item("Hide", 0, ItemType::armor);
//		t = Item("Chainmail", 0, ItemType::armor);
//		t = Item("Scalemail", 0, ItemType::armor);
//		t = Item("Half-Plate", 0, ItemType::armor);
//		t = Item("Plate", 0, ItemType::armor);
//		t = Item("Health", 0, ItemType::potion);
//		t = Item("Spirit", 0, ItemType::potion);
//		t = Item("Stamina", 0, ItemType::potion);
//		initComplete = true;
//	}
//}
#pragma endregion
*/

Player introduction() 
{
	testKey('q');
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
	options.push_back(std::make_tuple('Q', "uit"));
	townMenu1 = Menu(header, options, prompt);
	// Menu m = Menu(header, options, prompt);
	// Menu::addMenu("Town", m);
	// Menu::addMenu("Town", Menu(header, options, prompt));
}
void townMain(Player player)
{
    char cmd;
    do {
//		Menu::getMenu("Town").display(screen);
		cmd = getKey();
        screen.clear();
        screen.cursorReset();
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
