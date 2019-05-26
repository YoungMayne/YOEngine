#include "src/YOEnginge.h"

#include <ctime>


#ifdef _DEBUG
int main() {
#else
int WinMain() {
#endif
	yo::Window window(640, 480, "window");
	yo::Input* input = window.getInputHandle();
	yo::Ellipse rect(50, 50, 150, 300);
	while (!window.closed()) {
		//LOGIC

		window.clear();

		//DRAW 
		rect.draw();
		window.update();
	}

	return 0;
}