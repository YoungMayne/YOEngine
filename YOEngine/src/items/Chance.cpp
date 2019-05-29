#include "Chance.h"

namespace yo {

	//Put a chance between 0 and 100
	Chance::Chance(double chance) {
		this->chance = chance * 0.01;
	}


	//Put a chance between 0 and 100
	void Chance::setChance(double chance) {
		this->chance = chance * 0.01;
	}


	double Chance::getChance() {
		return chance;
	}


	int Chance::roll() {
		return chance >= (double)(rand() % 100) * 0.01;
	}

}
