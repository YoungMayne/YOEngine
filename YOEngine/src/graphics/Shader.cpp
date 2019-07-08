#include "Shader.h"


namespace YOEngine {


	Shader::Shader(const std::string& path) {
		id = glCreateProgram();

		shaders[VERTEX] = loadShader(GL_VERTEX_SHADER, readFile(path + ".vs"));
		shaders[FRAGMENT] = loadShader(GL_FRAGMENT_SHADER, readFile(path + ".fs"));

		for (YO_UINT i = 0; i < NUM_SHADERS; ++i) {
			glAttachShader(id, shaders[i]);
		}

		glBindAttribLocation(id, 0, "position");
		glBindAttribLocation(id, 1, "texture");
		glBindAttribLocation(id, 2, "color");

		glLinkProgram(id);
		glValidateProgram(id);

		for (YO_UINT i = 0; i < NUM_SHADERS; ++i) {
			glDeleteShader(shaders[i]);
		}

		uniforms[TRANSFORM] = glGetUniformLocation(1, "transform");
	}


	Shader::~Shader() {
		glDeleteProgram(id);
	}


	YO_VOID Shader::enable() {
		glUseProgram(id);
	}


	YO_VOID Shader::update(const Transform& transform, const Camera& camera) {
		mat4 model = camera.getViewProj() * transform.getModel();
		glUniformMatrix4fv(uniforms[TRANSFORM], 1, GL_FALSE, &model[0][0]);
	}


	YO_UINT Shader::getId() {
		return id;
	}


}
