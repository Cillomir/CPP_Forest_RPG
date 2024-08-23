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
	Print "Strength: " << FG_ORANGE1 << getStrength() << FG_GRAY2;
	Cursor::setHor(21);
	if (wide) Cursor::setHor(25);
	Print "Fortitude: " << FG_AZURE1 << getFortitude() << FG_GRAY2;
	Cursor::setHor(37);
	if (wide) Cursor::setHor(40);
	Print "Agility: " << FG_GREEN1 << getAgility() << FG_GRAY2;
	Cursor::setHor(54);
	if (wide) Cursor::setHor(55);
	Print "Intellect: " << FG_CYAN1 << getIntellect() << FG_GRAY2;
	Cursor::setHor(70);
	if (wide) Cursor::setHor(70);
	Print "Wisdom: " << FG_YELLOW1 << getWisdom() << FG_GRAY2;

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
#pragma endregion