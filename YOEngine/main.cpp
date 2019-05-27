#include "src/YOEnginge.h"

#include <ctime>


#ifdef _DEBUG
int main() {
#else
int WinMain() {
#endif
	yo::Window window(640, 480, "window");
	yo::Input* input = window.getInputHandle();
	yo::Ellipse ellipse(320, 240, 50);
	ellipse.fill();
	while (!window.closed()) {
		//LOGIC
		if (input->mousePressed(0)) {
			ellipse.setCoords(input->getMousePosition().x, input->getMousePosition().y, rand() % 100);
			ellipse.setColor(yo::Color(rand() % 255, rand() % 255, rand() % 255));
		}

		window.clear();
		//DRAW 
		ellipse.draw();

		window.update();
	}

	return 0;
}