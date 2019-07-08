#include "Texture.h"
#include "../dependencies/stb_image.h"


namespace YOEngine {


	Texture::Texture(const std::string& file) {		
		YO_INT params[3];//params[0] - width
						 //params[1] - height
						 //params[2] - components number
		YO_UCHAR* image = stbi_load(file.c_str(), &params[0], &params[1], &params[2], 4);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, params[0], params[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		stbi_image_free(image);
	}


	Texture::~Texture() {
		glDeleteTextures(1, &texture);
	}


	YO_VOID Texture::enable() {
		glActiveTexture(GL_TEXTURE0 + texture);
		glBindTexture(GL_TEXTURE_2D, texture);
	}


}