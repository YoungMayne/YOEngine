#pragma once


#include "../items/Types.h"
#include "../math/vec4.h"
#include "../math/vec3.h"
#include "../math/vec2.h"


namespace YOEngine {


	class Vertex {
	public:
		Vertex            (const vec3& pos, const vec3& color = vec3(), const vec2& texture = vec2());
	public:
		Vertex& set       (const Vertex& vert);
		Vertex& set       (const vec3& vec);

		vec3 getPos       ()const;
		vec3& getPos      ();

		vec3 getColor     ()const;
		vec3& getColor    ();

		vec2 getTexture   ()const;
		vec2& getTexture  ();
	public:
		Vertex& operator= (const Vertex& vert);
		Vertex& operator= (const vec3& vec);
	private:
		vec3              pos;
		vec3              color;
		vec2              texture;
	};


}