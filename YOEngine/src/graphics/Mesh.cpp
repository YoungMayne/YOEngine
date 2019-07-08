#include "Mesh.h"

#include <vector>


namespace YOEngine {


	Mesh::Mesh(const Vertex* vertices, YO_UINT num) {
		count = num;

		glGenVertexArrays(1, &object);
		glBindVertexArray(object);

		std::vector<vec3> pos;
		std::vector<vec2> tex;
		std::vector<vec3> color;

		for (YO_UINT i = 0; i < count; ++i) {
			pos.push_back(vertices[i].getPos());
			tex.push_back(vertices[i].getTexture());
			color.push_back(vertices[i].getColor());
		}

		glGenBuffers(BUFFERS_COUNT, buffers);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[POSITION]);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(pos[0]), &pos[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[TEXTURE]);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(tex[0]), &tex[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[COLOR]);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(color[0]), &color[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
		glBindVertexArray(0);
	}


	Mesh::~Mesh() {
		glDeleteVertexArrays(1, &object);
	}


	YO_VOID Mesh::draw() {
		glBindVertexArray(object);

		glDrawArrays(GL_TRIANGLES, 0, count);

		glBindVertexArray(0);
	}


}
