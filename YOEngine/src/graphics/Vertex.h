#pragma once


#include "../Types.h"
#include "../math/vec3.h"
#include "../math/vec2.h"


namespace YOEngine {


	class Vertex {
	public:
		Vertex            (const vec3& pos, const vec2& texCoord);
	public:
		Vertex& set       (const Vertex& vert);
		Vertex& set       (const vec3& vec);

		vec3 getPos       ()const;
		vec3& getPos      ();

		vec2 getTex       ()const;
		vec2& getTex      ();
	public:
		Vertex& operator= (const Vertex& vert);
		Vertex& operator= (const vec3& vec);
	private:
		vec3              pos;
		vec2              texCoord;
	};


}