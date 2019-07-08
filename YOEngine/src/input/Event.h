#pragma once
#include <glew.h>
#include <glfw3.h>
#ifdef _DEBUG
#include <iostream>
#endif


#include "../items/Types.h"
#include "../graphics/Window.h"


#define YO_MAX_KEYS 1000
#define YO_MAX_BUTTONS 32

#define YO_MOUSE_LEFT 0
#define YO_MOUSE_RIGHT 1
#define YO_MOUSE_WHEEL 2


namespace YOEngine {


	class Event {
	public:
		Event                                   (const Window& wnd);

		YO_BOOL keyPressed                      (YO_UINT keyCode);
		YO_BOOL keyReleased                     (YO_UINT keyCode);
		YO_BOOL mousePressed                    (YO_UINT buttonCode);
		YO_BOOL mouseReleased                   (YO_UINT buttonCode);
	private:
		friend YO_VOID key_callback             (struct GLFWwindow* window, YO_INT key, YO_INT scancode, YO_INT action, YO_INT mods);
		friend YO_VOID mouse_button_callback    (struct GLFWwindow* window, YO_INT button, YO_INT action, YO_INT mods);
		friend YO_VOID cursor_position_callback (GLFWwindow* window, YO_DOUBLE xpos, YO_DOUBLE ypos);
	private:
		struct yoInptKey {
			YO_BOOL                             pressed;
			YO_BOOL                             released;
		};

		yoInptKey                               keys[YO_MAX_KEYS];
		yoInptKey                               buttons[YO_MAX_BUTTONS];

		YO_UINT                                 mouseX;
		YO_UINT                                 mouseY;
	};


}

