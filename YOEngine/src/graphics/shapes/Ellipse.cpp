#include "Ellipse.h"

void DrawEllipse(float cx, float cy, float rx, float ry, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cos(theta);//precalculate the sine and cosine
	float s = sin(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments; i++)
	{
		//apply radius and offset
		glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

namespace yo {

	Ellipse::Ellipse() {
		Ellipse(0, 0, 0, 0);
	}


	Ellipse::Ellipse(float x, float y, float width, float height) {
		coords.x = x;
		coords.y = y;
		coords.width = width;
		coords.height = height;

		rx = coords.width * 0.5;
		ry = coords.height * 0.5;
	}


	Ellipse::Ellipse(const EllipseCoordinates& coords) {
		Ellipse(coords.x, coords.y, coords.width, coords.height);
	}


	void Ellipse::draw() {
		float x0 = coords.x + coords.width * 0.5;
		float y0 = coords.y + coords.height * 0.5;

		glPushMatrix();

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
	}

}
