#include "Ellipse.h"


namespace yo {

	Ellipse::Ellipse() {
		Ellipse(0, 0, 0, 0);
	}


	Ellipse::Ellipse(float x, float y, float width, float height) {
		setCoords(x, y, width, height);
		color.set(color.getRGBA().r / 255, color.getRGBA().g / 255, color.getRGBA().b / 255, color.getRGBA().alpha);
		filling = false;
	}


	Ellipse::Ellipse(const EllipseCoordinates& coords) {
		Ellipse(coords.x, coords.y, coords.width, coords.height);
	}


	Ellipse::Ellipse(float x, float y, float radius) {
		setCoords(x, y, radius);
	}


	EllipseCoordinates Ellipse::getCoords() {
		return coords;
	}


	Color Ellipse::getColor() {
		Color col(color.getRGBA().r * 255, color.getRGBA().g * 255, color.getRGBA().b * 255, color.getRGBA().alpha);
		return col;
	}


	void Ellipse::fill(int state) {
		filling = state;
	}


	void Ellipse::segments(int segments) {
		step = TWO_PI / (float)segments;
	}


	void Ellipse::setCoords(float x, float y, float width, float height) {
		coords.x = x;
		coords.y = y;
		coords.width = width;
		coords.height = height;

		rx = coords.width * 0.5;
		ry = coords.height * 0.5;

		x0 = coords.x + coords.width * 0.5;
		y0 = coords.y + coords.height * 0.5;
	}


	void Ellipse::setCoords(const EllipseCoordinates& coords) {
		setCoords(coords.x, coords.y, coords.width, coords.height);
	}


	void Ellipse::setCoords(float x, float y, float radius) {
		setCoords(x, y, radius * 2, radius * 2);
		x0 = x;
		y0 = y;
	}


	void Ellipse::setCoords(float x, float y) {
		setCoords(x, y, coords.width, coords.height);
		x0 = x;
		y0 = y;
	}


	void Ellipse::setColor(const Color& col) {
		color.set(col.getRGBA().r / 255, col.getRGBA().g / 255, col.getRGBA().b / 255, col.getRGBA().alpha);
	}


	void Ellipse::draw() {

		glDisable(GL_BLEND);
		glPushMatrix();
		glColor4f(color.getRGBA().r, color.getRGBA().g, color.getRGBA().b, color.getRGBA().alpha);
		if (filling) {
			glBegin(GL_TRIANGLE_FAN);

		}
		else {
			glBegin(GL_LINE_STRIP);
		}
		for (float angle = 0; angle <= TWO_PI; angle += step) {
			float x = x0 + cos(angle) * rx;
			float y = y0 + sin(angle) * ry;
			glVertex2f(x, y);
		}
		glEnd();

		glPopMatrix();
		glEnable(GL_BLEND);
	}

}
