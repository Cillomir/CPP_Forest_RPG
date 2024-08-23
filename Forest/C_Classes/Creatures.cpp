#pragma once
#include "Creatures.h"
using namespace Creatures;
using namespace CSL_Color;
using namespace CSL_Console;
using namespace CSL_Cursor;
using namespace CSL_Line;

#pragma region Mobile
void MOB::baseinit(std::string name, std::string description, int level, int health)
{
	_name = name;
	_description = description;
	_level = level;
	_health = { health, health };
	_condition = Condition::healthy;
	_equipment = std::vector<Item>();
};

void MOB::calcCondition()
{
	if (std::get<0>(_health) <= 0)
	{
		std::get<0>(_health) = 0;
		_condition = Condition::dead;
	}
	float percent = (float)std::get<0>(_health) / (float)std::get<1>(_health);
	percent *= 100;
	if (percent >= 100)
		_condition = Condition::healthy;
	else if (percent >= 80)
		_condition = Condition::light_injury;
	else if (percent >= 50)
		_condition = Condition::medium_injury;
	else if (percent >= 20)
		_condition = Condition::heavy_injury;
	else if (percent > 0)
		_condition = Condition::near_death;
	else
		_condition = Condition::dead;
}
void MOB::look()
{
	std::cout << _description << std::endl;;
}
void MOB::examine()
{
	std::cout << _name << ": " << _description << std::endl;
	std::cout << "Level: " << _level << std::endl;
	std::cout << "Health: " << std::get<0>(_health) << "/" << std::get<1>(_health) << std::endl;
	for (Item e : _equipment)
	{
		e.getShortDesc();
	}
}
void MOB::hurt(int amount)
{
	std::get<0>(_health) -= amount;
	if (std::get<0>(_health) < 0)
		std::get<0>(_health) = 0;
	calcCondition();
}
void MOB::heal(int amount)
{
	std::get<0>(_health) += amount;
	if (std::get<0>(_health) > std::get<1>(_health))
		std::get<0>(_health) = std::get<1>(_health);
	calcCondition();
}
bool MOB::has(Item item)
{
	bool has = false;
	for (Item e : _equipment)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
	}
	return has;
}
bool MOB::take(Item item)
{
	int i = 0;
	bool has = false;
	for (Item e : _equipment)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
		i++;
	}
	if (has)
		_equipment.erase(_equipment.begin() + i);
	return has;
}
#pragma endregion

#pragma region NPC
void NPC::init()
{
	_inventory = std::vector<Item>();
}
void NPC::addItem(Item item)
{
	_inventory.push_back(item);
}
bool NPC::hasItem(Item item)
{
	bool has = false;
	for (Item e : _inventory)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
	}
	return has;
}
Item NPC::getItem(int index)
{ 
	return _inventory.at(index);
}
void NPC::removeItem(int index)
{ 
	_inventory.erase(_inventory.begin() + index);
}
std::vector<Item> NPC::allItems()
{ 
	return _inventory; 
}
#pragma endregion

#pragma region Beast
void Beast::init(int attack, std::tuple<int, Dice::die> damage, DamageType damageType,
	int experience, std::tuple<int, Dice::die> gold)
{
	_attack = attack;
	_damage = damage;
	_damageType = damageType;
	_experience = experience;
	_gold = gold;
	_loot = std::vector<Item>();
}
int Beast::getAttack() 
{ 
	return _attack; 
}
void Beast::setAttack(int attack)
{ 
	_attack = attack; 
}
std::tuple<int, Dice::die> Beast::getDamage()
{ 
	return _damage;
}
int Beast::rollDamage()
{
	int damage = 0;
	for (int i = 0; i < std::get<0>(_damage); ++i)
	{
		damage += Dice::Roll(std::get<1>(_damage));
	}
	return damage;
}
void Beast::setDamage(std::tuple<int, Dice::die> damage)
{
	_damage = damage;
}
int Beast::getExperience()
{
	return _experience;
}
void Beast::setExperience(int experience)
{
	_experience = experience;
}
std::tuple<int, Dice::die> Beast::getGold()
{
	return _gold;
}
int Beast::rollGold()
{
	int gold = 0;
	for (int i = 0; i < std::get<0>(_gold); ++i)
	{
		gold += Dice::Roll(std::get<1>(_gold));
	}
	return gold;
}
void Beast::setGold(std::tuple<int, Dice::die> gold)
{
	_gold = gold;
}
#pragma endregion

