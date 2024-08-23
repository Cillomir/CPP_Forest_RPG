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

	enum class DamType
	{
		none, cutting, stabbing, bashing, fire, water, earth, air, poison, lightning, sonic
	};
	struct DamageType
	{
		DamType type;
		std::string name;
		int power, resist;
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

	struct StatPoints
	{
		std::string name;
		int current, max;
		float GetPercent() {
			return ((float)current / (float)max) * 100;
		}
		std::string GetString() {
			return std::format("{}: {}/{}", name, current, max);
		}
	};

	class Creature
	{
	protected:
		// General
		std::string _name;
		std::string _gender, _race, _school;
		std::string _shortDesc, _longDesc;

		int _level, _experience;
		int _gold, _silver, _copper;

		// Stats
		StatPoints _health, _spirit, _stamina;
		int _strength, _agility, _fortitude, _intellect, _wisdom;
		int _armor, _accuracy, _evasion, _magic;

		DamageType _cutting, _stabbing, _bashing;
		DamageType _fire, _water, _earth, _air;
		DamageType _poison, _lightning, _sonic;

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

		int GetArmor() { return _armor; }
		void SetArmor(int armor) { _armor = armor; }
		int GetAccuracy() { return _accuracy; }
		void SetAccuracy(int accuracy) { _accuracy = accuracy; }
		int GetEvasion() { return _evasion; }
		void SetEvasion(int evasion) { _evasion = evasion; }
		int GetMagic() { return _magic; }
		void SetMagic(int magic) { _magic = magic; }

		int GetCuttingPower() { return _cutting.power; }
		int GetCuttingResist() { return _cutting.resist; }
		int GetStabbingPower() { return _stabbing.power; }
		int GetStabbingResist() { return _stabbing.resist; }
		int GetBashingPower() { return _bashing.power; }
		int GetBashingResist() { return _bashing.resist; }
		int GetFirePower() { return _fire.power; }
		int GetFireResist() { return _fire.resist; }
		int GetWaterPower() { return _water.power; }
		int GetWaterResist() { return _water.resist; }
		int GetEarthPower() { return _earth.power; }
		int GetEarthResist() { return _earth.resist; }
		int GetAirPower() { return _air.power; }
		int GetAirResist() { return _air.resist; }
		int GetPoisonPower() { return _poison.power; }
		int GetPoisonResist() { return _poison.resist; }
		int GetLightningPower() { return _lightning.power; }
		int GetLightningResist() { return _lightning.resist; }
		int GetSonicPower() { return _sonic.power; }
		int GetSonicResist() { return _sonic.resist; }

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
#ifndef PLAYER_H
#include "Player.h"
#endif
#endif
