#pragma once
#include <glew.h>
#include <glfw3.h>

#include "../../items/Color.h"

namespace yo {

	struct LineCoordinates {
		float xBegin;
		float xEnd;
		float yBegin;
		float yEnd;
	};

	class Line {
	public:
		Line();
		Line(float xBegin, float xEnd, float yBegin, float yEnd);
		Line(const LineCoordinates& coords);

		LineCoordinates getCoords();

		Color getColor();

		float getLineThickness();

		void setCoords(float xBegin, float yBegin, float xEnd, float yEnd);
		void setCoords(const LineCoordinates& coords);
		void setColor(const Color& col);
		void lineThickness(float thickness);
		void draw();
	private:
		float thickness;
		LineCoordinates coords;
		Color color;
	};

}