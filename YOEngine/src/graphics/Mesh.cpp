#include "Mesh.h"

#include <vector>


namespace YOEngine {


	Mesh::Mesh(const Vertex* vertices, YO_UINT num) {
		drawCount = num;

		glGenVertexArrays(1, &object);
		glBindVertexArray(object);

		std::vector<vec3> poss;
		std::vector<vec2> texCoords;

		poss.reserve(num);
		texCoords.reserve(num);

		for (YO_UINT i = 0; i < num; ++i) {
			poss.push_back(vertices[i].getPos());
			texCoords.push_back(vertices[i].getTex());
		}

		glGenBuffers(NUM_BUFFERS, buffers);
		glBindBuffer(GL_ARRAY_BUFFER, buffers[POS_VB]);
		glBufferData(GL_ARRAY_BUFFER, num * sizeof(poss[0]), &poss[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


		glBindBuffer(GL_ARRAY_BUFFER, buffers[TEXCOORD_VB]);
		glBufferData(GL_ARRAY_BUFFER, num * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(0);
	}


	Mesh::~Mesh() {
		glDeleteVertexArrays(1, &object);
	}


	YO_VOID Mesh::draw() {
		glBindVertexArray(object);

		glDrawArrays(GL_TRIANGLES, 0, drawCount);

		glBindVertexArray(0);
	}


}
