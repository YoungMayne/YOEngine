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
		enum         {POS_VB, TEXCOORD_VB, NUM_BUFFERS};
		YO_UINT      object;
		YO_UINT      buffers[NUM_BUFFERS];
		YO_UINT      drawCount;
	};


}