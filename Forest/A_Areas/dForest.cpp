// Forest Dungeon
#pragma once
#include "Dungeons.h"

using namespace Menus;
using namespace RPG;

void Forest::init()
{
    std::string header = "You enter the edge of the forest.";
    std::string prompt = "What would you like to do?";
    std::vector<Option> options;
    options.push_back({ 'E', "Explore the Forest" });
    options.push_back({ 'V', "View Your Stats" });
    options.push_back({ 'R', "Return to Town" });
    Forest::menus.emplace("main", Menu(header, options, prompt));
    
    header = "You have encountered something!";
    options.clear();
    options.push_back({ 'I', "Interact with it" });
    options.push_back({ 'V', "View Your Stats" });
    options.push_back({ 'R', "Run Away" });
    Forest::menus.emplace("encounter", Menu(header, options, prompt));

    header = "You enter into combat!";
    options.clear();
    options.push_back({ 'A', "Attack the Creature" });
    options.push_back({ 'D', "Defend Yourself" });
    options.push_back({ 'S', "Use a Skill" });
    options.push_back({ 'C', "Cast a Spell" });
    options.push_back({ 'V', "View Your Stats" });
    options.push_back({ 'R', "Run Away" });
    Forest::menus.emplace("battle", Menu(header, options, prompt));
}
void Forest::generate()
{
    Forest::beasts.clear();
    switch (Creatures::player.getLevel())
    {
    case 1:
        generateLevel1();
        break;
    case 2:
        generateLevel2();
        break;
    case 3:
        generateLevel3();
        break;
    case 4:
        generateLevel4();
        break;
    case 5:
        generateLevel5();
        break;
    default:
        generateClear();
    }
}
void Forest::generateClear()
{

}
void Forest::generateLevel1()
{

}
void Forest::generateLevel2()
{

}
void Forest::generateLevel3()
{

}
void Forest::generateLevel4()
{

}
void Forest::generateLevel5()
{

}


void Forest::mainMenu()
{

}

void Forest::encounterMenu()
{

}

void Forest::battleMenu()
{

}



//void Forest::encounter() {
//
//}
//
//void Forest::menu(Console scrn) {
//	std::cout << "Welcome to the Forest\n";
//
//}
