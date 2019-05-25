#pragma once
#include <iostream>
#include <glew.h>
#include <glfw3.h>

#include "../input/Input.h"

namespace yo {

	struct WindowCoords {
		int x;
		int y;
	};

	class Window {
	public:
		Window(int width, int height, const char* title)noexcept;
		~Window()noexcept;

		void clear()noexcept;
		void update()noexcept;

		int closed()noexcept;

		WindowCoords getWindowCoords()noexcept;

		Input* getInputHandle()noexcept;
	private:
		GLFWwindow* window;
		Input* input;
		const char* title;
		int         width;
		int         height;
	private:
		int init()noexcept;
	};

}