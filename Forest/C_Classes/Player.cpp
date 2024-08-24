#include "Player.h"

using namespace Creatures;
using namespace CSL_Color;
using namespace CSL_Console;
using namespace CSL_Cursor;
using namespace CSL_Line;

#pragma region Player
void PC::init(std::string name)
{
	_name = name;
	_title = "the fledgling";
	_level = 1;
	_experience = 0;
	_gold = 100;
	_health = { "Health", 100, 100 };
	_spirit = { "Spirit", 20, 20 };
	_stamina = { "Stamina", 100, 100 };
	_strength = 5;
	_fortitude = 3;
	_agility = 3;
	_intellect = 5;
	_curWeapon = Weapon("Fists", 0, ItemType::misc);
	_curArmor = Armor("Tunic", 0, ItemType::gear);
	_curShield = Shield("none", 0, ItemType::misc);
	_inventory = std::vector<Item>();
	_weapons = std::vector<Weapon>();
	_armors = std::vector<Armor>();
	_shields = std::vector<Shield>();
	_potions = std::vector<Potion>();
	_gear = std::vector<Item>();
	_miscItems = std::vector<Item>();
	_weapons.push_back(_curWeapon);
	_inventory.push_back(_curWeapon);
	_armors.push_back(_curArmor);
	_inventory.push_back(_curArmor);
};

