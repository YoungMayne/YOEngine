#include "Vertex.h"


namespace YOEngine {


	YOEngine::Vertex::Vertex(const vec3& pos, const vec2& texCoord) {
		this->pos = pos;
		this->texCoord = texCoord;
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


	vec2 Vertex::getTex() const {
		return texCoord;
	}


	vec2& Vertex::getTex() {
		return texCoord;
	}


	Vertex& Vertex::operator=(const Vertex& vert) {
		return set(vert);
	}


	Vertex& Vertex::operator=(const vec3& vec) {
		return set(vec);
	}


}
