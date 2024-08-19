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
#include "Items.h"
using namespace Items;

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
		none, cutting, stabbing, smashing, fire, water, earth, air, dark, light
	};


	class PC
	{
	private:
		// Constants
		static const int minLevel = 1;
		static const int maxLevel = 10;
		static const int minExp = 0;
		static const int minGold = 0;
		static const int maxGold = 1000000;
		const std::vector<int> expNeeded = { 0, 100, 200, 400, 800, 1500, 2500, 4000, 6500, 10000, 15000 };

		// General
		std::string _name;
		std::string _title;
		int _level;
		int _experience;
		int _gold;

		// Stats
		std::tuple <int, int> _health;
		std::tuple <int, int> _spirit;
		std::tuple <int, int> _stamina;
		int _strength;
		int _fortitude;
		int _agility;
		int _intellect;

		// Equipment
		Weapon _curWeapon;
		Armor _curArmor;
		Shield _curShield;
		std::vector<Item> _inventory;
		std::vector<Weapon> _weapons;
		std::vector<Armor> _armors;
		std::vector<Shield> _shields;
		std::vector<Potion> _potions;
		std::vector<Item> _gear;
		std::vector<Item> _miscItems;

		// Methods
		void init(std::string name);
		void sortInventory();

	public:
		// Constructor
		PC()
		{
			init("");
		}
		PC(std::string name)
		{
			init(name);
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
		std::vector<Item> _equipment;

		void baseinit(std::string name, std::string description, int level, int health);
		void calcCondition();

	public:
		MOB()
		{
			baseinit("", "", 1, 100);
		}
		MOB(std::string name)
		{
			baseinit(name, "", 1, 100);
		}
		MOB(std::string name, std::string description)
		{
			baseinit(name, description, 1, 100);
		}
		MOB(std::string name, std::string description, int level, int health)
		{
			baseinit(name, description, level, health);
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
		bool has(Item item);
		bool take(Item item);
	};

	class NPC : public MOB
	{
	private:
		std::vector<Item> _inventory;

		void init();
	public:
		NPC()
			: MOB()
		{
			init();
		}
		NPC(std::string name)
			: MOB(name)
		{
			init();
		}

		void addItem(Item item);
		bool hasItem(Item item);
		Item getItem(int index);
		void removeItem(int index);
		std::vector<Item> allItems();
	};

	class Beast : public MOB
	{
	private:
		int _attack;
		std::tuple<int, Dice::die> _damage;
		DamageType _damageType;
		int _experience;
		std::tuple<int, Dice::die> _gold;
		std::vector<Item> _loot;

		void init(int attack, std::tuple<int, Dice::die> damage, DamageType damageType,
			int experience, std::tuple<int, Dice::die> gold);

	public:
		Beast() : MOB()
		{
			init(0, { 0, Dice::d0 }, DamageType::none, 0, { 0, Dice::d0 });
		}
		Beast(std::string name)
			: MOB(name)
		{
			init(0, { 0, Dice::d0 }, DamageType::none, 0, { 0, Dice::d0 });
		}
		Beast(std::string name, int level, int health, int attack, std::tuple<int, Dice::die> damage, DamageType damageType,
			int experience, std::tuple<int, Dice::die> gold)
			: MOB(name, "", level, health)
		{
			init(attack, damage, damageType, experience, gold);
		}

		// Gets & Sets
		int getAttack();
		void setAttack(int attack);
		std::tuple<int, Dice::die> getDamage();
		int rollDamage();
		void setDamage(std::tuple<int, Dice::die> damage);
		int getExperience();
		void setExperience(int experience);
		std::tuple<int, Dice::die> getGold();
		int rollGold();
		void setGold(std::tuple<int, Dice::die> gold);
	};
}
#endif
