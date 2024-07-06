#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "console.h"
//#include "internals.h"

enum class equipType : int {
	weapon, armor, potion, gear, misc
};

class equipment
{
private:
	std::string _name;
	int _value;
	equipType _type;

//	static std::vector<equip> _allEquipment;
//	static std::vector<equip> _allWeapons;
//	static std::vector<equip> _allArmors;
//	static std::vector<equip> _allPotions;
//	static std::vector<equip> _allGear;
//	static std::vector<equip> _allMisc;
//
//	static void sortEquipment(void)
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
//
public:
//	static void init(void);
//	static std::vector<equip> allEquip()
//	{
//		return equip::_allEquipment;
//	};
//	static std::vector<equip> allWeapons()
//	{
//		return equip::_allWeapons;
//	}
//	static std::vector<equip> allArmors()
//	{
//		return equip::_allArmors;
//	}
//	static std::vector<equip> allPotions()
//	{
//		return equip::_allPotions;
//	}
//	static std::vector<equip> allGear()
//	{
//		return equip::_allGear;
//	}
//	static std::vector<equip> allMisc()
//	{
//		return equip::_allMisc;
//	}
//
	equipment() {};

	equipment(std::string name, int value, equipType type) {
		_name = name;
		_value = value;
		_type = type;
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
		}
	};
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
//};
//
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
class Weapon : Equipment
{
private:
	std::string name;
	std::string description;
	int value;
	bool masterwork;
	int cutting;
	int piercing;
	int smashing;
	int accuracy;
	std::tuple<int, int> damage;

public:
	Weapon()
	{
		name = "";
		description = "";
		cutting = 0;
		piercing = 0;
		smashing = 0;
		accuracy = 0;
		damage = { 0, 0 };
	}
};

class Armor : Equipment
{
private:
	std::string name;
	std::string description;
	int value;
	bool masterwork;
	int hardness;
	int cutting;
	int piercing;
	int smashing;
	int health;

public:
	Armor()
	{
		name = "";
		description = "";
		value = 0;
		masterwork = false;
		hardness = 0;
		cutting = 0;
		piercing = 0;
		smashing = 0;
		health = 0;
	}
};

/*
#pragma region Equipment
enum ItemType : int { weapon = 1, armor, potion, gear, misc };

class Item
{
public:
	//static void init(void);
	static std::vector<Item> allEquip()
	{
		return Item::_allEquipment;
	};
	static std::vector<Item> allWeapons()
	{
		return Item::_allWeapons;
	}
	static std::vector<Item> allArmors()
	{
		return Item::_allArmors;
	}
	static std::vector<Item> allPotions()
	{
		return Item::_allPotions;
	}
	static std::vector<Item> allGear()
	{
		return Item::_allGear;
	}
	static std::vector<Item> allMisc()
	{
		return Item::_allMisc;
	}

//	Item() {};

	Item(std::string name, int value, ItemType type) {
		_name = name;
		_value = value;
		_type = type;
		_allEquipment.emplace_back(this);

		switch (_type) {
		case weapon:
			_allWeapons.emplace_back(this);
			break;
		case armor:
			_allArmors.emplace_back(this);
			break;
		case potion:
			_allPotions.emplace_back(this);
			break;
		case gear:
			_allGear.emplace_back(this);
			break;
		case misc:
			_allMisc.emplace_back(this);
			break;
		}
	};

	std::string name() { return _name; }
	int value() { return _value; }
	std::string type() {
		switch (_type) {
		case weapon: return "weapon";
			break;
		case armor: return "armor";
			break;
		case potion: return "potion";
			break;
		case gear: return "gear";
			break;
		case misc: return "miscellaneous";
			break;
		};
	};
private:
	std::string _name;
	int _value;
	ItemType _type;

	static std::vector<Item> _allEquipment;
	static std::vector<Item> _allWeapons;
	static std::vector<Item> _allArmors;
	static std::vector<Item> _allPotions;
	static std::vector<Item> _allGear;
	static std::vector<Item> _allMisc;

	//static void sortEquipment(void)
	//{
	//	std::sort(_allWeapons.begin(), _allWeapons.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allArmors.begin(), _allArmors.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allPotions.begin(), _allPotions.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allGear.begin(), _allGear.end(), [](Item a, Item b) {return a._name < b._name; });
	//	std::sort(_allMisc.begin(), _allMisc.end(), [](Item a, Item b) {return a._name < b._name; });
	//	_allEquipment.clear();
	//	_allEquipment.emplace_back(_allWeapons);
	//	_allEquipment.emplace_back(_allArmors);
	//	_allEquipment.emplace_back(_allPotions);
	//	_allEquipment.emplace_back(_allGear);
	//	_allEquipment.emplace_back(_allMisc);
	//}
};

//static bool initComplete = false;
//static void init(void) {
//	if (!initComplete) {
//		Item t;
//		t = Item("Fists", 0, ItemType::misc);
//		t = Item("Dagger", 0, ItemType::weapon);
//		t = Item("Iron Shortsword", 0, ItemType::weapon);
//		t = Item("Iron Longsword", 0, ItemType::weapon);
//		t = Item("Steel Shortsword", 0, ItemType::weapon);
//		t = Item("Steel Longsword", 0, ItemType::weapon);
//		t = Item("Tunic", 0, ItemType::armor);
//		t = Item("Leather", 0, ItemType::armor);
//		t = Item("Hide", 0, ItemType::armor);
//		t = Item("Chainmail", 0, ItemType::armor);
//		t = Item("Scalemail", 0, ItemType::armor);
//		t = Item("Half-Plate", 0, ItemType::armor);
//		t = Item("Plate", 0, ItemType::armor);
//		t = Item("Health", 0, ItemType::potion);
//		t = Item("Spirit", 0, ItemType::potion);
//		t = Item("Stamina", 0, ItemType::potion);
//		initComplete = true;
//	}
//}
#pragma endregion
*/
