#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "../config.h"
#include "Creatures.h"


namespace Creatures
{
	class PC : public Creature
	{
	private:
		// Constants
		const std::vector<int> expNeeded = { 0, 100, 200, 400, 800, 1500, 2500, 4000, 6500, 10000, 15000 };

		// General
		std::string _title;

		// Equipment
		std::map<EquipLocation, Item> _equipment;

		int _trainingPoints;
		int _skillPoints;

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
				_gender = obj._gender;
				_race = obj._race;
				_school = obj._school;
				_shortDesc = obj._shortDesc;
				_longDesc = obj._longDesc;
				_title = obj._title;
				_level = obj._level;
				_experience = obj._experience;
				_gold = obj._gold;
				_silver = obj._silver;
				_copper = obj._copper;
				_health = obj._health;
				_spirit = obj._spirit;
				_stamina = obj._stamina;
				_strength = obj._strength;
				_agility = obj._agility;
				_fortitude = obj._fortitude;
				_intellect = obj._intellect;
				_wisdom = obj._wisdom;
				_luck = obj._luck;
				_armor = obj._armor;
				_accuracy = obj._accuracy;
				_evasion = obj._evasion;
				_magic = obj._magic;
				_cutting = obj._cutting;
				_stabbing = obj._stabbing;
				_bashing = obj._bashing;
				_fire = obj._fire;
				_water = obj._water;
				_earth = obj._earth;
				_air = obj._air;
				_poison = obj._poison;
				_lightning = obj._lightning;
				_sonic = obj._sonic;
				_trainingPoints = obj._trainingPoints;
				_skillPoints = obj._skillPoints;
				_inventory = obj._inventory;

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
		void gainLevel(void) { if (_level < config::maxLevel) _level++; _experience = 0; }
		void loseLevel(void) { if (_level > config::minLevel) _level--; _experience = 0; }

		int getExp(void) { return _experience; }
		int gainExp(int exp) { if (_experience + exp < expNeeded[getLevel()]) _experience += exp; else gainLevel(); }

		int getGold(void) { return _gold; }
		void setGold(int gold) { _gold = gold; }
		void gainGold(int gold) { if (_gold + gold < config::maxGold) _gold += gold; }
		void loseGold(int gold) { if (_gold - gold > config::minGold) _gold -= gold; }

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

		int GetTrainingPoints(void) { return _trainingPoints; }
		void SetTrainingPoints(int points) { _trainingPoints = points; }

		int GetSkillPoints(void) { return _skillPoints; }
		void SetSkillPoints(int points) { _skillPoints = points; }

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

		static void createNew(PC &player);

		static void save();
		static void load();
	};
	static PC player;
}

#endif
