#pragma once
#ifndef CREATURES_H
#define CREATURES_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <format>
#include "../support/Console.h"
#include "../support/Internals.h"
#include "../support/Locals.h"
#include "Abilities.h"
#include "Items.h"
using namespace Items;

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
	enum class School
	{
		none, Fighter, Rogue, Wizard
	};

	enum class Condition
	{
		healthy, light_injury, medium_injury, heavy_injury, near_death, dead
	};
	enum class Title
	{
		none, fledgling, novice, adventurer, expert, master
	};

	struct StatPoints
	{
		std::string name;
		int current;
		int max;
		float GetPercent() {
			return ((float)current / (float)max) * 100;
		}
		std::string GetString() {
			return std::format("{}: {}/{}", name, current, max);
		}
	};

	enum class DamType
	{
		none, cutting, stabbing, bashing, fire, water, earth, air, poison, lightning, sonic
	};
	struct DamageType
	{
		DamType type;
		std::string name;
		int power;
		int resist;
	};

	enum class EquipLocation
	{
		head, neck, body, arms, hands, waist, legs, feet, mainHand, offHand
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
		std::string _school;
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
		DamageType _lightning;
		DamageType _sonic;

		std::vector<Item> _inventory;

	public:
		Creature()
			: _name(""), _gender(""), _race(""), _school(""), _shortDesc(""), _longDesc(""),
			_level(0), _experience(0), _gold(0), _silver(0), _copper(0),
			_health({ "Health", 0, 0 }), _spirit({ "Spirit", 0, 0 }), _stamina({ "Stamina", 0, 0 }),
			_strength(0), _agility(0), _fortitude(0), _intellect(0), _wisdom(0),
			_armor(0), _accuracy(0), _evasion(0), _magic(0),
			_cutting({ DamType::cutting, "Cutting", 0, 0 }),
			_stabbing({ DamType::stabbing, "Stabbing", 0, 0 }),
			_bashing({ DamType::bashing, "Bashing", 0, 0 }),
			_fire({ DamType::fire, "Fire", 0, 0 }),
			_water({ DamType::water, "Water", 0,0 }),
			_earth({ DamType::earth, "Earth", 0,0 }),
			_air({ DamType::air, "Air", 0,0 }),
			_poison({ DamType::poison, "Poison", 0,0 }),
			_lightning({ DamType::lightning, "Lightning", 0,0 }),
			_sonic({ DamType::sonic, "Sonic", 0,0 })
		{};

		Creature(std::string name)
			: _name(name), _gender(""), _race(""), _school(""), _shortDesc(""), _longDesc(""),
			_level(0), _experience(0), _gold(0), _silver(0), _copper(0),
			_health({ "Health", 0, 0 }), _spirit({ "Spirit", 0, 0 }), _stamina({ "Stamina", 0, 0 }),
			_strength(0), _agility(0), _fortitude(0), _intellect(0), _wisdom(0),
			_armor(0), _accuracy(0), _evasion(0), _magic(0),
			_cutting({ DamType::cutting, "Cutting", 0, 0 }),
			_stabbing({ DamType::stabbing, "Stabbing", 0, 0 }),
			_bashing({ DamType::bashing, "Bashing", 0, 0 }),
			_fire({ DamType::fire, "Fire", 0, 0 }),
			_water({ DamType::water, "Water", 0,0 }),
			_earth({ DamType::earth, "Earth", 0,0 }),
			_air({ DamType::air, "Air", 0,0 }),
			_poison({ DamType::poison, "Poison", 0,0 }),
			_lightning({ DamType::lightning, "Lightning", 0,0 }),
			_sonic({ DamType::sonic, "Sonic", 0,0 })
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
		std::string GetSchool() { return _school; }
		void SetSchool(School school)
		{
			switch (school) {
			case School::Fighter: _school = "Fighter";
				break;
			case School::Rogue: _school = "Rogue";
				break;
			case School::Wizard: _school = "Wizard";
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
		std::string ShowHealth() { return std::format("Health: {}/{}", GetCurHealth(), GetMaxHealth()); }
		std::string ShowSpirit() { return std::format("Spirit: {}/{}", GetCurSpirit(), GetMaxSpirit()); }
		std::string ShowStamina() { return std::format("Stamina: {}/{}", GetCurStamina(), GetMaxStamina()); }

		int GetStrength() { return _strength; }
		void SetStrength(int strength) { _strength = strength; }
		int GetAgility() { return _agility; }
		void SetAgility(int agility) { _agility = agility; }
		int GetFortitude() { return _fortitude; }
		void SetFortitude(int fortitude) { _fortitude = fortitude; }
		int GetIntellect() { return _intellect; }
		void SetIntellect(int intellect) { _intellect = intellect; }
		int GetWisdom() { return _wisdom; }
		void SetWisdom(int wisdom) { _wisdom = wisdom; }

		std::vector<Item> GetInventory() { return _inventory; }
		void AddItem(Item item) { _inventory.emplace_back(item); }
		bool CheckItem(Item item) 
		{
			for (Item i : _inventory)
				if (i.getName() == item.getName())
					return true;
			return false;
		}
		//void RemoveItem(Item item) { _inventory.erase(item); }
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
		};
		PC(std::string name)
		{
			init(name);
		};

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

		int getHealth(void) { return _health.current; }
		void setHealth(int health) { _health.current = health; }
		void gainHealth(int health) { _health.current += health; if (_health.current > _health.max) _health.current = _health.max; }
		void loseHealth(int health) { _health.current -= health; if (_health.current < 0) _health.current = 0; }

		int getHealthMax(void) { return _health.max; }
		void setHealthMax(int health) { _health.max = health; }
		void gainHealthMax(int health) { _health.max += health; }
		void loseHealthMax(int health) { if (_health.max - health > 0) _health.max -= health; }

		int getSpirit(void) { return _spirit.current; }
		void setSpirit(int spirit) { _spirit.current = spirit; }
		void gainSpirit(int spirit) { _spirit.current += spirit; if (_spirit.current > _spirit.max) _spirit.current = _spirit.max; }
		void loseSpirit(int spirit) { _spirit.current -= spirit; if (_spirit.current < 0) _spirit.current = 0; }

		int getSpiritMax(void) { return _spirit.max; }
		void setSpiritMax(int spirit) { _spirit.max = spirit; }
		void gainSpiritMax(int spirit) { _spirit.max += spirit; }
		void loseSpiritMax(int spirit) { if (_spirit.max - spirit > 0) _spirit.max -= spirit; }

		int getStamina(void) { return _stamina.current; }
		void setStamina(int stamina) { _stamina.current = stamina; }
		void gainStamina(int stamina) { _stamina.current += stamina; if (_stamina.current > _stamina.max) _stamina.current = _stamina.max; }
		void loseStamina(int stamina) { _stamina.current -= stamina; if (_stamina.current < 0) _stamina.current = 0; }

		int getStaminaMax(void) { return _stamina.max; }
		void setStaminaMax(int stamina) { _stamina.max = stamina; }
		void gainStaminaMax(int stamina) { _stamina.max += stamina; }
		void loseStaminaMax(int stamina) { if (_stamina.max - stamina > 0) _stamina.max -= stamina; }

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
			init(0, { 0, Dice::d0 }, { DamType::none, "none", 0, 0}, 0, {0, Dice::d0});
		}
		Beast(std::string name)
			: MOB(name)
		{
			init(0, { 0, Dice::d0 }, { DamType::none, "none", 0 , 0}, 0, { 0, Dice::d0 });
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
