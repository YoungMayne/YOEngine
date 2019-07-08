#pragma once


#include <glew.h>
#include <glfw3.h>
#include <fstream>
#include <string>

#include "Types.h"


namespace YOEngine {


	inline std::string readFile(const std::string& path) {
		return std::string(std::istreambuf_iterator<char>(std::ifstream(path.c_str()).rdbuf()), std::istreambuf_iterator<char>());
	}


	inline YO_UINT loadShader(YO_UINT shaderType, const std::string& source) {
		YO_UINT shaderId = glCreateShader(shaderType);

		const YO_CHAR* shaderCode = source.data();

		glShaderSource(shaderId, 1, &shaderCode, nullptr);
		glCompileShader(shaderId);

		YO_INT result;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

#ifdef _DEBUG
		if (result == YO_FALSE) {
			std::cout << "Error loading shaders" << std::endl;
		}
#endif
		return shaderId;
	}


}