void PC::createNew(PC& player)
{
	if ((player._name == "") || (player._race == Race::none) || (player._school == School::none))
		return;

	player._health.Set(80);
	player._spirit.Set(80);
	player._stamina.Set(80);

	player._strength = player._agility = player._fortitude = 8;
	player._intellect = player._wisdom = player._luck = 8;

	player._armor = 0;
	player._accuracy = player._evasion = 3;
	player._magic = 1;

	player._cutting.power = player._stabbing.power = player._bashing.power = 3;
	player._cutting.resist = player._stabbing.resist = player._bashing.resist = 1;
	player._fire.power = player._water.power = player._earth.power = player._air.power = 0;
	player._fire.resist = player._water.resist = player._earth.resist = player._air.resist = 0;
	player._poison.power = player._lightning.power = player._sonic.power = 0;
	player._poison.resist = player._lightning.resist = player._sonic.resist = 0;

	player._trainingPoints = 6;
	player._skillPoints = 5;

	switch (player._race)
	{
	case Race::Human:
		player._health.Add(25);
		player._spirit.Add(25);
		player._stamina.Add(25);
		player._strength += 6;
		player._agility += 6;
		player._fortitude += 6;
		player._intellect += 6;
		player._wisdom += 6;
		player._luck += 7;
		player._accuracy += 2;
		player._evasion += 2;
		player._magic += 2;
		player._cutting.power += 2;
		player._cutting.resist += 2;
		player._stabbing.power += 2;
		player._stabbing.resist += 2;
		player._bashing.power += 2;
		player._bashing.resist += 2;
		player._fire.power += 1;
		player._fire.resist += 2;
		player._water.power += 1;
		player._water.resist += 2;
		player._earth.power += 1;
		player._earth.resist += 2;
		player._air.power += 1;
		player._air.resist += 2;
		break;
	case Race::Elf:
		player._health.Add(10);
		player._spirit.Add(40);
		player._stamina.Add(30);
		player._strength += 4;
		player._agility += 10;
		player._fortitude += 4;
		player._intellect += 8;
		player._wisdom += 7;
		player._luck += 4;
		player._accuracy += 3;
		player._evasion += 3;
		player._magic += 3;
		player._cutting.power += 2;
		player._cutting.resist += 1;
		player._stabbing.power += 2;
		player._stabbing.resist += 1;
		player._bashing.power += 1;
		player._bashing.resist += 1;
		player._fire.power += 1;
		player._fire.resist += 1;
		player._water.power += 1;
		player._water.resist += 1;
		player._earth.power += 1;
		player._earth.resist += 1;
		player._air.power += 1;
		player._air.resist += 1;
		player._poison.power += 1;
		player._poison.resist += 1;
		player._lightning.power += 2;
		player._lightning.resist += 2;
		player._sonic.power += 2;
		player._sonic.resist += 2;
		break;
	case Race::Dwarf:
		player._health.Add(40);
		player._spirit.Add(10);
		player._stamina.Add(30);
		player._strength += 8;
		player._agility += 2;
		player._fortitude += 10;
		player._intellect += 4;
		player._wisdom += 5;
		player._luck += 7;
		player._armor += 1;
		player._accuracy += 2;
		player._evasion += 1;
		player._magic += 1;
		player._cutting.power += 3;
		player._cutting.resist += 3;
		player._stabbing.power += 1;
		player._stabbing.resist += 3;
		player._bashing.power += 3;
		player._bashing.resist += 3;
		player._fire.power += 2;
		player._fire.resist += 3;
		player._earth.power += 2;
		player._earth.resist += 3;
		player._poison.power += 2;
		player._poison.resist += 3;
		break;
	case Race::Gnome:
		player._spirit.Add(50);
		player._stamina.Add(15);
		player._strength += 2;
		player._agility += 8;
		player._fortitude += 2;
		player._intellect += 10;
		player._wisdom += 8;
		player._luck += 9;
		player._accuracy += 2;
		player._evasion += 4;
		player._magic += 4;
		player._cutting.power += 1;
		player._cutting.resist += 2;
		player._stabbing.power += 2;
		player._stabbing.resist += 2;
		player._bashing.power += 1;
		player._bashing.resist += 2;
		player._water.power += 2;
		player._water.resist += 3;
		player._air.power += 2;
		player._air.resist += 3;
		player._sonic.power += 2;
		player._sonic.resist += 3;
		break;
	case Race::Orc:
		player._health.Add(35);
		player._stamina.Add(45);
		player._strength += 10;
		player._agility += 4;
		player._fortitude += 8;
		player._intellect += 2;
		player._wisdom += 5;
		player._luck += 7;
		player._armor += 1;
		player._accuracy += 2;
		player._evasion += 2;
		player._magic += 1;
		player._cutting.power += 2;
		player._cutting.resist += 4;
		player._stabbing.power += 2;
		player._stabbing.resist += 4;
		player._bashing.power += 2;
		player._bashing.resist += 4;
		player._fire.resist += 1;
		player._water.resist += 1;
		player._earth.resist += 1;
		player._air.resist += 1;
		player._poison.power += 1;
		player._poison.resist += 2;
		player._lightning.power += 2;
		player._lightning.resist += 3;
		break;

	}
	switch (player._school)
	{
	case School::Fighter:
		player._health.Add(25);
		player._spirit.Add(5);
		player._stamina.Add(20);
		player._strength += 3;
		player._agility += 3;
		player._fortitude += 2;
		player._intellect += 1;
		player._wisdom += 1;
		player._luck += 1;
		player._armor += 1;
		player._accuracy += 3;
		player._evasion += 3;
		player._magic += 1;
		player._cutting.power += 4;
		player._cutting.resist += 2;
		player._stabbing.power += 2;
		player._stabbing.resist += 2;
		player._bashing.power += 3;
		player._bashing.resist += 2;
		player._fire.resist += 1;
		player._water.resist += 1;
		player._earth.power += 1;
		player._earth.resist += 1;
		player._air.resist += 1;
		player._lightning.power += 1;
		break;
	case School::Rogue:
		player._health.Add(15);
		player._spirit.Add(10);
		player._stamina.Add(25);
		player._strength += 2;
		player._agility += 4;
		player._fortitude += 1;
		player._intellect += 1;
		player._wisdom += 2;
		player._luck += 1;
		player._accuracy += 3;
		player._evasion += 5;
		player._magic += 1;
		player._cutting.power += 2;
		player._cutting.resist += 1;
		player._stabbing.power += 5;
		player._stabbing.resist += 1;
		player._bashing.power += 2;
		player._bashing.resist += 1;
		player._fire.power += 1;
		player._air.power += 1;
		player._poison.power += 3;
		player._poison.resist += 2;
		break;
	case School::Wizard:
		player._spirit.Add(40);
		player._stamina.Add(10);
		player._strength += 1;
		player._agility += 1;
		player._intellect += 5;
		player._wisdom += 3;
		player._luck += 1;
		player._accuracy += 1;
		player._evasion += 1;
		player._magic += 5;
		player._stabbing.power += 1;
		player._fire.power += 2;
		player._fire.resist += 1;
		player._water.power += 2;
		player._water.resist += 1;
		player._earth.power += 2;
		player._earth.resist += 1;
		player._air.power += 2;
		player._air.resist += 1;
		player._poison.power += 1;
		player._lightning.power += 2;
		player._lightning.resist += 1;
		player._sonic.power += 2;
		player._sonic.resist += 1;
		break;
	}
};


