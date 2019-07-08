#include "Event.h"


namespace YOEngine {


	YO_VOID key_callback(struct GLFWwindow* window, YO_INT key, YO_INT scancode, YO_INT action, YO_INT mods) {
		Event* event = (Event*)glfwGetWindowUserPointer(window);

		if (key < YO_MAX_KEYS) {
			switch (action) {
			case GLFW_PRESS:
#ifdef _DEBUG
				std::cout << key << " key pressed" << std::endl;
#endif	
				event->keys[key].pressed = YO_TRUE;
				break;
			case GLFW_RELEASE:
#ifdef _DEBUG
				std::cout << key << " key released" << std::endl;
#endif	
				event->keys[key].released = YO_TRUE;
				event->keys[key].pressed = YO_FALSE;
				break;
			}
		}
	}


	YO_VOID mouse_button_callback(struct GLFWwindow* window, YO_INT button, YO_INT action, YO_INT mods) {
		Event* event = (Event*)glfwGetWindowUserPointer(window);

		if (button < YO_MAX_BUTTONS) {
			switch (action) {
			case GLFW_PRESS:
#ifdef _DEBUG
				std::cout << button << " button pressed" << std::endl;
#endif	
				event->buttons[button].pressed = YO_TRUE;
				break;
			case GLFW_RELEASE:
#ifdef _DEBUG
				std::cout << button << " button released" << std::endl;
#endif	
				event->buttons[button].released = YO_TRUE;
				event->buttons[button].pressed = YO_FALSE;
				break;
			}
		}
	}


	YO_VOID cursor_position_callback(GLFWwindow* window, YO_DOUBLE xpos, YO_DOUBLE ypos) {
		Event* event = (Event*)glfwGetWindowUserPointer(window);
#ifdef _DEBUG
		std::cout << "mouseX: " << xpos << " mouseY: " << ypos << std::endl;
#endif	
		event->mouseX = xpos;
		event->mouseY = ypos;
	}


	Event::Event(const Window& wnd) {
		for (YO_UINT i = 0; i < YO_MAX_KEYS; ++i) {
			keys[i].pressed = YO_FALSE;
			keys[i].released = YO_FALSE;
		}
		for (YO_UINT i = 0; i < YO_MAX_BUTTONS; ++i) {
			buttons[i].pressed = YO_FALSE;
			buttons[i].released = YO_FALSE;
		}

		glfwSetWindowUserPointer(wnd.window, this);

		glfwSetKeyCallback(wnd.window, key_callback);
		glfwSetMouseButtonCallback(wnd.window, mouse_button_callback);
		glfwSetCursorPosCallback(wnd.window, cursor_position_callback);
	}


	YO_BOOL Event::keyPressed(YO_UINT keyCode) {
		if (keyCode < YO_MAX_KEYS) {
			return keys[keyCode].pressed;
		}
		return YO_FALSE;
	}


	YO_BOOL Event::keyReleased(YO_UINT keyCode) {
		if (keyCode < YO_MAX_KEYS) {
			if (keys[keyCode].released) {
				keys[keyCode].released = YO_FALSE;
				return YO_TRUE;
			}
		}
		return YO_FALSE;
	}


	YO_BOOL Event::mousePressed(YO_UINT buttonCode) {
		if (buttonCode < YO_MAX_BUTTONS) {
			return buttons[buttonCode].pressed;
		}
		return YO_FALSE;
	}


	YO_BOOL Event::mouseReleased(YO_UINT buttonCode) {
		if (buttonCode < YO_MAX_BUTTONS) {
			if (buttons[buttonCode].released) {
				buttons[buttonCode].released = YO_FALSE;
				return YO_TRUE;
			}
		}
		return YO_FALSE;
	}


}