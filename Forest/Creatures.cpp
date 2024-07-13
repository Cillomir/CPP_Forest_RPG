#pragma once
#include "Creatures.h"
using namespace Creatures;
using namespace CSL_Color;
using namespace CSL_Console;
using namespace CSL_Cursor;
using namespace CSL_Line;

void PC::init()
{
	_title = "the fledgling";
	_level = 1;
	_experience = 0;
	_gold = 100;
	_health = { 100, 100 };
	_spirit = { 20, 20 };
	_stamina = { 100, 100 };
	_strength = 5;
	_fortitude = 3;
	_agility = 3;
	_intellect = 5;
	_curWeapon = Weapon("Fists", 0, Equipment::EquipType::misc);
	_curArmor = Armor("Tunic", 0, Equipment::EquipType::gear);
	_curShield = Shield("none", 0, Equipment::EquipType::misc);
	_inventory = std::vector<Equipment>();
	_weapons = std::vector<Weapon>();
	_armors = std::vector<Armor>();
	_shields = std::vector<Shield>();
	_potions = std::vector<Potion>();
	_gear = std::vector<Equipment>();
	_miscItems = std::vector<Equipment>();
	_weapons.push_back(_curWeapon);
	_inventory.push_back(_curWeapon);
	_armors.push_back(_curArmor);
	_inventory.push_back(_curArmor);
};

void PC::sortEquipment()
	{
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
	};

int PC::getAccuracy()
{
	int acc = _agility + _curWeapon.getSpeed() - _curArmor.getPenalty() - _curShield.getPenalty();
	return acc;
}
int PC::getDamCutting()
{
	int dam = _strength + (int)floor(_fortitude / 3) + (int)floor(_agility / 3) + _curWeapon.getCutting();
	return dam;
}
int PC::getDamStabbing()
{
	int dam = _strength + (int)floor(_agility / 2) + _curWeapon.getStabbing();
	return dam;
}
int PC::getDamSmashing()
{
	int dam = _strength + (int)floor(_fortitude / 2) + _curWeapon.getSmashing();
	return dam;
}
int PC::getDodge()
{
	int dodge = _agility + (int)floor(_curWeapon.getSpeed() / 2) - _curArmor.getPenalty() + _curShield.getDefense();
	return dodge;
}
int PC::getResCutting()
{
	int res = _fortitude + _curArmor.getCutting() + _curShield.getCutting();
	return res;
}
int PC::getResStabbing()
{
	int res = _fortitude + _curArmor.getStabbing() + _curShield.getStabbing();
	return res;
}
int PC::getResSmashing()
{
	int res = _fortitude + _curArmor.getSmashing() + _curShield.getSmashing();
	return res;
}

