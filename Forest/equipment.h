#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include "support/Console.h"
#include "support/Internals.h"
#include "support/Locals.h"

class Equipment
{
public:
	enum class EquipType : int {
		weapon, armor, potion, gear, misc
	};

protected:
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
	Equipment(EquipType type)
	{
		_name = "";
		_value = 0;
		_type = type;
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

class Weapon : public Equipment
{
private:
	std::string _description;
	bool _masterwork;
	int _speed;
	int _cutting;
	int _stabbing;
	int _smashing;
	int _accuracy;
	std::tuple<int, int> _damage;
	int _penalty;

public:
	Weapon() : Equipment(EquipType::weapon)
	{
		_description = "";
		_masterwork = false;
		_speed = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_accuracy = 0;
		_damage = { 0, 0 };
		_penalty = 0;
	}
	Weapon(std::string name, int value) : Equipment(name, value, EquipType::weapon)
	{
		_description = "";
		_masterwork = false;
		_speed = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_accuracy = 0;
		_damage = { 0, 0 };
		_penalty = 0;
	}
	Weapon(std::string name, int value, EquipType type) : Equipment(name, value, type)
	{
		_description = "";
		_masterwork = false;
		_speed = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_accuracy = 0;
		_damage = { 0, 0 };
		_penalty = 0;
	}

	// Gets and Sets
	bool getMasterwork() { return _masterwork; }
	void setMasterwork(bool b) { _masterwork = b; }
	int getSpeed() { return _speed; }
	void setSpeed(int speed) { _speed = speed; }
	int getCutting() { return _cutting; }
	void setCutting(int cutting) { _cutting = cutting; }
	int getStabbing() { return _stabbing; }
	void setStabbing(int stabbing) { _stabbing = stabbing; }
	int getSmashing() { return _smashing; }
	void setSmashing(int smashing) { _smashing = smashing; }
	int getAccuracy() { return _accuracy; }
	void setAccuracy(int accuracy) { _accuracy = accuracy; }
	std::tuple<int, int> getDamage() { return _damage; }
	void setDamage(int damage, int dice) { _damage = { damage, dice }; }
	int getPenalty() { return _penalty; }
	void setPenalty(int penalty) { _penalty = penalty; }
};

class Armor : public Equipment
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

public:
	Armor() : Equipment(EquipType::armor)
	{
		_description = "";
		_masterwork = false;
		_health = 0;
		_hardness = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}
	Armor(std::string name, int value) : Equipment(name, value, EquipType::armor)
	{
		_description = "";
		_masterwork = false;
		_health = 0;
		_hardness = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}
	Armor(std::string name, int value, EquipType type) : Equipment(name, value, type)
	{
		_description = "";
		_masterwork = false;
		_health = 0;
		_hardness = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}

	// Gets and Sets
	bool getMasterwork() { return _masterwork; }
	void setMasterwork(bool b) { _masterwork = b; }
	int getHealth() { return _health; }
	void setHealth(int health) { _health = health; }
	int getHardness() { return _hardness; }
	void setHardness(int hardness) { _hardness = hardness; }
	int getCutting() { return _cutting; }
	void setCutting(int cutting) { _cutting = cutting; }
	int getStabbing() { return _stabbing; }
	void setStabing(int stabbing) { _stabbing = stabbing; }
	int getSmashing() { return _smashing; }
	void setSmashing(int smashing) { _smashing = smashing; }
	int getPenalty() { return _penalty; }
	void setPenalty(int penalty) { _penalty = penalty; }
};

class Shield : public Equipment
{
private:
	std::string _description;
	bool _masterwork;
	int _defense;
	int _cutting;
	int _stabbing;
	int _smashing;
	int _penalty;

public:
	Shield() : Equipment(EquipType::armor)
	{
		_description = "";
		_masterwork = false;
		_defense = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}
	Shield(std::string name, int value) : Equipment(name, value, EquipType::armor)
	{
		_description = "";
		_masterwork = false;
		_defense = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}
	Shield(std::string name, int value, EquipType type) : Equipment(name, value, type)
	{
		_description = "";
		_masterwork = false;
		_defense = 0;
		_cutting = 0;
		_stabbing = 0;
		_smashing = 0;
		_penalty = 0;
	}
	// Gets and Sets
	bool getMasterwork() { return _masterwork; }
	void setMasterwork(bool b) { _masterwork = b; }
	int getDefense() { return _defense; }
	void setDefense(int defense) { _defense = defense; }
	int getCutting() { return _cutting; }
	void setCutting(int cutting) { _cutting = cutting; }
	int getStabbing() { return _stabbing; }
	void setStabbing(int stabbing) { _stabbing = stabbing; }
	int getSmashing() { return _smashing; }
	void setSmashing(int smashing) { _smashing = smashing; }
	int getPenalty() { return _penalty; }
	void setPenalty(int penalty) { _penalty = penalty; }
};



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
