#include "src/YOEnginge.h"

#include <ctime>

#ifdef _DEBUG
int main() {
#else
int WinMain() {
#endif
	yo::Window window(640, 480, "Window");
	yo::Input* input = window.getInputHandle();
	while (!window.closed()) {
		//LOGIC
		
		window.clear();
		//DRAW 
		window.update();
	}
	return 0;
}