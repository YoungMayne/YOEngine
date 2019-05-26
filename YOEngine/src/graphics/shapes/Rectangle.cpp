#include "Rectangle.h"

namespace yo {

	yo::Rectangle::Rectangle() {
		Rectangle(0, 0, 0, 0);
	}


	Rectangle::Rectangle(float x, float y, float width, float height) {
		coords.x = x;
		coords.y = y;
		coords.width = width;
		coords.height = height;

		filling = false;
	}


	Rectangle::Rectangle(const RectangleCoordinates& coords) {
		Rectangle(coords.x, coords.y, coords.width, coords.height);
	}


	RectangleCoordinates Rectangle::getCoords() {
		return coords;
	}


	Color Rectangle::getColor() {
		return color;
	}


	int Rectangle::isFilling() {
		return filling;
	}


	void Rectangle::setCoords(float x, float y, float width, float height) {
		coords.x = x;
		coords.y = y;
		coords.width = width;
		coords.height = height;
	}


	void Rectangle::setCoords(const RectangleCoordinates& coords) {
		this->coords.x = coords.x;
		this->coords.y = coords.y;
		this->coords.width = coords.width;
		this->coords.height = coords.height;
	}


	void Rectangle::setColor(const Color& col) {
		filling = true;
		color.set(col.getRGBA().r / 255, col.getRGBA().g / 255, col.getRGBA().b / 255, col.getRGBA().alpha);
	}


	void Rectangle::fill(int status) {
		filling = status;
	}


	void Rectangle::draw() {
		glPushMatrix();
		glColor4f(color.getRGBA().r, color.getRGBA().g, color.getRGBA().b, color.getRGBA().alpha);
		if (!filling) {
			glBegin(GL_LINE_LOOP);
		}
		else {
			glBegin(GL_QUADS);
		}
		glVertex2f(coords.x, coords.y);
		glVertex2f(coords.x + coords.width, coords.y);
		glVertex2f(coords.x + coords.width, coords.y + coords.height);
		glVertex2f(coords.x, coords.y + coords.height);
		glEnd();
		glPopMatrix();
	}
}
