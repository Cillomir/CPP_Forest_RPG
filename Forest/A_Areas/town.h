#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>
#include "../support/Internals.h"
#include "../support/Console.h"
#include "../support/Locals.h"
#include "../Menu.h"
#include "../C_Classes/Creatures.h"
#include "../C_Classes/Items.h"
#include "../C_Classes/Abilities.h"
using namespace CSL_Console;

class Town
{
public:
	static std::unordered_map<std::string, Creatures::NPC> shopkeepers;
	static std::unordered_map<std::string, Menus::Menu> menus;

	static void initTown();
	static void townMain();

	static void initArmorShop();
	static void initWeaponShop();
	static void initHealersHut();
	static void armorShop();

	static void weaponShop();

	static void healersHut();
	static void getHealing();

	static void listItems(Creatures::NPC shopkeep);
	static void buyItem(Creatures::NPC shopkeep);
	static void sellItem(Creatures::NPC shopkeep);

};
