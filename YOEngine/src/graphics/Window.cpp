#include "Window.h"

namespace yo {

	Window::Window(int width, int height, const char* title) noexcept {
		this->width = width;
		this->height = height;
		this->title = title;
		if (!init()) {
#ifdef _DEBUG
			std::cout << "Window init faied" << std::endl;
			system("pause");
#endif
			exit(EXIT_FAILURE);
		}
	}


	Window::~Window() noexcept {
		glfwDestroyWindow(window);
		glfwTerminate();
	}


	int Window::init() noexcept {
		if (!glfwInit()) {
#ifdef _DEBUG
			std::cout << "glfw init failed" << std::endl;
#endif
			glfwTerminate();
			return 0;
		}

		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL) {
#ifdef _DEBUG
			std::cout << "Window creation failed" << std::endl;
#endif
			glfwTerminate();
			return 0;
		}

		input = new Input(window);
		glfwMakeContextCurrent(window);

		//set callbacks
		glfwSetErrorCallback([](int error, const char* description) { std::cout << "Error: " << description << std::endl; });
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

		if (glewInit() != GLEW_OK) {
#ifdef _DEBUG
			std::cout << "glew init failed" << std::endl;
#endif
			return 0;
		}
		return 1;
	}


	void Window::clear() noexcept {
		glClear(GL_COLOR_BUFFER_BIT);
	}


	void Window::update() noexcept {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	int Window::closed() noexcept {
		return glfwWindowShouldClose(window);
	}


	WindowCoords Window::getWindowCoords() noexcept {
		WindowCoords coords;
		glfwGetWindowPos(window, &coords.x, &coords.y);
		return coords;
	}


	Input* Window::getInputHandle() noexcept {
		return input;
	}

}