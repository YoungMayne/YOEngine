#pragma once
#include <iostream>
#include <glfw3.h>

#define YO_MAX_KEYS 1000
#define YO_MAX_BUTTONS 32

namespace yo {

	struct MouseCoords {
		int x;
		int y;
	};

	class Input {
	private:
		struct Button {
			int pressed;
			int released;
		};
	public:
		Input(GLFWwindow* handle)noexcept;

		int keyPressed(int keyCode)noexcept;
		int keyReleased(int keyCode)noexcept;

		int mousePressed(int buttonCode)noexcept;
		int mouseReleased(int buttonCode)noexcept;

		MouseCoords getMousePosition()noexcept;
	private:
		Button keys[YO_MAX_KEYS];
		Button buttons[YO_MAX_BUTTONS];

		MouseCoords mouse;
	};

}