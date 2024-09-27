// amory acosta - copyright 2024


#include "Combatant.h"

Stat::Stat(uint32_t _current, uint32_t _max) {
	current = _current;
	max = _max;
}

Stat & Stat::operator += (int rhs) {
	current += rhs;
	std::clamp((int)current, 0, (int)max);

	return *this;
}

Stat & Stat::operator -= (int rhs) {
	rhs = std::clamp(rhs, 0, (int)current);

	current -= rhs;

	std::clamp((int)current, 0, (int)max);

	return *this;
}

Combatant::Combatant() {

}

Combatant::~Combatant() {

}
