#pragma once
#include "town.h"

void Town::townMain()
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
        CSL::clear();
        townMenu.display();
        cmd = townMenu.select();
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
        case 'V':
            Creatures::mainPlayer.viewStats();
            break;
        }
    } while (cmd != 'Q');
}

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
void Town::armorShop()
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
        CSL::clear();
        armorMenu.display();
        cmd = IT::getKey();
        switch (cmd) {
            //case 'B':
            //    buyArmor();
            //    break;
            //case 'S':
            //    sellArmor();
            //    break;
            //case 'L':
            //    listArmor();
            //    break;
            case 'V':
                Creatures::mainPlayer.viewStats();
                break;
            }
    } while (cmd != 'R');
}
//static void buyArmor() {};
//static void sellArmor() {};
//static void listArmor() {};

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
void Town::weaponShop()
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
        CSL::clear();
        weaponMenu.display();
        std::cin >> cmd;
        switch (cmd) {
        //case 'B':
        //    buyWeapons();
        //    break;
        //case 'S':
        //    sellWeapons();
        //    break;
        //case 'L':
        //    listWeapons();
        //    break;
        case 'V':
            Creatures::mainPlayer.viewStats();
            break;
        }
} while (cmd != 'R');
}
//static void buyWeapons() {};
//static void sellWeapons() {};
//static void listWeapons() {};

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
void Town::healersHut()
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
        CSL::clear();
        healersMenu.display();
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
