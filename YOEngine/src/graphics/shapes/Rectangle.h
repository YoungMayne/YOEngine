#pragma once
#include <glew.h>
#include <glfw3.h>

#include "../../items/Color.h"

namespace yo {

	struct RectangleCoordinates {
		float x;
		float y;
		float width;
		float height;
	};

	class Rectangle {
	public:
		Rectangle();
		Rectangle(float x, float y, float width, float height);
		Rectangle(const RectangleCoordinates& coords);

		RectangleCoordinates getCoords();

		Color getColor();

		int isFilling();

		void setCoords(float x, float y, float width, float height);
		void setCoords(const RectangleCoordinates& coords);
		void setColor(const Color& col);
		void fill(int status);
		void draw();
	private:
		RectangleCoordinates coords;
		Color color;

		int filling;
	};

}