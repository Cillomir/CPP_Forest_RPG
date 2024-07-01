#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "console.cpp"
#include "creature.cpp"
#include "menu.cpp"
//#include "console.h"
//#include "creature.h"
//#include "internals.h"

static void armorShopInit();
static void weaponShopInit();
static void healersHutInit();

static void armorShop(Console scrn, Player player);
static void weaponShop(Console scrn, Player player);
static void healersHut(Console scrn, Player player);

//class shops
//{
//public:
//	static void enterShop(std::string name) 
//	{
//		std::cout << "Welcome to the " << name << "!";
//	}
//};
