// amory acosta - copyright 2024

#pragma once

#include "CoreMinimal.h"

#include <cstdint>

// Stats

class Stat {

};

class HealthStat : public Stat {

};

class SpeedStat : public Stat {

};

// Statuses

class Status { };

class TimedStatus : public Status {
public:
	virtual std::uint32_t rounds() = 0;
	std::uint32_t cure_timer = 0;

	void update_countdown() {
		cure_timer++;
		
		if (cure_timer == rounds()) {

		}
	}
};

// Combatants

class UNDONE_API Combatant {
public:
	Combatant();
	~Combatant();

	HealthStat health;
	SpeedStat speed;
};
