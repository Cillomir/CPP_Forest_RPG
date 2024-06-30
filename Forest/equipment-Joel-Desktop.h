#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "internals.h"

enum equipType : int {
	weapon, armor, potion, gear, misc
};

class equip
{
private:
	std::string _name;
	int _value;
	equipType _type;

	static std::vector<equip> _allequips;
	static std::vector<equip> _allWeapons;
	static std::vector<equip> _allArmors;
	static std::vector<equip> _allPotions;
	static std::vector<equip> _allGear;
	static std::vector<equip> _allMisc;

	static void sortEquipment(void)
	{
		std::sort(_allWeapons.begin(), _allWeapons.end(), [](equip a, equip b) {return a._name < b._name; });
		std::sort(_allArmors.begin(), _allArmors.end(), [](equip a, equip b) {return a._name < b._name; });
		std::sort(_allPotions.begin(), _allPotions.end(), [](equip a, equip b) {return a._name < b._name; });
		std::sort(_allGear.begin(), _allGear.end(), [](equip a, equip b) {return a._name < b._name; });
		std::sort(_allMisc.begin(), _allMisc.end(), [](equip a, equip b) {return a._name < b._name; });
		_allequips.clear();
		_allequips.emplace_back(_allWeapons);
		_allequips.emplace_back(_allArmors);
		_allequips.emplace_back(_allPotions);
		_allequips.emplace_back(_allGear);
		_allequips.emplace_back(_allMisc);
	}

public:
	static void init(void);
	static std::vector<equip> allequips()
	{
		return equip::_allequips;
	};
	static std::vector<equip> allWeapons()
	{
		return equip::_allWeapons;
	}
	static std::vector<equip> allArmors()
	{
		return equip::_allArmors;
	}
	static std::vector<equip> allPotions()
	{
		return equip::_allPotions;
	}
	static std::vector<equip> allGear()
	{
		return equip::_allGear;
	}
	static std::vector<equip> allMisc()
	{
		return equip::_allMisc;
	}

	equip() {};

	equip(std::string name, int value, equipType type) {
		_name = name;
		_value = value;
		_type = type;
		_allequips.emplace_back(this);

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
	}

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
	}

};

static bool initComplete = false;
static void init(void) {
	if (!initComplete) {
		equip t;
		t = equip("Fists", 0, equipType::misc);
		t = equip("Dagger", 0, equipType::weapon);
		t = equip("Iron Shortsword", 0, equipType::weapon);
		t = equip("Iron Longsword", 0, equipType::weapon);
		t = equip("Steel Shortsword", 0, equipType::weapon);
		t = equip("Steel Longsword", 0, equipType::weapon);
		t = equip("Tunic", 0, equipType::armor);
		t = equip("Leather", 0, equipType::armor);
		t = equip("Hide", 0, equipType::armor);
		t = equip("Chainmail", 0, equipType::armor);
		t = equip("Scalemail", 0, equipType::armor);
		t = equip("Half-Plate", 0, equipType::armor);
		t = equip("Plate", 0, equipType::armor);
		t = equip("Health", 0, equipType::potion);
		t = equip("Spirit", 0, equipType::potion);
		t = equip("Stamina", 0, equipType::potion);
		initComplete = true;
	}
}



