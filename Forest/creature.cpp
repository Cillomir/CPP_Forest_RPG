#pragma once
#include "creature.h"
using namespace Creatures;
using namespace CSL_Color;
using namespace CSL_Console;
using namespace CSL_Cursor;
using namespace CSL_Line;

//Creatures::mainPlayer = Player();

void Creature::setDefaults(int level, int health)
{
	_level = level;
	_health = { health, health };
	_condition = Condition::healthy;
	_allEquipment = std::vector<Equipment>();
}

void Player::setDefaults()
{
	_title = "the fledgling";
	_level = 1;
	_experience = 0;
	_gold = 100;
	_health = { 100, 100 };
	_strength = 5;
	_defense = 3;
	_curWeapon = Equipment("Fists", 0, Equipment::EquipType::weapon);
	_curArmor = Equipment("Tunic", 0, Equipment::EquipType::gear);
	_allEquipment = std::vector<Equipment>();
	_allWeapons = std::vector<Equipment>();
	_allArmors = std::vector<Equipment>();
	_allPotions = std::vector<Equipment>();
	_allGear = std::vector<Equipment>();
	_allMisc = std::vector<Equipment>();
	_allWeapons.push_back(_curWeapon);
	_allEquipment.push_back(_curWeapon);
	_allArmors.push_back(_curArmor);
	_allEquipment.push_back(_curArmor);
}

void Creature::calcCondition()
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
void Creature::look()
{
	std::cout << _description << std::endl;;
}
void Creature::examine()
{
	std::cout << _name << ": " << _description << std::endl;
	std::cout << "Level: " << _level << std::endl;
	std::cout << "Health: " << std::get<0>(_health) << "/" << std::get<1>(_health) << std::endl;
	for (Equipment e : _allEquipment)
	{
		e.description();
	}
}
void Creature::hurt(int amount)
{
	std::get<0>(_health) -= amount;
	if (std::get<0>(_health) < 0)
		std::get<0>(_health) = 0;
	calcCondition();
}
void Creature::heal(int amount)
{
	std::get<0>(_health) += amount;
	if (std::get<0>(_health) > std::get<1>(_health))
		std::get<0>(_health) = std::get<1>(_health);
	calcCondition();
}
bool Creature::take(Equipment item)
{
	int i = 0;
	bool has = false;
	for (Equipment e : _allEquipment)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
		i++;
	}
	if (has)
		_allEquipment.erase(_allEquipment.begin() + i);
	return has;
}

void Player::viewStats() {
	CSL::clear();
	Line::lineDrawingOn();
	Cursor::setHor(2);
	Line::lineDraw(Line::TL);
	for (int i = 3; i < 80 - 2; ++i)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::TR);
	COORD cursorPos = CSL::getCursorPos();
	for (int i = 2; i < 20; ++i)
	{
		Print "\n";
		Cursor::setHor(2);
		if (i == 8)
		{
			Line::lineDraw(Line::LEFT_T);
			for (int i = 3; i < 80 - 2; ++i)
				Line::lineDraw(Line::HOR);
			Line::lineDraw(Line::RIGHT_T);
		}
		else
		{
			Line::lineDraw(Line::VER);
			Cursor::setHor(80 - 2);
			Line::lineDraw(Line::VER);
		}
	}
	Print "\n";
	Cursor::setHor(2);
	Line::lineDraw(Line::BL);
	for (int i = 3; i < 80 - 2; ++i)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::BR);
	Line::lineDrawingOff();

	Cursor::setPos(5, 2);
	Print FG_AZURE1 << getName() << FG_CYAN1 << ", " << getTitle() << FG_GRAY2;
	Cursor::setPos(5, 4);
	Print "Level: " << FG_SPRING1 << getLevel() << FG_GRAY2;
	Cursor::setHor(30);
	Print "Experience: " << FG_SPRING1 << getExp() << FG_GRAY2;
	Cursor::setPos(5, 6);
	Print "Health: " << FG_RED1 << getHealth() << FG_GRAY1 << "/" << FG_RED1 << getHealthMax() << FG_GRAY2;
	Cursor::setPos(5, 7);
	Print "Strength: " << FG_ORANGE1 << getStrength() << FG_GRAY2;
	Cursor::setHor(30);
	Print "Defense: " << FG_AZURE1 << getDefense() << FG_GRAY2;
	Cursor::setPos(5, 9);
	Print "Gold: " << FG_GOLD1 << getGold() << FG_GRAY2;
	Cursor::setPos(5, 10);
	Print "Weapon: " << FG_WHITE << getWeapon() << FG_GRAY2;
	Cursor::setHor(30);
	Print "Armor: " << FG_WHITE << getArmor() << FG_GRAY2;
	Print SGR_RESET;
	pressAnyKey();
};