void PC::viewStats()
{
	CSL::clear();
	Line::lineDrawingOn();
	Cursor::setHor(2);
	Line::lineDraw(Line::TL);
	for (int i = 3; i < 80 - 2; ++i)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::TR);
	COORD cursorPos = CSL::getCursorPos();
	for (int i = 2; i < 22; ++i)
	{
		Print "\n";
		Cursor::setHor(2);
		if (i == 11)
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

	Cursor::setPos(5, 14);
	Line::lineDraw(Line::TL);
	for (int x = 6; x < 25; ++x)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::TR);
	Cursor::setHor(32);
	Line::lineDraw(Line::TL);
	for (int x = 33; x < 52; ++x)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::TR);
	for (int y = 15; y < 19; ++y)
	{
		Print "\n";
		Cursor::setHor(5);
		Line::lineDraw(Line::VER);
		Cursor::setHor(25);
		Line::lineDraw(Line::VER);
		Cursor::setHor(32);
		Line::lineDraw(Line::VER);
		Cursor::setHor(52);
		Line::lineDraw(Line::VER);
	}
	Cursor::setPos(5, 19);
	Line::lineDraw(Line::BL);
	for (int x = 6; x < 25; ++x)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::BR);
	Cursor::setHor(32);
	Line::lineDraw(Line::BL);
	for (int x = 33; x < 52; ++x)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::BR);

	Line::lineDrawingOff();

	Cursor::setPos(5, 2);
	Print FG_AZURE1 << getName() << FG_CYAN1 << ", " << getTitle() << FG_GRAY2;

	Cursor::setPos(5, 4);
	Print "Level: " << FG_SPRING1 << getLevel() << FG_GRAY2;
	Cursor::setHor(23);
	Print "Experience: " << FG_SPRING1 << getExp() << FG_GRAY2;

	char health[5], spirit[5], stamina[5] = { 0 };
	sprintf_s(health, 5, "% 4d", getHealth());
	sprintf_s(spirit, 5, "% 4d", getSpirit());
	sprintf_s(stamina, 5, "% 4d", getStamina());
	Cursor::setPos(5, 6);
	Print "Health:  " << FG_RED1 << health << FG_GRAY1 << "/" << FG_RED1 << getHealthMax() << FG_GRAY2;
	Cursor::setPos(5, 7);
	Print "Spirit:  " << FG_RED1 << spirit << FG_GRAY1 << "/" << FG_RED1 << getSpiritMax() << FG_GRAY2;
	Cursor::setPos(5, 8);
	Print "Stamina: " << FG_RED1 << stamina << FG_GRAY1 << "/" << FG_RED1 << getStaminaMax() << FG_GRAY2;

	Cursor::setPos(5, 10);
	Print "Strength: " << FG_ORANGE1 << getStrength() << FG_GRAY2;
	Cursor::setHor(23);
	Print "Fortitude: " << FG_AZURE1 << getFortitude() << FG_GRAY2;
	Cursor::setHor(41);
	Print "Agility: " << FG_GREEN1 << getAgility() << FG_GRAY2;
	Cursor::setHor(59);
	Print "Intellect: " << FG_CYAN1 << getIntellect() << FG_GRAY2;

	Cursor::setPos(5, 12);
	Print "Gold: " << FG_GOLD1 << getGold() << FG_GRAY2;
	Cursor::setPos(5, 13);
	Print "Weapon: " << FG_WHITE << getWeapon() << FG_GRAY2;
	Cursor::setHor(30);
	Print "Armor: " << FG_WHITE << getArmor() << FG_GRAY2;
	Cursor::setHor(55);
	Print "Shield: " << FG_WHITE << getShield() << FG_GRAY2;

	Cursor::setPos(7, 15);
	Print "Accuracy: " << FG_VIOLET1 << getAccuracy() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Dodge:    " << FG_AZURE1 << getDodge() << FG_GRAY2;
	Cursor::setPos(7, 16);
	Print "Cutting:  " << FG_VIOLET1 << getDamCutting() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Cutting:  " << FG_AZURE1 << getResCutting() << FG_GRAY2;
	Cursor::setPos(7, 17);
	Print "Stabbing: " << FG_VIOLET1 << getDamStabbing() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Stabbing: " << FG_AZURE1 << getResStabbing() << FG_GRAY2;
	Cursor::setPos(7, 18);
	Print "Smashing: " << FG_VIOLET1 << getDamSmashing() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Smashing: " << FG_AZURE1 << getResSmashing() << FG_GRAY2;

	Print SGR_RESET;
	pressAnyKey();
}

void PC::statLine()
{
	COORD size = CSL::getWindowSize();
	Cursor::setPos(1, size.Y - 1);
	Print FG_GRAY2 << "<Health: ";
	Print FG_RED1;
	Print getHealth() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print getHealthMax() << FG_GRAY2 << "  ";
	Print FG_GRAY2 << "Spirit: ";
	Print FG_RED1;
	Print getSpirit() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print getSpiritMax() << FG_GRAY2 << "  ";
	Print FG_GRAY2 << "Stamina: ";
	Print FG_RED1;	Print getStamina() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print getStaminaMax() << FG_GRAY2 << ">: " << SGR_RESET << CUR_SHAPE_BAR_B;

}

void MOB::init(std::string name, std::string description, int level, int health)
{
	_name = name;
	_description = description;
	_level = level;
	_health = { health, health };
	_condition = Condition::healthy;
	_equipment = std::vector<Equipment>();
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
	for (Equipment e : _equipment)
	{
		e.description();
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
bool MOB::has(Equipment item)
{
	bool has = false;
	for (Equipment e : _equipment)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
	}
	return has;
}
bool MOB::take(Equipment item)
{
	int i = 0;
	bool has = false;
	for (Equipment e : _equipment)
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

void NPC::addItem(Equipment item)
{
	_inventory.push_back(item);
}
bool NPC::hasItem(Equipment item)
{
	bool has = false;
	for (Equipment e : _inventory)
	{
		if (e.getName() == item.getName())
		{
			has = true;
			break;
		}
	}
	return has;
}
Equipment NPC::getItem(int index)
{ 
	return _inventory.at(index);
}
void NPC::removeItem(int index)
{ 
	_inventory.erase(_inventory.begin() + index);
}
std::vector<Equipment> NPC::allItems()
{ 
	return _inventory; 
}

