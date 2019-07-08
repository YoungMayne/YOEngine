#pragma once


#include <glew.h>
#include <glfw3.h>

#include "Vertex.h"


namespace YOEngine {


	class Mesh {
	public:
		Mesh         (const Vertex* vertices, YO_UINT num);
		~Mesh        ();
	public:
		YO_VOID draw ();
	private:
		enum         {POSITION, TEXTURE, COLOR, BUFFERS_COUNT};
		YO_UINT      object;
		YO_UINT      buffers[BUFFERS_COUNT];
		YO_UINT      count;
	};


}