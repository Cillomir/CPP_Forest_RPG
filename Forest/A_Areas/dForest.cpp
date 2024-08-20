// Forest Dungeon
#pragma once
#include "dungeons.h"

void Forest::init()
{
    std::string header = "You enter the edge of the forest.";
    std::string prompt = "What would you like to do?";
    std::vector<std::tuple<char, std::string>> options;
    options.push_back(std::make_tuple('E', "xplore the Forest"));
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "eturn to Town"));
    Forest::menus.emplace("main", Menu(header, options, prompt));
    
    header = "You have encountered something!";
    options.clear();
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "un Away"));
    Forest::menus.emplace("encounter", Menu(header, options, prompt));

    header = "You enter into combat!";
    options.clear();
    options.push_back(std::make_tuple('A', "ttack the Creature"));
    options.push_back(std::make_tuple('D', "efend Yourself"));
    options.push_back(std::make_tuple('V', "iew Your Stats"));
    options.push_back(std::make_tuple('R', "un Away"));
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
