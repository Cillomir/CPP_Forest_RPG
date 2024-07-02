#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "console.h"

#pragma region Creatures
class Player
{
protected:
	static const int minLevel = 1;
	static const int maxLevel = 10;
	static const int minExp = 0;
	static const int minGold = 0;
	static const int maxGold = 1000000;
	const std::vector<int> expNeeded = { 0, 100, 200, 400, 800, 1500, 2500, 4000, 6500, 10000, 15000 };

private:
	std::string _name;
	int _level;
	int _experience;
	int _gold;
	int _health;
	int _healthMax;
	int _strength;
	int _defense;
	//Item _weapon;
	//Item _armor;

	void setDefaults()
	{
		_level = 1;
		_experience = 0;
		_gold = 100;
		_health = 100;
		_healthMax = 100;
		_strength = 5;
		_defense = 3;
		//_weapon = Item("Fists", 0, ItemType::misc);
		//_armor = Item("Tunic", 0, ItemType::gear);
	}
public:
	static Player player;

	// Constructor
	Player() 
	{
		_name = "";
		setDefaults();
	}
	Player(std::string name)
	{
		_name = name;
		setDefaults();
	}

	// Sets & Gets
	std::string getName(void) { return _name; }
	void setName(std::string name) { _name = name; }

	int getLevel(void) { return _level; }
	void gainLevel(void) { if (_level < maxLevel) _level++; _experience = 0; }
	void loseLevel(void) { if (_level > minLevel) _level--; _experience = 0; }

	int getExp(void) { return _experience; }
	int gainExp(int exp) { if (_experience + exp < expNeeded[getLevel()]) _experience += exp; else gainLevel(); }

	int getGold(void) { return _gold; }
	void setGold(int gold) { _gold = gold; }
	void gainGold(int gold) { if (_gold + gold < maxGold) _gold += gold; }
	void loseGold(int gold) { if (_gold - gold > minGold) _gold -= gold; }

	int getHealth(void) { return _health; }
	void setHealth(int health) { _health = health; }
	void gainHealth(int health) { if (_health + health < _healthMax) _health += health; }
	void loseHealth(int health) { if (_health - health > 0) _health -= health; }

	int getHealthMax(void) { return _healthMax; }
	void setHealthMax(int health) { _healthMax = health; }
	void gainHealthMax(int health) { _healthMax += health; }
	void loseHealthMax(int health) { if (_healthMax - health > 0) _healthMax -= health; }

	int getStrength(void) { return _strength; }
	void setStrength(int strength) { _strength = strength; }

	int getDefense(void) { return _defense; }
	void setDefense(int defense) { _defense = defense; }

	//std::string getWeapon(void) { return _weapon.name(); }
	//void setWeapon(Item weapon) { _weapon = weapon; }

	//std::string getArmor(void) { return _armor.name(); }
	//void setArmor(Item armor) { _armor = armor; }

	// Public Methods
	//void viewStats(Console scrn);
	//void Player::viewStats(Console scrn) {
	//	scrn.clear();
	//	scrn.cursorReset();
	//	std::cout << this->getName() << std::endl;
	//	std::cout << std::string(25, '~') << std::endl;
	//};

};
#pragma endregion

//#include "internals.h"

//class creature
//{
//public:
//	// Constructor
//	creature(std::string name) {
//		_name = name;
//		_level = 1;
//		_experience = 0;
//		_gold = 100;
//		_health = 100;
//		_healthMax = 100;
//		_strength = 5;
//		_defense = 3;
//		_weapon = equip("Fists", 0, equipType::misc);
//		_armor = equip("Tunic", 0, equipType::gear);
//	};
//
//	// Sets & Gets
//	std::string getName(void) { return _name; }
//	void setName(std::string name) { _name = name; }
//
//	int getLevel(void) { return _level; }
//	void gainLevel(void) { if (_level < maxLevel) _level++;	}
//	void loseLevel(void) { if (_level > minLevel) _level--;	}
//
//	int getExp(void) { return _experience; }
//	
//	int getGold(void) { return _gold; }
//	void setGold(int gold) { _gold = gold; }
//	void gainGold(int gold) { if (_gold + gold < maxGold) _gold += gold; }
//	void loseGold(int gold) { if (_gold - gold > minGold) _gold -= gold; }
//
//	int getHealth(void) { return _health; }
//	void setHealth(int health) { _health = health; }
//	void gainGold(int health) { if (_health + health < _healthMax) _health += health; }
//	void loseGold(int health) { if (_health - health > 0) _health -= health; }
//
//	int getHealthMax(void) { return _healthMax; }
//	void setHealthMax(int health) { _healthMax = health; }
//	void gainHealthMax(int health) { _healthMax += health; }
//	void loseHealthMax(int health) { if (_healthMax - health > 0) _healthMax -= health; }
//
//	int getStrength(void) { return _strength; }
//	void setStrength(int strength) { _strength = strength; }
//	
//	int getDefense(void) { return _defense; }
//	void setDefense(int defense) { _defense = defense; }
//	
//	std::string getWeapon(void) { return _weapon.name(); }
//	void setWeapon(equip weapon) { _weapon = weapon; }
//	
//	std::string getArmor(void) { return _armor.name(); }
//	void setArmor(equip armor) { _armor = armor; }
//
//	// Public Methods
//	//void viewStats(console screen);
//	void viewStats(console screen) {
//		screen.clear();
//		screen.cursorReset();
//		std::cout << this->getName() << std::endl;
//		std::cout << std::string(25, '~') << std::endl;
//	};
//
//private:
//	std::string _name;
//	int _level;
//	int _experience;
//	int _gold;
//	int _health;
//	int _healthMax;
//	int _strength;
//	int _defense;
//	equip _weapon;
//	equip _armor;
//
//protected:
//	static const int minLevel = 1;
//	static const int maxLevel = 10;
//	static const int minExp = 0;
//	static const int minGold = 0;
//	static const int maxGold = 1000000;
//};

//class monster
//{
//
//};
