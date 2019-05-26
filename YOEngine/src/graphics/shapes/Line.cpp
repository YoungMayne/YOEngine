#include "Line.h"

namespace yo {

	Line::Line() {
		Line(0, 0, 0, 0);
	}


	Line::Line(float xBegin, float yBegin, float xEnd, float yEnd) {
		coords.xBegin = xBegin;
		coords.yBegin = yBegin;
		coords.xEnd = xEnd;
		coords.yEnd = yEnd;

		thickness = 1;
		color.set(color.getRGBA().r / 255, color.getRGBA().g / 255, color.getRGBA().b / 255);
	}


	Line::Line(const LineCoordinates& coords) {
		Line(coords.xBegin, coords.yBegin, coords.xEnd, coords.yEnd);
	}


	LineCoordinates Line::getCoords() {
		return coords;
	}


	Color Line::getColor() {
		Color col(color.getRGBA().r * 255, color.getRGBA().g * 255, color.getRGBA().b * 255, color.getRGBA().alpha);
		return col;
	}


	float Line::getLineThickness() {
		return thickness;
	}


	void Line::setCoords(float xBegin, float yBegin, float xEnd, float yEnd) {
		coords.xBegin = xBegin;
		coords.yBegin = yBegin;
		coords.xEnd = xEnd;
		coords.yEnd = yEnd;
	}


	void Line::setCoords(const LineCoordinates& coords) {
		setCoords(coords.xBegin, coords.yBegin, coords.xEnd, coords.yEnd);
	}


	void Line::setColor(const Color& col) {
		color.set(col.getRGBA().r / 255, col.getRGBA().g / 255, col.getRGBA().b / 255, col.getRGBA().alpha);
	}


	void Line::lineThickness(float thickness) {
		this->thickness = thickness;
	}


	void Line::draw() {
		float line[] = { coords.xBegin, coords.yBegin, 0, coords.xEnd, coords.yEnd, 0 };

		glPushMatrix();

		glColor4f(color.getRGBA().r, color.getRGBA().g, color.getRGBA().b, color.getRGBA().alpha);
		glLineWidth(thickness);

		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_LINE_STIPPLE);
		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, line);
		glDrawArrays(GL_LINES, 0, 2);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_LINE_SMOOTH);

		glPopMatrix();
	}

}