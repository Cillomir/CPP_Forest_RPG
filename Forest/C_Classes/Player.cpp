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

void PC::createNew(PC *player)
{
	PC pc = *player;
	if ((pc._name == "") || (pc._race == Race::none) || (pc._school == School::none))
		return;

	pc._health.Set(80);
	pc._spirit.Set(80);
	pc._stamina.Set(80);

	pc._strength = pc._agility = pc._fortitude = 8;
	pc._intellect = pc._wisdom = pc._luck = 8;

	pc._armor = 0;
	pc._accuracy = pc._evasion = 3;
	pc._magic = 1;

	pc._cutting.power = pc._stabbing.power = pc._bashing.power = 3;
	pc._cutting.resist = pc._stabbing.resist = pc._bashing.resist = 1;
	pc._fire.power = pc._water.power = pc._earth.power = pc._air.power = 0;
	pc._fire.resist = pc._water.resist = pc._earth.resist = pc._air.resist = 0;
	pc._poison.power = pc._lightning.power = pc._sonic.power = 0;
	pc._poison.resist = pc._lightning.resist = pc._sonic.resist = 0;

	pc._trainingPoints = 6;
	pc._skillPoints = 5;

	switch (pc._race)
	{
	case Race::Human:
		pc._health.Add(25);
		pc._spirit.Add(25);
		pc._stamina.Add(25);
		pc._strength += 6;
		pc._agility += 6;
		pc._fortitude += 6;
		pc._intellect += 6;
		pc._wisdom += 6;
		pc._luck += 7;
		pc._accuracy += 2;
		pc._evasion += 2;
		pc._magic += 2;
		pc._cutting.power += 2;
		pc._cutting.resist += 2;
		pc._stabbing.power += 2;
		pc._stabbing.resist += 2;
		pc._bashing.power += 2;
		pc._bashing.resist += 2;
		pc._fire.power += 1;
		pc._fire.resist += 2;
		pc._water.power += 1;
		pc._water.resist += 2;
		pc._earth.power += 1;
		pc._earth.resist += 2;
		pc._air.power += 1;
		pc._air.resist += 2;
		break;
	case Race::Elf:
		pc._health.Add(10);
		pc._spirit.Add(40);
		pc._stamina.Add(30);
		pc._strength += 4;
		pc._agility += 10;
		pc._fortitude += 4;
		pc._intellect += 8;
		pc._wisdom += 7;
		pc._luck += 4;
		pc._accuracy += 3;
		pc._evasion += 3;
		pc._magic += 3;
		pc._cutting.power += 2;
		pc._cutting.resist += 1;
		pc._stabbing.power += 2;
		pc._stabbing.resist += 1;
		pc._bashing.power += 1;
		pc._bashing.resist += 1;
		pc._fire.power += 1;
		pc._fire.resist += 1;
		pc._water.power += 1;
		pc._water.resist += 1;
		pc._earth.power += 1;
		pc._earth.resist += 1;
		pc._air.power += 1;
		pc._air.resist += 1;
		pc._poison.power += 1;
		pc._poison.resist += 1;
		pc._lightning.power += 2;
		pc._lightning.resist += 2;
		pc._sonic.power += 2;
		pc._sonic.resist += 2;
		break;
	case Race::Dwarf:
		pc._health.Add(40);
		pc._spirit.Add(10);
		pc._stamina.Add(30);
		pc._strength += 8;
		pc._agility += 2;
		pc._fortitude += 10;
		pc._intellect += 4;
		pc._wisdom += 5;
		pc._luck += 7;
		pc._armor += 1;
		pc._accuracy += 2;
		pc._evasion += 1;
		pc._magic += 1;
		pc._cutting.power += 3;
		pc._cutting.resist += 3;
		pc._stabbing.power += 1;
		pc._stabbing.resist += 3;
		pc._bashing.power += 3;
		pc._bashing.resist += 3;
		pc._fire.power += 2;
		pc._fire.resist += 3;
		pc._earth.power += 2;
		pc._earth.resist += 3;
		pc._poison.power += 2;
		pc._poison.resist += 3;
		break;
	case Race::Gnome:
		pc._spirit.Add(50);
		pc._stamina.Add(15);
		pc._strength += 2;
		pc._agility += 8;
		pc._fortitude += 2;
		pc._intellect += 10;
		pc._wisdom += 8;
		pc._luck += 9;
		pc._accuracy += 2;
		pc._evasion += 4;
		pc._magic += 4;
		pc._cutting.power += 1;
		pc._cutting.resist += 2;
		pc._stabbing.power += 2;
		pc._stabbing.resist += 2;
		pc._bashing.power += 1;
		pc._bashing.resist += 2;
		pc._water.power += 2;
		pc._water.resist += 3;
		pc._air.power += 2;
		pc._air.resist += 3;
		pc._sonic.power += 2;
		pc._sonic.resist += 3;
		break;
	case Race::Orc:
		pc._health.Add(35);
		pc._stamina.Add(45);
		pc._strength += 10;
		pc._agility += 4;
		pc._fortitude += 8;
		pc._intellect += 2;
		pc._wisdom += 5;
		pc._luck += 7;
		pc._armor += 1;
		pc._accuracy += 2;
		pc._evasion += 2;
		pc._magic += 1;
		pc._cutting.power += 2;
		pc._cutting.resist += 4;
		pc._stabbing.power += 2;
		pc._stabbing.resist += 4;
		pc._bashing.power += 2;
		pc._bashing.resist += 4;
		pc._fire.resist += 1;
		pc._water.resist += 1;
		pc._earth.resist += 1;
		pc._air.resist += 1;
		pc._poison.power += 1;
		pc._poison.resist += 2;
		pc._lightning.power += 2;
		pc._lightning.resist += 3;
		break;

	}
	switch (pc._school)
	{
	case School::Fighter:
		pc._health.Add(25);
		pc._spirit.Add(5);
		pc._stamina.Add(20);
		pc._strength += 3;
		pc._agility += 3;
		pc._fortitude += 2;
		pc._intellect += 1;
		pc._wisdom += 1;
		pc._luck += 1;
		pc._armor += 1;
		pc._accuracy += 3;
		pc._evasion += 3;
		pc._magic += 1;
		pc._cutting.power += 4;
		pc._cutting.resist += 2;
		pc._stabbing.power += 2;
		pc._stabbing.resist += 2;
		pc._bashing.power += 3;
		pc._bashing.resist += 2;
		pc._fire.resist += 1;
		pc._water.resist += 1;
		pc._earth.power += 1;
		pc._earth.resist += 1;
		pc._air.resist += 1;
		pc._lightning.power += 1;
		break;
	case School::Rogue:
		pc._health.Add(15);
		pc._spirit.Add(10);
		pc._stamina.Add(25);
		pc._strength += 2;
		pc._agility += 4;
		pc._fortitude += 1;
		pc._intellect += 1;
		pc._wisdom += 2;
		pc._luck += 1;
		pc._accuracy += 3;
		pc._evasion += 5;
		pc._magic += 1;
		pc._cutting.power += 2;
		pc._cutting.resist += 1;
		pc._stabbing.power += 5;
		pc._stabbing.resist += 1;
		pc._bashing.power += 2;
		pc._bashing.resist += 1;
		pc._fire.power += 1;
		pc._air.power += 1;
		pc._poison.power += 3;
		pc._poison.resist += 2;
		break;
	case School::Wizard:
		pc._spirit.Add(40);
		pc._stamina.Add(10);
		pc._strength += 1;
		pc._agility += 1;
		pc._intellect += 5;
		pc._wisdom += 3;
		pc._luck += 1;
		pc._accuracy += 1;
		pc._evasion += 1;
		pc._magic += 5;
		pc._stabbing.power += 1;
		pc._fire.power += 2;
		pc._fire.resist += 1;
		pc._water.power += 2;
		pc._water.resist += 1;
		pc._earth.power += 2;
		pc._earth.resist += 1;
		pc._air.power += 2;
		pc._air.resist += 1;
		pc._poison.power += 1;
		pc._lightning.power += 2;
		pc._lightning.resist += 1;
		pc._sonic.power += 2;
		pc._sonic.resist += 1;
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

void PC::viewStats(PC& pc)
{
	//PC pc = *player;

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

	if (wide)
	{
		textBoxBorder(6, 14, 20, 6);
		textBoxBorder(32, 14, 20, 6);
		textBoxBorder(58, 14, 20, 7);
		textBoxBorder(84, 14, 20, 7);
	}
	else
	{
		textBoxBorder(3, 14, 20, 6);
		textBoxBorder(25, 14, 20, 6);
		textBoxBorder(47, 14, 20, 7);
		textBoxBorder(59, 14, 20, 7);
	}

	Cursor::setPos(5, 2);
	Print FG_AZURE1 << pc.GetName() << FG_CYAN1 << ", " << pc.getTitle() << " " << FG_CYAN2 << pc.GetRace() << " " << pc.GetSchool() << FG_GRAY2;

	Cursor::setPos(5, 4);
	Print "Level: " << FG_SPRING1 << pc.GetLevel() << FG_GRAY2;
	Cursor::setHor(23);
	if (wide) Cursor::setHor(25);
	Print "Experience: " << FG_SPRING1 << pc.GetExperience() << FG_GRAY2;

	char health[5], spirit[5], stamina[5] = { 0 };
	sprintf_s(health, 5, "% 4d", pc.GetCurHealth());
	sprintf_s(spirit, 5, "% 4d", pc.GetCurSpirit());
	sprintf_s(stamina, 5, "% 4d", pc.GetCurStamina());
	Cursor::setPos(5, 6);
	Print "Health:  " << FG_RED1 << health << FG_GRAY1 << "/" << FG_RED1 << pc.GetMaxHealth() << FG_GRAY2;
	Cursor::setPos(5, 7);
	Print "Spirit:  " << FG_RED1 << spirit << FG_GRAY1 << "/" << FG_RED1 << pc.GetMaxSpirit() << FG_GRAY2;
	Cursor::setPos(5, 8);
	Print "Stamina: " << FG_RED1 << stamina << FG_GRAY1 << "/" << FG_RED1 << pc.GetMaxStamina() << FG_GRAY2;

	Cursor::setPos(5, 10);
	Print "Strength: " << FG_ORANGE1 << pc.GetStrength() << FG_GRAY2;
	Cursor::setHor(20);
	if (wide) Cursor::setHor(23);
	Print "Fortitude: " << FG_AZURE1 << pc.GetFortitude() << FG_GRAY2;
	Cursor::setHor(35);
	if (wide) Cursor::setHor(41);
	Print "Agility: " << FG_GREEN1 << pc.GetAgility() << FG_GRAY2;
	Cursor::setHor(50);
	if (wide) Cursor::setHor(59);
	Print "Intellect: " << FG_CYAN1 << pc.GetIntellect() << FG_GRAY2;
	Cursor::setHor(65);
	if (wide) Cursor::setHor(77);
	Print "Wisdom: " << FG_YELLOW1 << pc.GetWisdom() << FG_GRAY2;
	Cursor::setHor(80);
	if (wide) Cursor::setHor(95);
	Print "Luck: " << FG_TAN1 << pc.GetLuck() << FG_GRAY2;

	Cursor::setPos(5, 12);
	Print "Gold: " << FG_GOLD1 << pc.GetGold() << FG_GRAY2;
	Cursor::setHor(22);
	Print "Silver: " << FG_SILVER1 << pc.GetSilver() << FG_GRAY2;
	Cursor::setHor(39);
	Print "Copper: " << FG_COPPER1 << pc.GetCopper() << FG_GRAY2;

	Cursor::setPos(8, 15);
	Print "Accuracy: " << FG_VIOLET1 << pc.getAccuracy() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Dodge:    " << FG_AZURE1 << pc.getDodge() << FG_GRAY2;
	Cursor::setHor(60);
	Print "Magic:    " << FG_ROSE1 << pc.GetMagic() << FG_GRAY2;
	Cursor::setPos(8, 16);
	Print "Cutting:  " << FG_VIOLET1 << pc.getDamCutting() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Cutting:  " << FG_AZURE1 << pc.getResCutting() << FG_GRAY2;
	Cursor::setHor(60);
	Print "Fire:     " << pc.GetFirePower() << FG_GRAY2;
	Cursor::setHor(85);
	Print "Fire:     " << pc.GetFireResist() << FG_GRAY2;
	Cursor::setPos(8, 17);
	Print "Stabbing: " << FG_VIOLET1 << pc.getDamStabbing() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Stabbing: " << FG_AZURE1 << pc.getResStabbing() << FG_GRAY2;
	Cursor::setHor(60);
	Print "Water:    " << pc.GetWaterPower() << FG_GRAY2;
	Cursor::setHor(85);
	Print "Water:    " << pc.GetWaterResist() << FG_GRAY2;
	Cursor::setPos(8, 18);
	Print "Bashing:  " << FG_VIOLET1 << pc.getDamSmashing() << FG_GRAY2;
	Cursor::setHor(34);
	Print "Bashing:  " << FG_AZURE1 << pc.getResSmashing() << FG_GRAY2;
	Cursor::setHor(60);
	Print "Earth:    " << pc.GetEarthPower() << FG_GRAY2;
	Cursor::setHor(85);
	Print "Earth:    " << pc.GetEarthResist() << FG_GRAY2;

	Cursor::setPos(5, 20);
	Print "Weapon: " << FG_WHITE << pc.getWeapon() << FG_GRAY2;
	Cursor::setHor(30);
	if (wide) Cursor::setHor(40);
	Print "Armor: " << FG_WHITE << pc.getArmor() << FG_GRAY2;
	Cursor::setHor(55);
	if (wide) Cursor::setHor(70);
	Print "Shield: " << FG_WHITE << pc.getShield() << FG_GRAY2;


	Print SGR_RESET;
	pressAnyKey();
}
void PC::statLine(PC& pc)
{
	//PC pc = *player;

	COORD size = CSL::getWindowSize();
	Cursor::setPos(1, size.Y - 1);
	Print FG_GRAY2 << "<Health: ";
	Print FG_RED1;
	Print pc.GetCurHealth() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print pc.GetMaxHealth() << FG_GRAY2 << "  ";
	Print FG_GRAY2 << "Spirit: ";
	Print FG_RED1;
	Print pc.GetCurSpirit() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print pc.GetMaxSpirit() << FG_GRAY2 << "  ";
	Print FG_GRAY2 << "Stamina: ";
	Print FG_RED1;	
	Print pc.GetCurStamina() << FG_GRAY1 << "/";
	Print FG_RED1;
	Print pc.GetMaxStamina() << FG_GRAY2 << ">: " << SGR_RESET << CUR_SHAPE_BAR_B;
}

void PC::save()
{
};
void PC::load()
{
};

#pragma endregion