#pragma once
#include <iostream>
#include <ctime>

namespace yo {

	class Chance {
	public:
		Chance(double chance);

		void setChance(double chance);

		double getChance();

		int roll();
	private:
		double chance;
	};

}
