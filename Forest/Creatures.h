#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "support/Console.h"
#include "support/Internals.h"
#include "support/Locals.h"
#include "Equipment.h"

#ifndef CREATURES_H
#define CREATURES_H

namespace Creatures
{
	enum class Condition
	{
		healthy, light_injury, medium_injury, heavy_injury, near_death, dead
	};
	enum class Title
	{
		none, fledgling, novice, adventurer, expert, master
	};
	enum class DamageType
	{
		cutting, stabbing, smashing, fire, water, earth, air, dark, light
	};


	class PC
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
		std::tuple <int, int> _spirit;
		std::tuple <int, int> _stamina;
		int _strength;
		int _fortitude;
		int _agility;
		int _intellect;
		Weapon _curWeapon;
		Armor _curArmor;
		Shield _curShield;
		std::vector<Equipment> _inventory;
		std::vector<Weapon> _weapons;
		std::vector<Armor> _armors;
		std::vector<Shield> _shields;
		std::vector<Equipment> _potions;
		std::vector<Equipment> _gear;
		std::vector<Equipment> _miscItems;

		void init();
		void sortEquipment();

	public:
		// Constructor
		PC()
		{
			init();
		}
		PC(std::string name)
		{
			init();
			_name = name;
		}

		PC& operator=(PC& obj)
		{
			if (this != &obj)
			{
				_name = obj._name;
				_title = obj._title;
				_level = obj._level;
				_experience = obj._experience;
				_gold = obj._gold;
				_health = obj._health;
				_spirit = obj._spirit;
				_stamina = obj._stamina;
				_strength = obj._strength;
				_fortitude = obj._fortitude;
				_agility = obj._agility;
				_intellect = obj._intellect;
				_curWeapon = obj._curWeapon;
				_curArmor = obj._curArmor;
				_curShield = obj._curShield;
				_inventory = obj._inventory;
				_weapons = obj._weapons;
				_armors = obj._armors;
				_shields = obj._shields;
				_potions = obj._potions;
				_gear = obj._gear;
				_miscItems = obj._miscItems;
			}
			return *this;
		}

		// Sets & Gets
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

		int getSpirit(void) { return std::get<0>(_spirit); }
		void setSpirit(int spirit) { std::get<0>(_spirit) = spirit; }
		void gainSpirit(int spirit) { std::get<0>(_spirit) += spirit; if (std::get<0>(_spirit) > std::get<1>(_spirit)) std::get<0>(_spirit) = std::get<1>(_spirit); }
		void loseSpirit(int spirit) { std::get<0>(_spirit) -= spirit; if (std::get<0>(_spirit) < 0) std::get<0>(_spirit) = 0; }

		int getSpiritMax(void) { return std::get<1>(_spirit); }
		void setSpiritMax(int spirit) { std::get<1>(_spirit) = spirit; }
		void gainSpiritMax(int spirit) { std::get<1>(_spirit) += spirit; }
		void loseSpiritMax(int spirit) { if (std::get<1>(_spirit) - spirit > 0) std::get<1>(_spirit) -= spirit; }

		int getStamina(void) { return std::get<0>(_stamina); }
		void setStamina(int stamina) { std::get<0>(_stamina) = stamina; }
		void gainStamina(int stamina) { std::get<0>(_stamina) += stamina; if (std::get<0>(_stamina) > std::get<1>(_stamina)) std::get<0>(_stamina) = std::get<1>(_stamina); }
		void loseStamina(int stamina) { std::get<0>(_stamina) -= stamina; if (std::get<0>(_stamina) < 0) std::get<0>(_stamina) = 0; }

		int getStaminaMax(void) { return std::get<1>(_stamina); }
		void setStaminaMax(int stamina) { std::get<1>(_stamina) = stamina; }
		void gainStaminaMax(int stamina) { std::get<1>(_stamina) += stamina; }
		void loseStaminaMax(int stamina) { if (std::get<1>(_stamina) - stamina > 0) std::get<1>(_stamina) -= stamina; }

		int getStrength(void) { return _strength; }
		void setStrength(int strength) { _strength = strength; }

		int getFortitude(void) { return _fortitude; }
		void setFortitude(int fortitude) { _fortitude = fortitude; }

		int getAgility(void) { return _agility; }
		void setAgility(int agility) { _agility = agility; }

		int getIntellect(void) { return _intellect; }
		void setIntellect(int intellect) { _intellect = intellect; }

		std::string getWeapon(void) { return _curWeapon.getName(); }
		void setWeapon(Weapon weapon) { _curWeapon = weapon; }

		std::string getArmor(void) { return _curArmor.getName(); }
		void setArmor(Armor armor) { _curArmor = armor; }

		std::string getShield(void) { return _curShield.getName(); }
		void setShield(Shield shield) { _curShield = shield; }

		int getAccuracy();
		int getDamCutting();
		int getDamStabbing();
		int getDamSmashing();
		int getDodge();
		int getResCutting();
		int getResStabbing();
		int getResSmashing();

		// Public Methods
		void viewStats();
		void statLine();
	};
	static PC player;

	class MOB
	{
	protected:
		std::string _name;
		std::string _description;
		int _level;
		std::tuple <int, int> _health;
		Condition _condition;
		std::vector<Equipment> _equipment;

		void init(std::string name, std::string description, int level, int health);
		void calcCondition();

	public:
		MOB()
		{
			init("", "", 1, 100);
		}
		MOB(std::string name)
		{
			init(name, "", 1, 100);
		}
		MOB(std::string name, std::string description)
		{
			init(name, description, 1, 100);
		}
		MOB(std::string name, std::string description, int level, int health)
		{
			init(name, description, level, health);
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
		bool has(Equipment item);
		bool take(Equipment item);
	};

	class NPC : public MOB
	{
	private:
		std::vector<Equipment> _inventory;

	public:
		NPC()
		{
			init("", "", 1, 100);
			_inventory = std::vector<Equipment>();

		}
		NPC(std::string name)
		{
			init(name, "", 1, 100);
			_inventory = std::vector<Equipment>();
		}

		void addItem(Equipment item);
		bool hasItem(Equipment item);
		Equipment getItem(int index);
		void removeItem(int index);
		std::vector<Equipment> allItems();
	};

	class Beast : public MOB
	{
	private:
		int _attack;
		std::tuple<int, int> _damage;
		DamageType _damageType;
		int _experience;
		std::tuple<int, int> _gold;
		std::vector<Equipment> _loot;

	public:
		Beast() : MOB()
		{
			init();
		}
		Beast(std::string name)
			: MOB(name)
		{
			init();
		}
		Beast(std::string name, int level, int health, int attack, std::tuple<int, int> damage, int experience, std::tuple<int, int> gold)
			: MOB(name, "", level, health)
		{
			init(attack, damage, experience, gold);
		}

		// Gets & Sets
		int getAttack() { return _attack; }
		void setAttack(int attack) { _attack = attack; }
		std::tuple<int, int> getDamage() { return _damage; }
		int rollDamage()
		{
			int damage = 0;
			for (int i = 0; i < std::get<0>(_damage); ++i)
			{
				damage += rand() % std::get<1>(_damage) + 1;
			}
			return damage;
		}

	};
}
#endif
