#pragma once


#include <glew.h>
#include <glfw3.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "../items/Types.h"
#include "../items/Utils.h"
#include "Transform.h"
#include "Camera.h"


namespace YOEngine {


	class Shader {
	public:
		Shader          (const std::string& path);
		~Shader         ();

		YO_VOID enable  ();
		YO_VOID update  (const Transform& transform, const Camera& camera);

		YO_UINT getId   ();
	private:
		enum            {VERTEX, FRAGMENT, NUM_SHADERS};
		enum            {TRANSFORM, NUM_UNIFORMS};
		YO_UINT         id;
		YO_UINT         uniforms[NUM_UNIFORMS];
		YO_UINT         shaders[NUM_SHADERS];
	};


}