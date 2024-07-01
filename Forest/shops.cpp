#pragma once
#include "shops.h"

//Menu armorMenu1 = Menu();
//Menu weaponMenu1 = Menu();
//Menu healersMenu1 = Menu();

#pragma region Armor Shop
static void armorShopInit()
{
    std::string header = "Welcome to the Armor Shop!";
    std::string prompt = "Select an Option:";
    std::vector<std::tuple<char, std::string>> options;
    options.push_back(std::make_tuple('B', "uy Armor"));
    options.push_back(std::make_tuple('S', "ell Armor"));
    options.push_back(std::make_tuple('L', "ist Armor"));
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "eturn to Town"));
    //armorMenu1.setHeader(header);
    //armorMenu1.setPrompt(prompt);
     Menu armorMenu1 = Menu(header, options, prompt);
    // Menu m = Menu(header, options, prompt);
    // Menu::addMenu("Armor", m);
    // Menu::addMenu("Armor", Menu(header, options, prompt));
}
static void armorShop(Console scrn, Player player) {
    char cmd;
    do {    
        //armorMenu1.display(scrn);
        //std::cout << "Welcome to the Armor Shop\n";
        //std::cout << BLUE << "[B]" << WHITE << "uy Armor\n";
        //std::cout << "[S]ell Armor\n";
        //std::cout << "[L]ist Armor\n";
        //std::cout << "[V]iew Stats\n";
        //std::cout << "[R]eturn\n";
        std::cin >> cmd;
        scrn.clear();
        scrn.cursorReset();
        //switch (cmd) {
        //case 'B':
        //    buyArmor(scrn, player);
        //    break;
        //case 'S':
        //    sellArmor(scrn, player);
        //    break;
        //case 'L':
        //    listArmor(scrn, player);
        //    break;
        //case 'V':
        //    player.viewStats(scrn);
        //    break;
        //}
    } while (cmd != 'R');
}
//static void buyArmor(Console scrn, Player player) {};
//static void sellArmor(Console scrn, Player player) {};
//static void listArmor(Console scrn, Player player) {};

#pragma endregion

#pragma region Weapon Shop
static void weaponShopInit()
{
    std::string header = "Welcome to the Weapon Shop!";
    std::string prompt = "Select an Option:";
    std::vector<std::tuple<char, std::string>> options;
    options.push_back(std::make_tuple('B', "uy Weapons"));
    options.push_back(std::make_tuple('S', "ell Weapons"));
    options.push_back(std::make_tuple('L', "ist Weapons"));
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "eturn to Town"));
    Menu weaponMenu1 = Menu(header, options, prompt);
    // Menu m = Menu(header, options, prompt);
    // Menu::addMenu("Weapon", m);
    // Menu::addMenu("Weapon", Menu(header, options, prompt));
}
static void weaponShop(Console scrn, Player player) {
    char cmd;
    do {
        //weaponMenu1.display(scrn);
        std::cin >> cmd;
        scrn.clear();
        scrn.cursorReset();
        //switch (cmd) {
        //case 'B':
        //    buyWeapons(scrn, player);
        //    break;
        //case 'S':
        //    sellWeapons(scrn, player);
        //    break;
        //case 'L':
        //    listWeapons(scrn, player);
        //    break;
        //case 'V':
        //    player.viewStats(scrn);
        //    break;
        //}
    } while (cmd != 'R');
};
//static void buyWeapons(Console scrn, Player player) {};
//static void sellWeapons(Console scrn, Player player) {};
//static void listWeapons(Console scrn, Player player) {};

#pragma endregion

#pragma region Healers Hut
static void healersHutInit()
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
    Menu healersMenu1 = Menu(header, options, prompt);
    // Menu m = Menu(header, options, prompt);
    // Menu::addMenu("Healer", m);
    // Menu::addMenu("Healer", Menu(header, options, prompt));
}

static void healersHut(Console scrn, Player player) {
    char cmd;
    do {
        //healersMenu1.display(scrn);
        std::cin >> cmd;
        scrn.clear();
        scrn.cursorReset();
        //switch (cmd) {
        //case 'H':
        //    getHealing(scrn, player);
        //    break;
        //case 'B':
        //    buyPotions(scrn, player);
        //    break;
        //case 'S':
        //    sellPotions(scrn, player);
        //    break;
        //case 'L':
        //    listPotions(scrn, player);
        //    break;
        //case 'V':
        //    player.viewStats(scrn);
        //    break;
        //}
    } while (cmd != 'R');

};

#pragma endregion
