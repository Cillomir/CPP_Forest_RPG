#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "support/Console.h"
#include "support/Internals.h"
#include "support/Locals.h"
#include "equipment.h"

#ifndef CREATURES_H
#define CREATURES_H

namespace Creatures
{
	enum class Condition
	{
		healthy, light_injury, medium_injury, heavy_injury, near_death, dead
	};
	class Creature
	{
	private:
		std::string _name;
		std::string _description;
		int _level;
		std::tuple <int, int> _health;
		Condition _condition;
		std::vector<Equipment> _allEquipment;

		void setDefaults(int level, int health);
		void calcCondition();

	public:
		Creature(std::string name)
		{
			_name = name;
			_description = "";
			setDefaults(1, 100);
		}
		Creature(std::string name, std::string description)
		{
			_name = name;
			_description = description;
			setDefaults(1, 100);
		}
		Creature(std::string name, std::string description, int level, int health)
		{
			_name = name;
			_description = description;
			setDefaults(level, health);
		}
		std::string getName() { return _name; }
		void setName(std::string name) { _name = name; }
		std::string getDescription() { return _description; }
		void setDescription(std::string description) { _description = description; }
		int getLevel() { return _level; }
		void setLevel(int level) { _level = level; }
		std::tuple<int, int> getHealth() { return _health; }
		void setHealth(int health) { _health = { health, health }; }
		void look();
		void examine();
		void hurt(int amount);
		void heal(int amount);
		bool take(Equipment item);
	};

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
		std::string _title;
		int _level;
		int _experience;
		int _gold;
		std::tuple <int, int> _health;
		int _strength;
		int _defense;
		Equipment _curWeapon;
		Equipment _curArmor;
		std::vector<Equipment> _allEquipment;
		std::vector<Equipment> _allWeapons;
		std::vector<Equipment> _allArmors;
		std::vector<Equipment> _allPotions;
		std::vector<Equipment> _allGear;
		std::vector<Equipment> _allMisc;

		void setDefaults();
		//	void sortEquipment(void)
		//	{
		//		std::sort(_allWeapons.begin(), _allWeapons.end(), [](equip a, equip b) {return a._name < b._name; });
		//		std::sort(_allArmors.begin(), _allArmors.end(), [](equip a, equip b) {return a._name < b._name; });
		//		std::sort(_allPotions.begin(), _allPotions.end(), [](equip a, equip b) {return a._name < b._name; });
		//		std::sort(_allGear.begin(), _allGear.end(), [](equip a, equip b) {return a._name < b._name; });
		//		std::sort(_allMisc.begin(), _allMisc.end(), [](equip a, equip b) {return a._name < b._name; });
		//		_allEquipment.clear();
		//		_allEquipment.emplace_back(_allWeapons);
		//		_allEquipment.emplace_back(_allArmors);
		//		_allEquipment.emplace_back(_allPotions);
		//		_allEquipment.emplace_back(_allGear);
		//		_allEquipment.emplace_back(_allMisc);
		//	};

	public:
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
		//void setMain()
		//{
		//	mainPlayer = *this;
		//}
		Player& operator=(Player& obj)
		{
			if (this != &obj)
			{
				_name = obj._name;
				_title = obj._title;
				_level = obj._level;
				_experience = obj._experience;
				_gold = obj._gold;
				_health = obj._health;
				_strength = obj._strength;
				_defense = obj._defense;
				_curWeapon = obj._curWeapon;
				_curArmor = obj._curArmor;
				_allEquipment = obj._allEquipment;
				_allWeapons = obj._allWeapons;
				_allArmors = obj._allArmors;
				_allPotions = obj._allPotions;
				_allGear = obj._allGear;
				_allMisc = obj._allMisc;
			}
			return *this;
		}

		std::string getName(void) { return _name; }
		void setName(std::string name) { _name = name; }

		std::string getTitle(void) { return _title; }
		void setTitle(std::string title) { _title = title; }

		int getLevel(void) { return _level; }
		void gainLevel(void) { if (_level < maxLevel) _level++; _experience = 0; }
		void loseLevel(void) { if (_level > minLevel) _level--; _experience = 0; }

		int getExp(void) { return _experience; }
		int gainExp(int exp) { if (_experience + exp < expNeeded[getLevel()]) _experience += exp; else gainLevel(); }

		int getGold(void) { return _gold; }
		void setGold(int gold) { _gold = gold; }
		void gainGold(int gold) { if (_gold + gold < maxGold) _gold += gold; }
		void loseGold(int gold) { if (_gold - gold > minGold) _gold -= gold; }

		int getHealth(void) { return std::get<0>(_health); }
		void setHealth(int health) { std::get<0>(_health) = health; }
		void gainHealth(int health) { std::get<0>(_health) += health; if (std::get<0>(_health) > std::get<1>(_health)) std::get<0>(_health) = std::get<1>(_health); }
		void loseHealth(int health) { std::get<0>(_health) -= health; if (std::get<0>(_health) < 0) std::get<0>(_health) = 0; }

		int getHealthMax(void) { return std::get<1>(_health); }
		void setHealthMax(int health) { std::get<1>(_health) = health; }
		void gainHealthMax(int health) { std::get<1>(_health) += health; }
		void loseHealthMax(int health) { if (std::get<1>(_health) - health > 0) std::get<1>(_health) -= health; }

		int getStrength(void) { return _strength; }
		void setStrength(int strength) { _strength = strength; }

		int getDefense(void) { return _defense; }
		void setDefense(int defense) { _defense = defense; }

		std::string getWeapon(void) { return _curWeapon.getName(); }
		void setWeapon(Equipment weapon) { _curWeapon = weapon; }

		std::string getArmor(void) { return _curArmor.getName(); }
		void setArmor(Equipment armor) { _curArmor = armor; }

		// Public Methods
		void viewStats();
	};
	static Player mainPlayer;

	//class NPC
	//{

	//};

	//class MOB
	//{

	//};
}
#endif
