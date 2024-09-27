// amory acosta - copyright 2024

#pragma once

#include "CoreMinimal.h"

class UNDONE_API Stat {
public:
	Stat(uint32_t _current, uint32_t _max);

	uint32_t current = 0;
	uint32_t max = 0;

	Stat & operator += (int rhs);
	Stat & operator -= (int rhs);
};

class UNDONE_API Combatant {
public:
	Combatant();
	~Combatant();
};
