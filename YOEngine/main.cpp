#include "src/graphics/Window.h"

#ifdef _DEBUG
int main() {
#else
int WinMain() {
#endif
	yo::Window window(640, 480, "window");
	yo::Input* input = window.getInputHandle();

	while (!window.closed()) {

		if (input->keyPressed(32)) {
			std::cout << "Space is held" << std::endl;
		}

		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glEnd();
		window.update();
	}

	return 0;
}