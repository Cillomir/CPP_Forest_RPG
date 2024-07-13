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
    initArmorShop();

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

void Town::initArmorShop()
{
    if (!Town::shopkeepers.contains("armor"))
    {
        Creatures::NPC shopkeep = Creatures::NPC("Angar Smithy");
        shopkeep.addItem(Armor("Cloth Tunic", 20));
        shopkeep.addItem(Armor("Leather Jerkin", 100));
        shopkeep.addItem(Armor("Padded Doublet", 200));
        shopkeep.addItem(Armor("Hide Armor", 450));
        shopkeep.addItem(Armor("Chainmail Armor", 800));
        shopkeep.addItem(Armor("Scale Armor", 1100));
        shopkeep.addItem(Armor("Breastplate", 1450));
        shopkeep.addItem(Armor("Coat of Plates", 1800));
        shopkeep.addItem(Armor("Half-Plate Armor", 2500));
        shopkeep.addItem(Armor("Platemail Armor", 4000));
        Town::shopkeepers.emplace("armor", shopkeep);
    }
    if (!Town::menus.contains("armor"))
    {
        std::string header = "Welcome to the Armor Shop!";
        std::string prompt = "Select an Option:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('B', "uy Armor"));
        options.push_back(std::make_tuple('S', "ell Armor"));
        options.push_back(std::make_tuple('L', "ist Armor"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('R', "eturn to Town"));
        Town::menus.emplace("armor", Menu(header, options, prompt));
    }
}

void Town::initWeaponShop()
{
    if (!Town::shopkeepers.contains("weapon"))
    {
        Creatures::NPC shopkeep = Creatures::NPC("Dylan Forger");
        shopkeep.addItem(Weapon("Iron Dagger", 120));
        shopkeep.addItem(Weapon("Steel Dagger", 200));
        shopkeep.addItem(Weapon("Iron Scimitar", 450));
        shopkeep.addItem(Weapon("Steel Scimitar", 600));
        shopkeep.addItem(Weapon("Iron Shortsword", 900));
        shopkeep.addItem(Weapon("Steel Shortsword", 1150));
        shopkeep.addItem(Weapon("Iron Longsword", 1400));
        shopkeep.addItem(Weapon("Steel Longsword", 1650));
        Town::shopkeepers.emplace("weapon", shopkeep);
    }
    if (!Town::menus.contains("weapon"))
    {
        std::string header = "Welcome to the Weapon Shop!";
        std::string prompt = "Select an Option:";
        std::vector<std::tuple<char, std::string>> options;
        options.push_back(std::make_tuple('B', "uy Weapons"));
        options.push_back(std::make_tuple('S', "ell Weapons"));
        options.push_back(std::make_tuple('L', "ist Weapons"));
        options.push_back(std::make_tuple('V', "iew Your Stats"));
        options.push_back(std::make_tuple('R', "eturn to Town"));
        Town::menus.emplace("weapon", Menu(header, options, prompt));
    }
}

void Town::initHealersHut()
{
    if (!Town::shopkeepers.contains("healer"))
    {
        Creatures::NPC shopkeep("Francine Surger");
        shopkeep.addItem(Potion("Health Potion", 40));
        shopkeep.addItem(Potion("Greater Health Potion", 150));
        shopkeep.addItem(Potion("Spirit Potion", 60));
        shopkeep.addItem(Potion("Greater Spirit Potion", 200));
        shopkeep.addItem(Potion("Stamina Potion", 35));
        shopkeep.addItem(Potion("Greater Stamina Potion", 125));
        shopkeep.addItem(Potion("Elixer of Protection", 90));
        Town::shopkeepers.emplace("healer", shopkeep);
    }
    if (!Town::menus.contains("healer"))
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

    }
}