void PC::sortInventory()
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
	int SizeX = CSL::getWindowSize().X;
	bool wide = false;
	int width = 80;
	if (SizeX >= 120)
	{
		wide = true;
		width = 120;
	}

	CSL::clear();
	Line::lineDrawingOn();
	Cursor::setHor(2);
	Line::lineDraw(Line::TL);
	for (int i = 3; i < width - 2; ++i)
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
			for (int i = 3; i < width - 2; ++i)
				Line::lineDraw(Line::HOR);
			Line::lineDraw(Line::RIGHT_T);
		}
		else
		{
			Line::lineDraw(Line::VER);
			Cursor::setHor(width - 2);
			Line::lineDraw(Line::VER);
		}
	}
	Print "\n";
	Cursor::setHor(2);
	Line::lineDraw(Line::BL);
	for (int i = 3; i < width - 2; ++i)
		Line::lineDraw(Line::HOR);
	Line::lineDraw(Line::BR);
	Line::lineDrawingOff();

	textBoxBorder(5, 14, 20, 6);
	textBoxBorder(30, 14, 20, 6);

	Cursor::setPos(5, 2);
	Print FG_AZURE1 << getName() << FG_CYAN1 << ", " << getTitle() << FG_GRAY2;

	Cursor::setPos(5, 4);
	Print "Level: " << FG_SPRING1 << getLevel() << FG_GRAY2;
	Cursor::setHor(23);
	if (wide) Cursor::setHor(25);
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
	Print "Strength: " << FG_ORANGE1 << GetStrength() << FG_GRAY2;
	Cursor::setHor(21);
	if (wide) Cursor::setHor(25);
	Print "Fortitude: " << FG_AZURE1 << GetFortitude() << FG_GRAY2;
	Cursor::setHor(37);
	if (wide) Cursor::setHor(40);
	Print "Agility: " << FG_GREEN1 << GetAgility() << FG_GRAY2;
	Cursor::setHor(54);
	if (wide) Cursor::setHor(55);
	Print "Intellect: " << FG_CYAN1 << GetIntellect() << FG_GRAY2;
	Cursor::setHor(70);
	if (wide) Cursor::setHor(70);
	Print "Wisdom: " << FG_YELLOW1 << GetWisdom() << FG_GRAY2;

	Cursor::setPos(5, 12);
	Print "Gold: " << FG_GOLD1 << getGold() << FG_GRAY2;
	Cursor::setPos(5, 13);
	Print "Weapon: " << FG_WHITE << getWeapon() << FG_GRAY2;
	Cursor::setHor(30);
	if (wide) Cursor::setHor(40);
	Print "Armor: " << FG_WHITE << getArmor() << FG_GRAY2;
	Cursor::setHor(55);
	if (wide) Cursor::setHor(70);
	Print "Shield: " << FG_WHITE << getShield() << FG_GRAY2;

	Cursor::setPos(7, 15);
	Print "Accuracy: " << FG_VIOLET1 << getAccuracy() << FG_GRAY2;
	Cursor::setHor(32);
	Print "Dodge:    " << FG_AZURE1 << getDodge() << FG_GRAY2;
	Cursor::setPos(7, 16);
	Print "Cutting:  " << FG_VIOLET1 << getDamCutting() << FG_GRAY2;
	Cursor::setHor(32);
	Print "Cutting:  " << FG_AZURE1 << getResCutting() << FG_GRAY2;
	Cursor::setPos(7, 17);
	Print "Stabbing: " << FG_VIOLET1 << getDamStabbing() << FG_GRAY2;
	Cursor::setHor(32);
	Print "Stabbing: " << FG_AZURE1 << getResStabbing() << FG_GRAY2;
	Cursor::setPos(7, 18);
	Print "Smashing: " << FG_VIOLET1 << getDamSmashing() << FG_GRAY2;
	Cursor::setHor(32);
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

void PC::save()
{
};
void PC::load()
{
};

#pragma endregion