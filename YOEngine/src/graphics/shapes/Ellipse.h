#pragma once
#include <glew.h>
#include <glfw3.h>
#include <cmath>

#include "../../items/Color.h"

namespace yo {

	struct EllipseCoordinates {
		float x;
		float y;
		float width;
		float height;
	};

	class Ellipse {
	public:
		Ellipse();
		Ellipse(float x, float y, float width, float height);
		Ellipse(const EllipseCoordinates& coords);

		void draw();
	private:
		EllipseCoordinates coords;

		int filling = false;

		float TWO_PI = 6.283;
		float step = TWO_PI / 100;
		float rx;
		float ry;
	};

}
