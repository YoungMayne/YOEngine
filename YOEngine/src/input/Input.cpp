#include "Input.h"

namespace yo {

	yo::Input::Input(GLFWwindow* handle) noexcept {
		for (int i = 0; i < YO_MAX_KEYS; ++i) {
			keys[i].pressed = false;
			keys[i].released = false;
		}

		for (int i = 0; i < YO_MAX_BUTTONS; ++i) {
			buttons[i].pressed = false;
			buttons[i].released = false;
		}

		glfwSetWindowUserPointer(handle, this);

		//set callbacks
		glfwSetKeyCallback(handle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			if (key < YO_MAX_KEYS)
				if (action == GLFW_PRESS) {
					input->keys[key].pressed = true;
#ifdef _DEBUG
					std::cout << "Key: " << key << " Pressed" << std::endl;
#endif
				}
				else if (action == GLFW_RELEASE) {
					input->keys[key].released = true;
#ifdef _DEBUG
					std::cout << "Key: " << key << " Released" << std::endl;
#endif
				}
			});

		glfwSetMouseButtonCallback(handle, [](GLFWwindow* window, int button, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			if (button < YO_MAX_BUTTONS)
				if (action == GLFW_PRESS) {
					input->buttons[button].pressed = true;
#ifdef _DEBUG
					std::cout << "Button: " << button << " Pressed" << std::endl;
#endif
				}
				else if (action == GLFW_RELEASE) {
					input->buttons[button].released = true;
#ifdef _DEBUG
					std::cout << "Button: " << button << " Released" << std::endl;
#endif
				}
			});

		glfwSetCursorPosCallback(handle, [](GLFWwindow* window, double xpos, double ypos) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->mouse.x = xpos;
			input->mouse.y = ypos;
#ifdef _DEBUG
			std::cout << "x: " << input->mouse.x << " y: " << input->mouse.y << std::endl;
#endif
			});
	}


	int Input::keyPressed(int keyCode) noexcept {
		if (keyCode < YO_MAX_KEYS) {
			if (keys[keyCode].pressed) {
				keys[keyCode].pressed = false;
				return true;
			}
		}
		return false;
	}


	int Input::keyReleased(int keyCode) noexcept {
		if (keyCode < YO_MAX_KEYS) {
			if (keys[keyCode].released) {
				keys[keyCode].released = false;
				return true;
			}
		}
		return false;
	}


	int Input::mousePressed(int buttonCode) noexcept {
		if (buttonCode < YO_MAX_BUTTONS) {
			if (buttons[buttonCode].pressed) {
				buttons[buttonCode].pressed = false;
				return true;
			}
		}
		return false;
	}


	int Input::mouseReleased(int buttonCode) noexcept {
		if (buttonCode < YO_MAX_BUTTONS) {
			if (buttons[buttonCode].released) {
				buttons[buttonCode].released = false;
				return true;
			}
		}
		return false;
	}


	MouseCoords Input::getMousePosition() noexcept {
		return mouse;
	}

}