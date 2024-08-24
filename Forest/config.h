#pragma once
#ifndef CONFIG_H
#define CONFIG_H

class config
{
public:
	static const int pulse = 50; // milliseconds
	static const int tick = 500; // pulses (standard event)
	static const int corpse_time = 5; // ticks

	static const int minLevel = 1;
	static const int maxLevel = 10;
	static const int minGold = 0;
	static const int maxGold = 1000000;

};

#endif
