#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include "../support/Console.h"
#include "../support/Internals.h"
#include "../support/Locals.h"

namespace Items
{
	enum class ItemType : int {
		weapon, armor, shield, potion, gear, misc
	};

	class Item
	{
	protected:
		std::string _name;
		std::string _shortDesc;
		std::string _longDesc;
		int _value;
		ItemType _type;

		void baseinit(std::string name, int value, ItemType type);

	public:
		Item() 
		{
			baseinit("", 0, ItemType::misc);
		}
		Item(ItemType type)
		{
			baseinit("", 0, type);
		}
		Item(std::string name, int value, ItemType type)
		{
			baseinit(name, value, type);
		}

		// Gets & Sets
		std::string getName();
		void setName(std::string name);
		std::string getShortDesc();
		void setShortDesc(std::string desc);
		std::string getLongDesc();
		void setLongDesc(std::string desc);
		int getValue();
		void setValue(int value);
		ItemType getType();
		std::string getTypeString();
		void setType(ItemType type);
		void printBrief();
	};

	class Weapon : public Item
	{
	private:
		bool _masterwork;
		int _speed;
		int _accuracy;
		int _cutting;
		int _stabbing;
		int _smashing;
		std::tuple<int, Dice::die> _damage;
		int _penalty;

		void init(bool masterwork, int speed, int accuracy,
			int cutting, int stabbing, int smashing,
			std::tuple<int, Dice::die> damage, int penalty);

	public:
		Weapon() 
			: Item(ItemType::weapon)
		{
			init(false, 0, 0, 0, 0, 0, { 0, Dice::d0 }, 0);
		}
		Weapon(std::string name, int value) 
			: Item(name, value, ItemType::weapon)
		{
			init(false, 0, 0, 0, 0, 0, { 0, Dice::d0 }, 0);
		}
		Weapon(std::string name, int value, ItemType type)
			: Item(name, value, type)
		{
			init(false, 0, 0, 0, 0, 0, { 0, Dice::d0 }, 0);
		}
		Weapon(std::string name, int value, ItemType type,
			bool masterwork, int speed, int accuracy,
			int cutting, int stabbing, int smashing,
			std::tuple<int, Dice::die> damage, int penalty)
			: Item(name, value, type)
		{
			init(masterwork, speed, accuracy, cutting, stabbing,
				smashing, damage, penalty);
		}

		// Gets & Sets
		bool getMasterwork();
		void setMasterwork(bool b);
		int getSpeed();
		void setSpeed(int speed);
		int getAccuracy();
		void setAccuracy(int accuracy);
		int getCutting();
		void setCutting(int cutting);
		int getStabbing();
		void setStabbing(int stabbing);
		int getSmashing();
		void setSmashing(int smashing);
		std::tuple<int, int> getDamage();
		void setDamage(int damage, Dice::die dice);
		int rollDamage();
		int getPenalty();
		void setPenalty(int penalty);
	};

	class Armor : public Item
	{
	private:
		std::string _description;
		bool _masterwork;
		int _health;
		int _hardness;
		int _cutting;
		int _stabbing;
		int _smashing;
		int _penalty;

		void init(bool masterwork, int health, int hardness, int cutting, int stabbing,
			int smashing, int penalty);

	public:
		Armor() 
			: Item(ItemType::armor)
		{
			init(false, 0, 0, 0, 0, 0, 0);
		}
		Armor(std::string name, int value) 
			: Item(name, value, ItemType::armor)
		{
			init(false, 0, 0, 0, 0, 0, 0);
		}
		Armor(std::string name, int value, ItemType type) 
			: Item(name, value, type)
		{
			init(false, 0, 0, 0, 0, 0, 0);
		}
		Armor(std::string name, int value, ItemType type,
			bool masterwork, int health, int hardness,
			int cutting, int stabbing, int smashing, int penalty)
			: Item(name, value, type)
		{
			init(masterwork, health, hardness, cutting, stabbing, smashing, penalty);
		}

