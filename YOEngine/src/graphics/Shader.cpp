#include "Shader.h"


YO_UINT get_compiled_shader(YO_UINT type, const std::string& source) {
	YO_UINT shaderId = glCreateShader(type);

	const YO_CHAR* p[1];
	p[0] = source.data();
	YO_INT lengths[1];
	lengths[0] = source.length();

	glShaderSource(shaderId, 1, p, lengths);
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


namespace YOEngine {


	Shader::Shader(const std::string& path) {
		id = glCreateProgram();

		shaders[0] = get_compiled_shader(GL_VERTEX_SHADER, readFile(path + ".vs"));
		shaders[1] = get_compiled_shader(GL_FRAGMENT_SHADER, readFile(path + ".fs"));

		for (YO_UINT i = 0; i < 2; ++i) {
			glAttachShader(id, shaders[i]);
		}

		glBindAttribLocation(id, 0, "position");
		glBindAttribLocation(id, 1, "texCoord");
		glBindAttribLocation(id, 2, "normal");

		glLinkProgram(id);
		glValidateProgram(id);

		uniforms[TRANSFORM] = glGetUniformLocation(id, "transform");
	}


	Shader::~Shader() {
		for (YO_UINT i = 0; i < 2; ++i) {
			glDetachShader(id, shaders[i]);
			glDeleteShader(shaders[i]);
		}
		glDeleteProgram(id);
	}


	YO_VOID Shader::enable() {
		glUseProgram(id);
	}


	YO_VOID Shader::update(const Transform& transform, const Camera& camera) {
		mat4 model = camera.getViewProj() * transform.getModel();
		glUniformMatrix4fv(uniforms[TRANSFORM], 1, GL_FALSE, &model.data()[0]);
	}


	YO_UINT Shader::getId() {
		return id;
	}


}
