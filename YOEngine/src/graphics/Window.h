#pragma once
#include <iostream>
#include <glew.h>
#include <glfw3.h>

#include "../input/Input.h"

namespace yo {

	struct WindowState {
		int x;
		int y;
		int width;
		int height;
		const char* title;
	};

	class Window {
	public:
		Window(int width, int height, const char* title)noexcept;
		~Window()noexcept;

		void clear()noexcept;
		void update()noexcept;

		int closed()noexcept;

		WindowState getWindowState()noexcept;

		Input* getInputHandle()noexcept;
	private:
		GLFWwindow* window;
		Input* input;
		WindowState state;
	private:
		int init()noexcept;
	};

}