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
	enum class Gender
	{
		male, female, other
	};

	enum class Race
	{
		Human, Elf, Dwarf, Gnome, Orc
	};
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
	enum class EquipLocation
	{
		head, neck, body, arms, hands, waist, legs, feet, mainHand, offHand
	};

	struct StatPoints
	{
		std::string name;
		int current;
		int max;
		float GetPercent() {
			return (current / max) * 100;
		}
		std::string GetString() {
			return std::sprintf("%s: %d/%d", name, current, max);
		}
	};

	struct DamageType
	{
		std::string name;
		int power;
		int resist;
	};

	struct Equipped
	{
		std::string name;
		EquipLocation location;
		Item item;
	};

	class Creature
	{
	protected:
		// General
		std::string _name;
		std::string _gender;
		std::string _race;
		std::string _shortDesc;
		std::string _longDesc;
		
		int _level;
		int _experience;
		int _gold;
		int _silver;
		int _copper;

		// Stats
		StatPoints _health;
		StatPoints _spirit;
		StatPoints _stamina;
		int _strength;
		int _agility;
		int _fortitude;
		int _intellect;
		int _wisdom;

		int _armor;
		int _accuracy;
		int _evasion;
		int _magic;

		DamageType _cutting;
		DamageType _stabbing;
		DamageType _bashing;
		DamageType _fire;
		DamageType _water;
		DamageType _earth;
		DamageType _air;
		DamageType _poison;

		std::vector<Item> _inventory

	public:
		Creature(std::string name)
			: _name(name), _level(0), _experience(0), _gold(0),
			_health({ "Health", 0, 0 }), _spirit("Spirit", 0, 0), _stamina("Stamina", 0, 0),
			_strength(0), _agility(0), _fortitude(0), _intellect(0), _wisdom(0)
		{};

		std::string GetName() { return _name; }
		void SetName(std::string name) { _name = name; }
		std::string GetGender() { return _gender; }
		void SetGender(Gender gender)
		{
			switch (gender) {
			case Gender::male: _gender = "Male";
				break;
			case Gender::female: _gender = "Female";
				break;
			case Gender::other: _gender = "Other";
				break;
			}
		}
		std::string GetRace() { return _race; }
		void SetRace(Race race)
		{
			switch (race) {
			case Race::Human: _race = "Human";
				break;
			case Race::Elf: _race = "Elf";
				break;
			case Race::Dwarf: _race = "Dwarf";
				break;
			case Race::Gnome: _race = "Gnome";
				break;
			case Race::Orc: _race = "Orc";
				break;
			}
		}
		std::string GetShortDesc() { return _shortDesc; }
		void SetShortDesc(std::string desc) { _longDesc = desc; }
		std::string GetLongDesc() { return _shortDesc; }
		void SetLongDesc(std::string desc) { _longDesc = desc; }

		int GetLevel() { return _level; }
		void SetLevel(int level) { _level = level; }
		int GetExperience() { return _experience; }
		void SetExperience(int experience) { _experience = experience; }
		int GetGold() { return _gold; }
		void SetGold(int gold) { _gold = gold; }
		int GetSilver() { return _silver; }
		void SetSilver(int silver) { _silver = silver; }
		int GetCopper() { return _copper; }
		void SetCopper(int copper) { _copper = copper; }

		int GetCurHealth() { return _health.current; }
		int GetCurSpirit() { return _spirit.current; }
		int GetCurStamina() { return _stamina.current; }
		int GetMaxHealth() { return _health.max; }
		int GetMaxSpirit() { return _spirit.max; }
		int GetMaxStamina() { return _stamina.max; }
		float GetHealthPercent() { return _health.GetPercent(); }
		float GetSpiritPercent() { return _spirit.GetPercent(); }
		float GetStaminaPercent() { return _stamina.GetPercent(); }
		std::string ShowHealth() { return "Health: " + GetCurHealth() + "/" + GetMaxHealth(); }
		std::string ShowSpirit() { return "Spirit: " + GetCurSpirit() + "/" + GetMaxSpirit(); }
		std::string ShowStamina() { return "Stamina: " + GetCurStamina() + "/" + GetMaxStamina(); }

		int GetStrength() { return _strength; }
		void SetStrength(int strength) { _strength = strength; }
		int GetAgility() { return _agility; }
		void SetAgility(int agility) { _agility = agility; }
		int GetFortitude() { return _fortitude; }
		void SetFortitude(int Fortitude) { _fortitude = fortitude}
		int GetIntellect() { return _intellect; }
		void SetIntellect(int intellect) { _intellect = intellect; }
		int GetWisdom() { return _wisdom; }
		void SetWisdom(int wisdom) { _wisdom = wisdom; }

		std::vector<Item> GetInventory() { return _inventory; }
		void AddItem(Item item) { _inventory.emplace_back(item); }
		bool CheckItem(Item item) 
		{
			for (Item i : _inventory)
				if (i == item)
					return true;
			return false;
		}
		void RemoveItem(Item item) { _inventory.erase(item); }
	};

	class PC : public Creature
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
		std::string _title;

		// Equipment
		Weapon _curWeapon;
		Armor _curArmor;
		Shield _curShield;
		std::vector<Item> _items;
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
