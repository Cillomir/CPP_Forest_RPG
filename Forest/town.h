#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "support/Internals.h"
#include "support/Console.h"
#include "support/Locals.h"
#include "Menu.h"
#include "Creatures.h"
using namespace CSL_Console;

class Town
{
public:
	static void townMain();

	static void armorShop();
	//static void buyArmor();
	//static void sellArmor();
	//static void listArmor();

	static void weaponShop();
	//static void buyWeapons() {};
	//static void sellWeapons() {};
	//static void listWeapons() {};

	static void healersHut();
	//static void getHealing();
	//static void buyPotions();
	//static void sellPotions();
	//static void listPotions();

};
