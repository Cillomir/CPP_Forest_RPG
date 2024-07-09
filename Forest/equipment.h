#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include "support/Console.h"
//#include "internals.h"

class Equipment
{
public:
	enum class EquipType : int {
		weapon, armor, potion, gear, misc
	};

private:
	std::string _name;
	int _value;
	EquipType _type;

public:
	Equipment()
	{
		_name = "";
		_value = 0;
		_type = EquipType::misc;
	}
	Equipment(std::string name, int value, EquipType type)
	{
		_name = name;
		_value = value;
		_type = type;
	}

	std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
	int getValue() { return _value; }
	void setValue(int value) { _value = value; }
	std::string getType()
	{
		switch (_type)
		{
		case EquipType::weapon: return "weapon";
			break;
		case EquipType::armor: return "armor";
			break;
		case EquipType::potion: return "potion";
			break;
		case EquipType::gear: return "gear";
			break;
		case EquipType::misc: return "miscellaneous";
			break;
		};
	}
	void setType(EquipType type) { _type = type; }
	void description()
	{
		std::cout << _name;
		switch (_type)
		{
		case EquipType::weapon: std::cout << ": a weapon.";
			break;
		case EquipType::armor: std::cout << ": an armor.";
			break;
		case EquipType::potion: std::cout << ": a potion.";
			break;
		case EquipType::gear: std::cout << ": a type of gear.";
			break;
		case EquipType::misc: std::cout << ": an item.";
			break;
		};
		std::cout << std::endl;
	}
};

//class Weapon : public Equipment
//{
//private:
//	//std::string name;
//	std::string _description;
//	//int value;
//	bool _masterwork;
//	int _cutting;
//	int _piercing;
//	int _smashing;
//	int _accuracy;
//	std::tuple<int, int> _damage;
//
//public:
//	Weapon()
//	{
//		_name = "";
//		_description = "";
//		_value = 0;
//		_type = EquipType::weapon;
//		_masterwork = false;
//		_cutting = 0;
//		_piercing = 0;
//		_smashing = 0;
//		_accuracy = 0;
//		_damage = { 0, 0 };
//	}
//};
//
//class Armor : public Equipment
//{
//private:
//	//std::string name;
//	std::string _description;
//	//int value;
//	bool _masterwork;
//	int _hardness;
//	int _cutting;
//	int _piercing;
//	int _smashing;
//	int _health;
//
//public:
//	Armor()
//	{
//		_name = "";
//		_description = "";
//		_value = 0;
//		_type = EquipType::armor;
//		_masterwork = false;
//		_hardness = 0;
//		_cutting = 0;
//		_piercing = 0;
//		_smashing = 0;
//		_health = 0;
//	}
//};


//	Item() {};
//
//	Item(std::string name, int value, ItemType type) {
//		_name = name;
//		_value = value;
//		_type = type;
//		_allEquipment.emplace_back(this);
//
//		switch (_type) {
//		case weapon:
//			_allWeapons.emplace_back(this);
//			break;
//		case armor:
//			_allArmors.emplace_back(this);
//			break;
//		case potion:
//			_allPotions.emplace_back(this);
//			break;
//		case gear:
//			_allGear.emplace_back(this);
//			break;
//		case misc:
//			_allMisc.emplace_back(this);
//			break;
//		}
//	};
//
//	std::string name() { return _name; }
//	int value() { return _value; }
//	std::string type() {
//		switch (_type) {
//		case weapon: return "weapon";
//			break;
//		case armor: return "armor";
//			break;
//		case potion: return "potion";
//			break;
//		case gear: return "gear";
//			break;
//		case misc: return "miscellaneous";
//			break;
//		};
//	};
//private:
//	std::string _name;
//	int _value;
//	ItemType _type;
//};

//	static void init(void);

//static bool initComplete = false;
//static void init(void) {
//	if (!initComplete) {
//		equip t;
//		t = equip("Fists", 0, equipType::misc);
//		t = equip("Dagger", 0, equipType::weapon);
//		t = equip("Iron Shortsword", 0, equipType::weapon);
//		t = equip("Iron Longsword", 0, equipType::weapon);
//		t = equip("Steel Shortsword", 0, equipType::weapon);
//		t = equip("Steel Longsword", 0, equipType::weapon);
//		t = equip("Tunic", 0, equipType::armor);
//		t = equip("Leather", 0, equipType::armor);
//		t = equip("Hide", 0, equipType::armor);
//		t = equip("Chainmail", 0, equipType::armor);
//		t = equip("Scalemail", 0, equipType::armor);
//		t = equip("Half-Plate", 0, equipType::armor);
//		t = equip("Plate", 0, equipType::armor);
//		t = equip("Health", 0, equipType::potion);
//		t = equip("Spirit", 0, equipType::potion);
//		t = equip("Stamina", 0, equipType::potion);
//		initComplete = true;
//	};
//};
