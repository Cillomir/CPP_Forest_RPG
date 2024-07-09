#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "support/Internals.h"
#include "support/Console.h"
#include "support/Locals.h"
#include "menu.h"
#include "creature.h"
using namespace CSL_Console;

namespace Town
{
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

}
