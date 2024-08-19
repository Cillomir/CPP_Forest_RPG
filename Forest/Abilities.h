#pragma once
#include <string>
#include <vector>
#include <map>

#ifndef ABILITIES_H
#define ABILITIES_H

namespace Abilities
{
	class Skill
	{
	private:
		std::string _name;
		int _level;
		float _training;
		int _useCost;

	public:
		Skill()
		{
			_name = "";
			_level = 1;
			_training = 0;
			_useCost = 1;
		}
	};

	class Spell
	{
	private:
		std::string _name;
		int _level;
		float _training;
		int _useCost;

	public:
		Spell()
		{
			_name = "";
			_level = 1;
			_training = 0;
			_useCost = 1;
		}

	};
}
#endif