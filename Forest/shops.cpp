//#pragma once
#include "shops.h"

#pragma region Shops

static void armorShop(Console scrn, Player player) {
    char cmd;
    do {
        std::cout << "Welcome to the Armor Shop\n";
        std::cout << BLUE << "[B]" << WHITE << "uy Armor\n";
        std::cout << "[S]ell Armor\n";
        std::cout << "[L]ist Armor\n";
        std::cout << "[V]iew Stats\n";
        std::cout << "[R]eturn\n";
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

static void weaponShop(Console scrn, Player player) {
    std::cout << "Welcome to the Weapon Shop\n";
};

static void healersHut(Console scrn, Player player) {
    std::cout << "Welcome to the Healer's Hut\n";

};

#pragma endregion

//static void armorShop(typename console screen, typename creature player) {
//    char cmd;
//    do {
//        std::cout << "Welcome to the Armor Shop\n";
//        std::cout << BLUE << "[B]" << WHITE << "uy Armor\n";
//        std::cout << "[S]ell Armor\n";
//        std::cout << "[L]ist Armor\n";
//        std::cout << "[V]iew Stats\n";
//        std::cout << "[R]eturn\n";
//        std::cin >> cmd;
//        screen.clear();
//        screen.cursorReset();
//        switch (cmd) {
//        case 'B':
//            buyArmor(screen, player);
//            break;
//        case 'S':
//            sellArmor(screen, player);
//            break;
//        case 'L':
//            listArmor(screen, player);
//            break;
//        case 'V':
//            player.viewStats(screen);
//            break;
//        }
//    } while (cmd != 'R');
//}
//
//static void buyArmor(typename console screen, typename creature player) {};
//static void sellArmor(typename console screen, typename creature player) {};
//static void listArmor(typename console screen, typename creature player) {};
//
//static void weaponShop(typename console screen, typename creature player) {
//    std::cout << "Welcome to the Weapon Shop\n";
//
//};
//
//static void healersHut(typename console screen, typename creature player) {
//    std::cout << "Welcome to the Healer's Hut\n";
//
//};
