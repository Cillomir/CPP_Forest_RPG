#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "internals.h"
#include "console.h"
#include "menu.h"
#include "creature.h"

namespace Town
{
    static void armorShop()
    {
        std::string header = "Welcome to the Armor Shop!";
        std::string prompt = "Select an Option:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('B', "uy Armor"));
        options.push_back(std::make_tuple('S', "ell Armor"));
        options.push_back(std::make_tuple('L', "ist Armor"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('R', "eturn to Town"));
        Menu armorMenu = Menu(header, options, prompt);
        char cmd;
        do {
            Console::screen.clear();
            Console::screen.cursorReset();
            armorMenu.display(Console::screen);
            cmd = IT::getKey();
            //switch (cmd) {
                //case 'B':
                //    buyArmor();
                //    break;
                //case 'S':
                //    sellArmor();
                //    break;
                //case 'L':
                //    listArmor();
                //    break;
                //case 'V':
                //    player.viewStats();
                //    break;
                //}
        } while (cmd != 'Q');

    }
	//static void buyArmor() {};
	//static void sellArmor() {};
	//static void listArmor() {};

	static void weaponShop()
    {
        std::string header = "Welcome to the Weapon Shop!";
        std::string prompt = "Select an Option:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('B', "uy Weapons"));
        options.push_back(std::make_tuple('S', "ell Weapons"));
        options.push_back(std::make_tuple('L', "ist Weapons"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('R', "eturn to Town"));
        Menu weaponMenu = Menu(header, options, prompt);
        char cmd;
        do {
            Console::screen.clear();
            Console::screen.cursorReset();
            weaponMenu.display(Console::screen);
            std::cin >> cmd;
            //switch (cmd) {
                //case 'B':
                //    buyWeapons();
                //    break;
                //case 'S':
                //    sellWeapons();
                //    break;
                //case 'L':
                //    listWeapons();
                //    break;
                //case 'V':
                //    player.viewStats();
                //    break;
            //}
        } while (cmd != 'R');
    }
	//static void buyWeapons() {};
	//static void sellWeapons() {};
	//static void listWeapons() {};

    static void healersHut()
    {
        std::string header = "Welcome to the Healer's Hut!";
        std::string prompt = "Select an Option:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('H', "ealing"));
        options.push_back(std::make_tuple('B', "uy Potions"));
        options.push_back(std::make_tuple('S', "ell Potions"));
        options.push_back(std::make_tuple('L', "ist Potions"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('R', "eturn to Town"));
        Menu healersMenu = Menu(header, options, prompt);
        char cmd;
        do {
            Console::screen.clear();
            Console::screen.cursorReset();
            healersMenu.display(Console::screen);
            std::cin >> cmd;
            //switch (cmd) {
            //case 'H':
            //    getHealing();
            //    break;
            //case 'B':
            //    buyPotions();
            //    break;
            //case 'S':
            //    sellPotions();
            //    break;
            //case 'L':
            //    listPotions();
            //    break;
            //case 'V':
            //    player.viewStats();
            //    break;
            //}
        } while (cmd != 'R');

    }
	//static void getHealing();
	//static void buyPotions();
	//static void sellPotions();
	//static void listPotions();

    static void townMain()
    {
        std::string header = "Welcome to the town!";
        std::string prompt = "Select a destination:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('A', "rmor Shop"));
        options.push_back(std::make_tuple('W', "eapon Shop"));
        options.push_back(std::make_tuple('H', "ealer's Hut"));
        options.push_back(std::make_tuple('F', "orest"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('Q', "uit"));
        Menu townMenu = Menu(header, options, prompt);
        char cmd;
        do {
            Console::screen.clear();
            Console::screen.cursorReset();
            townMenu.display(Console::screen);
            cmd = IT::getKey();
            switch (cmd) {
            case 'A':
                armorShop();
                break;
            case 'W':
                weaponShop();
                break;
            case 'H':
                healersHut();
                break;
                //case 'F':
                //    Forest::menu();
                //    break;
                //case 'V':
                //	player.viewStats();
                //	break;
            }
        } while (cmd != 'Q');
    }

}
