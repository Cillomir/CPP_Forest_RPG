#pragma once
#include "town.h"

#pragma region Town
//static void Town::townMain()
//{
//    std::string header = "Welcome to the town!";
//    std::string prompt = "Select a destination:";
//    std::vector<std::tuple<char, std::string>> options;
//    options.push_back(std::make_tuple('A', "rmor Shop"));
//    options.push_back(std::make_tuple('W', "eapon Shop"));
//    options.push_back(std::make_tuple('H', "ealer's Hut"));
//    options.push_back(std::make_tuple('F', "orest"));
//    options.push_back(std::make_tuple('V', "iew Your Stats"));
//    options.push_back(std::make_tuple('Q', "uit"));
//    Menu townMenu = Menu(header, options, prompt);
//    char cmd;
//    do {
//        Console::screen.clear();
//        Console::screen.cursorReset();
//        townMenu.display(Console::screen);
//        cmd = IT::getKey();
//        switch (cmd) {
//        case 'A':
//            Town::armorShop();
//            break;
//        case 'W':
//            Town::weaponShop();
//            break;
//        case 'H':
//            Town::healersHut();
//            break;
//            //case 'F':
//            //    Forest::menu();
//            //    break;
//            //case 'V':
//            //	player.viewStats();
//            //	break;
//        }
//    } while (cmd != 'Q');
//}
#pragma endregion

//#pragma region Armor Shop
//static void Town::armorShopInit()
//{
//    std::string header = "Welcome to the Armor Shop!";
//    std::string prompt = "Select an Option:";
//    std::vector<std::tuple<char, std::string>> options;
//    options.push_back(std::make_tuple('B', "uy Armor"));
//    options.push_back(std::make_tuple('S', "ell Armor"));
//    options.push_back(std::make_tuple('L', "ist Armor"));
//    options.push_back(std::make_tuple('V', "iew Your Stats"));
//    options.push_back(std::make_tuple('R', "eturn to Town"));
//    //armorMenu1.setHeader(header);
//    //armorMenu1.setPrompt(prompt);
//     Menu armorMenu1 = Menu(header, options, prompt);
//    // Menu m = Menu(header, options, prompt);
//    // Menu::addMenu("Armor", m);
//    // Menu::addMenu("Armor", Menu(header, options, prompt));
//}
//static void Town::armorShop() {
//    char cmd;
//    do {    
//        //armorMenu1.display(Console::screen);
//        std::cin >> cmd;
//        //Console::screen.clear();
//        //Console::screen.cursorReset();
//        //switch (cmd) {
//            //case 'B':
//            //    buyArmor();
//            //    break;
//            //case 'S':
//            //    sellArmor();
//            //    break;
//            //case 'L':
//            //    listArmor();
//            //    break;
//            //case 'V':
//            //    player.viewStats();
//            //    break;
//        //}
//    } while (cmd != 'R');
//}
//static void buyArmor() {};
//static void sellArmor() {};
//static void listArmor() {};
#pragma endregion

#pragma region Weapon Shop
//static void Town::weaponShopInit()
//{
//    std::string header = "Welcome to the Weapon Shop!";
//    std::string prompt = "Select an Option:";
//    std::vector<std::tuple<char, std::string>> options;
//    options.push_back(std::make_tuple('B', "uy Weapons"));
//    options.push_back(std::make_tuple('S', "ell Weapons"));
//    options.push_back(std::make_tuple('L', "ist Weapons"));
//    options.push_back(std::make_tuple('V', "iew Your Stats"));
//    options.push_back(std::make_tuple('R', "eturn to Town"));
//    Menu weaponMenu1 = Menu(header, options, prompt);
//    // Menu m = Menu(header, options, prompt);
//    // Menu::addMenu("Weapon", m);
//    // Menu::addMenu("Weapon", Menu(header, options, prompt));
//}
//static void Town::weaponShop() {
//    char cmd;
//    do {
//        //weaponMenu1.display(Console::screen);
//        std::cin >> cmd;
//        //Console::screen.clear();
//        //Console::screen.cursorReset();
//        //switch (cmd) {
//        //case 'B':
//        //    buyWeapons();
//        //    break;
//        //case 'S':
//        //    sellWeapons();
//        //    break;
//        //case 'L':
//        //    listWeapons();
//        //    break;
//        //case 'V':
//        //    player.viewStats();
//        //    break;
//        //}
//    } while (cmd != 'R');
//};
//static void buyWeapons() {};
//static void sellWeapons() {};
//static void listWeapons() {};
#pragma endregion

#pragma region Healers Hut
//static void Town::healersHutInit()
//{
//    std::string header = "Welcome to the Healer's Hut!";
//    std::string prompt = "Select an Option:";
//    std::vector<std::tuple<char, std::string>> options;
//    options.push_back(std::make_tuple('H', "ealing"));
//    options.push_back(std::make_tuple('B', "uy Potions"));
//    options.push_back(std::make_tuple('S', "ell Potions"));
//    options.push_back(std::make_tuple('L', "ist Potions"));
//    options.push_back(std::make_tuple('V', "iew Your Stats"));
//    options.push_back(std::make_tuple('R', "eturn to Town"));
//    Menu healersMenu1 = Menu(header, options, prompt);
//    // Menu m = Menu(header, options, prompt);
//    // Menu::addMenu("Healer", m);
//    // Menu::addMenu("Healer", Menu(header, options, prompt));
//}
//static void Town::healersHut() {
//    char cmd;
//    do {
//        //healersMenu1.display(Console::screen);
//        std::cin >> cmd;
//        //Console::screen.clear();
//        //Console::screen.cursorReset();
//        //switch (cmd) {
//        //case 'H':
//        //    getHealing();
//        //    break;
//        //case 'B':
//        //    buyPotions();
//        //    break;
//        //case 'S':
//        //    sellPotions();
//        //    break;
//        //case 'L':
//        //    listPotions();
//        //    break;
//        //case 'V':
//        //    player.viewStats();
//        //    break;
//        //}
//    } while (cmd != 'R');
//
//};
//static void getHealing();
//static void buyPotions();
//static void sellPotions();
//static void listPotions();
#pragma endregion
