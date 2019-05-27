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
		Ellipse(float x, float y, float radius);

		EllipseCoordinates getCoords();

		Color getColor();

		void fill(int state = 1);
		void segments(int segments);
		void setCoords(float x, float y, float width, float height);
		void setCoords(const EllipseCoordinates& coords);
		void setCoords(float x, float y, float radius);
		void setCoords(float x, float y);
		void setColor(const Color& col);
		void draw();
	private:
		EllipseCoordinates coords;
		Color color;

		int filling;

		float x0;
		float y0;
		float TWO_PI = 6.283;
		float step = TWO_PI / 100;
		float rx;
		float ry;
	};

}
