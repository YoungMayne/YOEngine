#pragma once


#include <glew.h>
#include <glfw3.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "../Types.h"


namespace YOEngine {


	class Window {
	public:
		friend class          Event;
	public:
		Window                (YO_STRING title);
		Window                (YO_UINT width, YO_UINT height, YO_STRING title, YO_BOOL borderless = YO_FALSE);
		~Window               ();

		YO_VOID resize        (YO_UINT width, YO_UINT height);
		YO_VOID getSize       (YO_INT& width, YO_INT height);

		YO_VOID setPos        (YO_UINT x, YO_UINT y);
		YO_VOID getPos        (YO_INT& x, YO_INT& y)const;

		YO_VOID setTitle      (YO_STRING title);
		YO_STRING getTitle    ()const;

		YO_VOID setVisibility (YO_BOOL status);
		YO_BOOL getVisibility ()const;

		YO_VOID setOpacity    (YO_FLOAT value);
		YO_FLOAT getOpacity   ()const;

		YO_VOID vsync         (YO_BOOL status);
		YO_VOID close         ();
		YO_VOID focus         ();
		YO_VOID clear         ();
		YO_VOID update        ();

		YO_BOOL closed        ()const;
	protected:
		GLFWwindow*           window;
		YO_BOOL               terminated;
		YO_STRING             title;
		YO_INT                height;
		YO_INT                width;
	};


}
