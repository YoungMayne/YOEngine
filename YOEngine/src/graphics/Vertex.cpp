#include "Vertex.h"


namespace YOEngine {


	YOEngine::Vertex::Vertex(const vec3& pos, const vec3& color, const vec2& texture) {
		this->pos = pos;
		this->color = color;
		this->texture = texture;
	}


	Vertex& Vertex::set(const Vertex& vert) {
		pos.set(vert.pos);
		return *this;
	}


	Vertex& Vertex::set(const vec3& vec) {
		pos.set(vec);
		return *this;
	}


	vec3 Vertex::getPos() const {
		return pos;
	}


	vec3& Vertex::getPos() {
		return pos;
	}


	vec3 Vertex::getColor() const {
		return color;
	}


	vec3& Vertex::getColor() {
		return color;
	}


	vec2 Vertex::getTexture() const {
		return texture;
	}


	vec2& Vertex::getTexture() {
		return texture;
	}


	Vertex& Vertex::operator=(const Vertex& vert) {
		return set(vert);
	}


	Vertex& Vertex::operator=(const vec3& vec) {
		return set(vec);
	}


}
