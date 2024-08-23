#pragma once
#include "Town.h"

using namespace Menus;
using namespace RPG;

std::unordered_map<std::string, Creatures::NPC> Town::shopkeepers = std::unordered_map<std::string, Creatures::NPC>();
std::unordered_map<std::string, Menu> Town::menus = std::unordered_map<std::string, Menu>();

void Town::initTown()
{
    std::string header = "Welcome to the town!";
    std::string prompt = "Select a destination:";
    std::vector<Option> options;
    options.push_back({ 'A', "Armor Shop" });
    options.push_back({ 'W', "Weapon Shop" });
    options.push_back({ 'H', "Healer's Hut" });
    options.push_back({ 'F', "Forest" });
    options.push_back({ 'V', "View Your Stats" });
    options.push_back({ 'Q', "Quit" });
    Town::menus.emplace("town", Menu(header, options, prompt));
    initArmorShop();
    initWeaponShop();
    initHealersHut();
}

void Town::townMain()
{
    if (!Town::menus.contains("town"))
        initTown();
    unsigned char cmd;
    do {
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
            Creatures::player.viewStats();
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
        std::vector<Option> options;
        options.push_back({ 'B', "uy Armor" });
        options.push_back({ 'S', "ell Armor" });
        options.push_back({ 'L', "ist Armor" });
        options.push_back({ 'V', "iew Your Stats" });
        options.push_back({ 'R', "eturn to Town" });
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
        std::vector<Option> options;
        options.push_back({ 'B', "uy Weapons" });
        options.push_back({ 'S', "ell Weapons" });
        options.push_back({ 'L', "ist Weapons" });
        options.push_back({ 'V', "iew Your Stats" });
        options.push_back({ 'R', "eturn to Town" });
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
        std::vector<Option> options;
        options.push_back({ 'H', "ealing" });
        options.push_back({ 'B', "uy Potions" });
        options.push_back({ 'S', "ell Potions" });
        options.push_back({ 'L', "ist Potions" });
        options.push_back({ 'V', "iew Your Stats" });
        options.push_back({ 'R', "eturn to Town" });
        Menu healersMenu = Menu(header, options, prompt);
    }
}

void Town::armorShop()
{
    initArmorShop();
    std::string message = "Welcome to Angar's Armor Shop. This is a test string to see if the string parsing will work for an armor shop description.";
    unsigned char cmd;
    do {
        Creatures::player.statLine();
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
                Creatures::player.viewStats();
                break;
        }
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
}


void Town::weaponShop()
{
    initWeaponShop();
    unsigned char cmd;
    do {
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
            Creatures::player.viewStats();
            break;
        }
} while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);
}

void Town::healersHut()
{
    initHealersHut();
    unsigned char cmd;
    do {
        cmd = Town::menus["healer"].select();
        switch (cmd) 
        {
            case 'H':
                getHealing();
                break;
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
                Creatures::player.viewStats();
                break;
        }
    } while (cmd != 'R' && cmd != CSL_Key::KEY_ESC);

}
void Town::getHealing()
{
    int missing = Creatures::player.getHealthMax() - Creatures::player.getHealth();
    Print "You are currently missing " << std::to_string(missing) << "health.\n";
    Print "It costs 2 gp per health point recovered.";
    Print "How much healing do you want? ";
    int healing;
    std::string input;
    std::cin >> input;
    if (std::isdigit(input[0]))
        healing = std::stoi(input);
    else
        healing = 0;
    if (healing > missing)
        healing = missing;
    if (healing < 0)
        healing = 0;
    if (healing * 2 > Creatures::player.getGold())
    {
        Print "You don't have enough gold to heal for that much.\n";
    }
    else
    {
        Print "Alright, healing you for " << std::to_string(healing) << " health points.\n";
        Creatures::player.loseGold(healing * 2);
        Creatures::player.gainHealth(healing);
    }
}

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
    for (Item e : shopkeep.allItems())
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

