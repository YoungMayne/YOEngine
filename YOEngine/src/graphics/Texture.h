#pragma once


#define STB_IMAGE_IMPLEMENTATION


#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <string>

#include "../items/Types.h"


namespace YOEngine {


	class Texture {
	public:
		Texture        (const std::string& file);
		~Texture       ();
	public:
		YO_VOID enable ();
	private:
		YO_UINT        texture;
	};


}