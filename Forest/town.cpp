#pragma once
#include "town.h"
std::unordered_map<std::string, Creatures::NPC> Town::shopkeepers = std::unordered_map<std::string, Creatures::NPC>();
std::unordered_map<std::string, Menu> Town::menus = std::unordered_map<std::string, Menu>();

void Town::initTown()
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
    Town::menus.emplace("town", Menu(header, options, prompt));
}

void Town::townMain()
{
    if (!Town::menus.contains("town"))
        initTown();
    unsigned char cmd;
    do {
        CSL::clear();
        Town::menus["town"].display();
        cmd = Town::menus["town"].select();
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
    } while (cmd != 'Q' && cmd != CSL_Key::KEY_ESC);
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
void Town::initArmorShop()
{
    if (!Town::shopkeepers.contains("armor"))
    {
        Creatures::NPC shopkeep = Creatures::NPC("Angar Smithy");
        shopkeep.addItem(Armor("Leather Jerkin", 100));
        shopkeep.addItem(Armor("Padded Doublet", 200));
        shopkeep.addItem(Armor("Hide Armor", 450));
        shopkeep.addItem(Armor("Chainmail Armor", 800));
        shopkeep.addItem(Armor("Scale Armor", 1100));
        shopkeep.addItem(Armor("Coat of Plates", 1800));
        shopkeep.addItem(Armor("Platemail Armor", 2500));
        Town::shopkeepers.emplace("armor", shopkeep);
    }
}

void Town::armorShop()
{
    initArmorShop();
    std::string header = "Welcome to the Armor Shop!";
    std::string prompt = "Select an Option:";
    std::vector<std::tuple<char, std::string>> options;
    options.push_back(std::make_tuple('B', "uy Armor"));
    options.push_back(std::make_tuple('S', "ell Armor"));
    options.push_back(std::make_tuple('L', "ist Armor"));
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "eturn to Town"));
    Menu armorMenu = Menu(header, options, prompt);
    unsigned char cmd;
    do {
        CSL::clear();
        armorMenu.display();
        cmd = armorMenu.select();
        switch (cmd) {
            //case 'B':
            //    buyArmor();
            //    break;
            //case 'S':
            //    sellArmor();
            //    break;
            case 'L':
                listArmor();
                break;
            case 'V':
                Creatures::mainPlayer.viewStats();
                break;
            }
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
}
//static void buyArmor() {};
//static void sellArmor() {};
void Town::listArmor()
{
    CSL::clear();
    std::vector<Equipment> items = Town::shopkeepers["armor"].allItems();
    for (Equipment e : items) 
    {
        Print e.getName() << "   " << e.getValue() << "\n";
    }
    IT::pressKey();
};

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
    unsigned char cmd;
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
} while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
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
    unsigned char cmd;
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
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);

}
//static void getHealing();
//static void buyPotions();
//static void sellPotions();
//static void listPotions();
