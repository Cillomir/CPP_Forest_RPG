#pragma once
#include "Items.h"
using namespace Items;

#pragma region R_Item
void Item::baseinit(std::string name, int value, ItemType type)
{
	_name = name;
	_shortDesc = "";
	_longDesc = "";
	_value = value;
	_type = type;
}
std::string Item::getName() 
{ 
	return _name;
}
void Item::setName(std::string name) 
{
	_name = name;
}
std::string Item::getShortDesc()
{
	return _shortDesc;
}
void Item::setShortDesc(std::string desc)
{
	_shortDesc = desc;
}
std::string Item::getLongDesc()
{
	return _longDesc;
}
void Item::setLongDesc(std::string desc)
{
	_longDesc = desc;
}
int Item::getValue() 
{ 
	return _value; 
}
void Item::setValue(int value)
{ 
	_value = value;
}
ItemType Item::getType()
{
	return _type;
}
std::string Item::getTypeString()
{
	switch (_type)
	{
	case ItemType::weapon: return "weapon";
		break;
	case ItemType::armor: return "armor";
		break;
	case ItemType::shield: return "shield";
		break;
	case ItemType::potion: return "potion";
		break;
	case ItemType::gear: return "gear";
		break;
	case ItemType::misc: return "miscellaneous";
		break;
	default: return "";
	};
}
void Item::setType(ItemType type)
{
	_type = type; 
}
void Item::printBrief()
{
	std::cout << _name;
	switch (_type)
	{
	case ItemType::weapon: std::cout << ": a weapon.";
		break;
	case ItemType::armor: std::cout << ": an armor.";
		break;
	case ItemType::shield: std::cout << ": a shield.";
		break;
	case ItemType::potion: std::cout << ": a potion.";
		break;
	case ItemType::gear: std::cout << ": a type of gear.";
		break;
	case ItemType::misc: std::cout << ": an item.";
		break;
	};
	std::cout << std::endl;
}
#pragma endregion

#pragma region R_Weapon
void Weapon::init(bool masterwork, int speed, int accuracy,	int cutting, int stabbing, 
	int smashing, std::tuple<int, Dice::die> damage, int penalty)
{
	_masterwork = masterwork;
	_speed = speed;
	_accuracy = accuracy;
	_cutting = cutting;
	_stabbing = stabbing;
	_smashing = smashing;
	_damage = damage;
	_penalty = penalty;
}
bool Weapon::getMasterwork() 
{ 
	return _masterwork; 
}
void Weapon::setMasterwork(bool b) 
{ 
	_masterwork = b; 
}
int Weapon::getSpeed() 
{ 
	return _speed; 
}
void Weapon::setSpeed(int speed) 
{ 
	_speed = speed; 
}
int Weapon::getAccuracy() 
{ 
	return _accuracy;
}
void Weapon::setAccuracy(int accuracy) 
{ 
	_accuracy = accuracy;
}
int Weapon::getCutting() 
{ 
	return _cutting;
}
void Weapon::setCutting(int cutting) 
{ 
	_cutting = cutting;
}
int Weapon::getStabbing() 
{ 
	return _stabbing;
}
void Weapon::setStabbing(int stabbing) 
{ 
	_stabbing = stabbing;
}
int Weapon::getSmashing() 
{ 
	return _smashing;
}
void Weapon::setSmashing(int smashing) 
{ 
	_smashing = smashing;
}
std::tuple<int, int> Weapon::getDamage() 
{ 
	return _damage;
}
void Weapon::setDamage(int damage, Dice::die dice)
{ 
	_damage = { damage, dice }; 
}
int Weapon::rollDamage()
{
	int damage = 0;
	for (int i = 0; i < std::get<0>(_damage); ++i)
	{
		damage += Dice::Roll(std::get<1>(_damage));
	}
	return damage;
}
int Weapon::getPenalty() 
{ 
	return _penalty; }
void Weapon::setPenalty(int penalty) 
{ 
	_penalty = penalty;
}
#pragma endregion

#pragma region R_Armor
void Armor::init(bool masterwork, int health, int hardness, int cutting, int stabbing,
	int smashing, int penalty)
{
	_masterwork = masterwork;
	_health = health;
	_hardness = hardness;
	_cutting = cutting;
	_stabbing = stabbing;
	_smashing = smashing;
	_penalty = penalty;
}
bool Armor::getMasterwork() 
{ 
	return _masterwork; 
}
void Armor::setMasterwork(bool b) 
{
	_masterwork = b; 
}
int Armor::getHealth() 
{ 
	return _health;
}
void Armor::setHealth(int health) 
{
	_health = health;
}
int Armor::getHardness() 
{ 
	return _hardness;
}
void Armor::setHardness(int hardness) 
{ 
	_hardness = hardness; 
}
int Armor::getCutting() 
{ 
	return _cutting; 
}
void Armor::setCutting(int cutting) 
{ 
	_cutting = cutting;
}
int Armor::getStabbing() 
{ 
	return _stabbing; 
}
void Armor::setStabing(int stabbing) 
{ 
	_stabbing = stabbing; 
}
int Armor::getSmashing() 
{ 
	return _smashing; 
}
void Armor::setSmashing(int smashing) 
{ 
	_smashing = smashing;
}
int Armor::getPenalty() 
{ 
	return _penalty; 
}
void Armor::setPenalty(int penalty) 
{
	_penalty = penalty; 
}
#pragma endregion

#pragma region R_Shield
void Shield::init(bool masterwork, int defense, int cutting, int stabbing, int smashing, int penalty)
{
	_masterwork = masterwork;
	_defense = defense;
	_cutting = cutting;
	_stabbing = stabbing;
	_smashing = smashing;
	_penalty = penalty;
}
bool Shield::getMasterwork()
{ 
	return _masterwork; 
}
void Shield::setMasterwork(bool b)
{ 
	_masterwork = b; 
}
int Shield::getDefense()
{
	return _defense; 
}
void Shield::setDefense(int defense)
{
	_defense = defense; 
}
int Shield::getCutting()
{
	return _cutting; 
}
void Shield::setCutting(int cutting)
{
	_cutting = cutting; 
}
int Shield::getStabbing()
{
	return _stabbing; 
}
void Shield::setStabbing(int stabbing)
{ 
	_stabbing = stabbing; 
}
int Shield::getSmashing()
{
	return _smashing; 
}
void Shield::setSmashing(int smashing)
{ 
	_smashing = smashing; 
}
int Shield::getPenalty()
{ 
	return _penalty;
}
void Shield::setPenalty(int penalty)
{
	_penalty = penalty; 
}
#pragma endregion

#pragma region R_Potion
void Potion::init(std::tuple<int, Dice::die> power)
{
	_power = power;
}
std::tuple<int, Dice::die> Potion::getPower()
{
	return _power;
}
void Potion::setPower(std::tuple<int, Dice::die> power)
{
	_power = power;
}
int Potion::rollPower()
{
	int amount = 0;
	for (int i = 0; i < std::get<0>(_power); ++i)
	{
		amount += Dice::Roll(std::get<1>(_power));
	}
	return amount;
}
#pragma endregion

#pragma region R_Gear
void Gear::init()
{

};
#pragma endregion
