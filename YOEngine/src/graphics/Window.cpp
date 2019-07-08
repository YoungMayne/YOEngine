#include "Window.h"

#include <Windows.h>


namespace YOEngine {


	Window::Window(YO_STRING title) : Window(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), title, YO_TRUE) {}


	YOEngine::Window::Window(YO_UINT width, YO_UINT height, YO_STRING title, YO_BOOL borderless) {
		this->title = title;
		this->width = width;
		this->height = height;

#ifdef _DEBUG
		if (!glfwInit()) {
			std::cout << "glfwInit failed" << std::endl;
			glfwTerminate();
		}
#else
		glfwInit();
#endif

		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_DECORATED, !borderless);

		window = glfwCreateWindow(width, height, title, NULL, NULL);

		setPos(GetSystemMetrics(SM_CXSCREEN) * 0.5 - (width * 0.5), GetSystemMetrics(SM_CYSCREEN) * 0.5 - height * 0.5);

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

#ifdef _DEBUG
		if (glewInit() != GLEW_OK) {
			std::cout << "glewInit failed" << std::endl;
	}
#else
		glewInit();
#endif
		std::cout << glGetString(GL_VERSION) << std::endl;

		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}


	YO_VOID Window::resize(YO_UINT width, YO_UINT height) {
		glfwSetWindowSize(window, this->width = width, this->height = height);
	}


	vec2 Window::getSize() {
		return { (YO_FLOAT)width, (YO_FLOAT)height };
	}


	YO_VOID Window::setPos(YO_UINT x, YO_UINT y) {
		glfwSetWindowPos(window, x, y);
	}


	YO_VOID Window::getPos(YO_INT& x, YO_INT& y) const {
		glfwGetWindowPos(window, &x, &y);
	}


	YO_VOID Window::setTitle(YO_STRING title) {
		glfwSetWindowTitle(window, this->title = title);
	}


	YO_VOID Window::close() {
		glfwSetWindowShouldClose(window, YO_TRUE);
	}


	YO_VOID Window::focus() {
		glfwFocusWindow(window);
	}


	YO_STRING Window::getTitle() const {
		return title;
	}


	YO_VOID Window::setVisibility(YO_BOOL status) {
		if (status) {
			glfwShowWindow(window);
		}
		else {
			glfwHideWindow(window);
		}
	}


	YO_VOID Window::setOpacity(YO_FLOAT value) {
		glfwSetWindowOpacity(window, value);
	}


	YO_FLOAT Window::getOpacity() const {
		return glfwGetWindowOpacity(window);
	}


	YO_VOID Window::vsync(YO_BOOL status) {
		glfwSwapInterval(status);
	}


	YO_BOOL Window::getVisibility() const {
		return glfwGetWindowAttrib(window, GLFW_VISIBLE);
	}


	YO_VOID Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	YO_VOID Window::update() {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	YO_BOOL Window::closed() const {
		return glfwWindowShouldClose(window);
	}


}