void Town::armorShop()
{
    initArmorShop();
    unsigned char cmd;
    do {
        CSL::clear();
        Town::menus["armor"].display();
        cmd = Town::menus["armor"].select();
        switch (cmd) 
        {
            //case 'B':
            //    buyArmor();
            //    break;
            //case 'S':
            //    sellArmor();
            //    break;
            case 'L':
                listItems(Town::shopkeepers["armor"]);
                break;
            case 'V':
                Creatures::mainPlayer.viewStats();
                break;
        }
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
}
//static void buyArmor() {};
//static void sellArmor() {};
//void Town::listArmor()
//{
//    CSL::clear();
//    //Cursor::setHor(3);
//    //Print CSL_Line::SETTAB;
//    //Cursor::setHor(5);
//    //Print CSL_Line::SETTAB;
//    //Cursor::setHor(30);
//    //Print CSL_Line::SETTAB;
//
//    CSL_Line::Line::lineDrawingOn();
//    Cursor::setPos(2, 2);
//    CSL_Line::Line::lineDraw(CSL_Line::Line::TL);
//    for (int x = 3; x < 40; ++x)
//        CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
//    CSL_Line::Line::lineDraw(CSL_Line::Line::TR);
//    for (int y = 4; y < 15; ++y)
//    {
//        Print "\n";
//        Cursor::setHor(2);
//        CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
//        Cursor::setHor(40);
//        CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
//    }
//    Print "\n";
//    Cursor::setHor(2);
//    CSL_Line::Line::lineDraw(CSL_Line::Line::BL);
//    for (int x = 3; x < 40; ++x)
//        CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
//    CSL_Line::Line::lineDraw(CSL_Line::Line::BR);
//    CSL_Line::Line::lineDrawingOff();
//    
//    Cursor::setPos(1, 4);
//    std::vector<Equipment> items = Town::shopkeepers["armor"].allItems();
//    bool newPage = false;
//    int i = 0;
//    for (Equipment e : items) 
//    {
//        if (i > 9)
//        {
//            newPage = true;
//            break;
//        }
//        Cursor::setHor(4);
//        Print i;
//        Cursor::setHor(8);
//        Print e.getName();
//        char str[9] = { 0 };
//        sprintf_s(str, 9, "% 5d gp", e.getValue());
//        Cursor::setHor(30);
//        Print str << "\n";
//        i++;
//    }
//    IT::pressKey();
//};

void Town::weaponShop()
{
    initWeaponShop();
    unsigned char cmd;
    do {
        CSL::clear();
        Town::menus["weapon"].display();
        cmd = Town::menus["weapon"].select();
        switch(cmd) {
        //case 'B':
        //    buyWeapons();
        //    break;
        //case 'S':
        //    sellWeapons();
        //    break;
        case 'L':
            listItems(Town::shopkeepers["weapon"]);
            break;
        case 'V':
            Creatures::mainPlayer.viewStats();
            break;
        }
} while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
}
//static void buyWeapons() {};
//static void sellWeapons() {};
//static void listWeapons() {};

void Town::healersHut()
{
    initHealersHut();
    unsigned char cmd;
    do {
        CSL::clear();
        Town::menus["healer"].display();
        cmd = Town::menus["healer"].select();
        switch (cmd) 
        {
            //case 'H':
            //    getHealing();
            //    break;
            //case 'B':
            //    buyPotions();
            //    break;
            //case 'S':
            //    sellPotions();
            //    break;
            case 'L':
                listItems(Town::shopkeepers["healer"]);
                break;
            case 'V':
                Creatures::mainPlayer.viewStats();
                break;
        }
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);

}
//static void getHealing();
//static void buyPotions();
//static void sellPotions();
//static void listPotions();

void Town::listItems(Creatures::NPC shopkeep)
{
    CSL::clear();
    CSL_Line::Line::lineDrawingOn();
    Cursor::setPos(2, 2);
    CSL_Line::Line::lineDraw(CSL_Line::Line::TL);
    for (int x = 3; x < 40; ++x)
        CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
    CSL_Line::Line::lineDraw(CSL_Line::Line::TR);
    for (int y = 4; y < 15; ++y)
    {
        Print "\n";
        Cursor::setHor(2);
        CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
        Cursor::setHor(40);
        CSL_Line::Line::lineDraw(CSL_Line::Line::VER);
    }
    Print "\n";
    Cursor::setHor(2);
    CSL_Line::Line::lineDraw(CSL_Line::Line::BL);
    for (int x = 3; x < 40; ++x)
        CSL_Line::Line::lineDraw(CSL_Line::Line::HOR);
    CSL_Line::Line::lineDraw(CSL_Line::Line::BR);
    CSL_Line::Line::lineDrawingOff();

    Cursor::setPos(1, 4);
    bool newPage = false;
    int i = 0;
    for (Equipment e : shopkeep.allItems())
    {
        if (i > 9)
        {
            newPage = true;
            break;
        }
        Cursor::setHor(4);
        Print i;
        Cursor::setHor(8);
        Print e.getName();
        char str[9] = { 0 };
        sprintf_s(str, 9, "% 5d gp", e.getValue());
        Cursor::setHor(30);
        Print str << "\n";
        i++;
    }
    IT::pressKey();
}

void Town::buyItem(Creatures::NPC shopkeep)
{
    Print "What would you like to buy?";

};

void Town::sellItem(Creatures::NPC shopkeep)
{
    Print "What would you like to sell?";
};