		// Gets & Sets
		bool getMasterwork();
		void setMasterwork(bool b);
		int getHealth();
		void setHealth(int health);
		int getHardness();
		void setHardness(int hardness);
		int getCutting();
		void setCutting(int cutting);
		int getStabbing();
		void setStabing(int stabbing);
		int getSmashing();
		void setSmashing(int smashing);
		int getPenalty();
		void setPenalty(int penalty);
	};

	class Shield : public Item
	{
	private:
		std::string _description;
		bool _masterwork;
		int _defense;
		int _cutting;
		int _stabbing;
		int _smashing;
		int _penalty;

		void init(bool masterwork, int defense, int cutting, int stabbing, int smashing, int penalty);

	public:
		Shield() 
			: Item(ItemType::armor)
		{
			init(false, 0, 0, 0, 0, 0);
		}
		Shield(std::string name, int value) 
			: Item(name, value, ItemType::armor)
		{
			init(false, 0, 0, 0, 0, 0);
		}
		Shield(std::string name, int value, ItemType type) 
			: Item(name, value, type)
		{
			init(false, 0, 0, 0, 0, 0);
		}
		Shield(std::string name, int value, ItemType type,
			bool masterwork, int defense, int cutting, int stabbing,
			int smashing, int penalty)
			: Item(name, value, type)
		{
			init(masterwork, defense, cutting, stabbing, smashing, penalty);
		}

		// Gets & Sets
		bool getMasterwork();
		void setMasterwork(bool b);
		int getDefense();
		void setDefense(int defense);
		int getCutting();
		void setCutting(int cutting);
		int getStabbing();
		void setStabbing(int stabbing);
		int getSmashing();
		void setSmashing(int smashing);
		int getPenalty();
		void setPenalty(int penalty);
	};

	class Potion : public Item
	{
	private:
		std::tuple<int, Dice::die> _power;
		//	std::function<void(Creatures::Creature)> _action;
		//	std::function<void(Creatures::Creature)> _consume;
		//	std::function<void(Creatures::Creature)> _throw;

		void init(std::tuple<int, Dice::die> power);

	public:
		Potion()
			: Item(ItemType::potion)
		{
			init({ 0, Dice::d0 });
			//_action = {};
		}
		Potion(std::string name, int value)
			: Item(name, value, ItemType::potion)
		{
			init({ 0, Dice::d0 });
			//_action = {};
		}
		Potion(std::string name, int value, std::tuple<int, Dice::die> power)
			: Item(name, value, ItemType::potion)
		{
			init(power);
			//_action = {};
		}
		//Potion(std::string name, int value, std::function<void(Creatures::Creature)> action) 
		//	: Equipment(name, value, ItemType::potion)
		//{
		//	_description = "";
		//	_action = action;
		//	_power = { 0, 0 };
		//}
		//Potion(std::string name, int value, std::tuple<int, int> power, std::function<void(Creatures::Creature)> action) 
		//	: Equipment(name, value, ItemType::potion)
		//{
		//	_description = "";
		//	_action = action;
		//	_power = power;
		//}
		//Potion(std::string name, int value, std::string description, std::tuple<int, int> power, std::function<void(Creatures::Creature)> action) 
		//	: Equipment(name, value, ItemType::potion)
		//{
		//	_description = description;
		//	_action = action;
		//	_power = power;
		//}

		// Gets & Sets
		std::tuple<int, Dice::die> getPower();
		void setPower(std::tuple<int, Dice::die> power);
		int rollPower();
	};

	class Gear : public Item
	{
	private:
		void init();
	public:
		Gear()
			: Item(ItemType::gear)
		{
			init();
		}
		Gear(std::string name, int value)
			: Item(name, value, ItemType::gear)
		{
			init();
		}

		// Gets & Sets
	};
}
