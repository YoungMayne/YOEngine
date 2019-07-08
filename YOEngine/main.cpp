#include <iostream>

#include "src/YOEngine.h"


#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 800


int STARTENGINE() {
	YOEngine::Window window(DISPLAY_WIDTH, DISPLAY_HEIGHT, "window");
	YOEngine::Event event(window);
	YOEngine::Shader shader("resourses/shaders/vs");
	YOEngine::Texture texture("resourses/textures/bricks.jpg");
	YOEngine::Camera camera({ 0, 0, 3 }, 45.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, -0.01, 1000.0f);
	YOEngine::Transform transform;

	YO_FLOAT vSize = 0.5f;

	YOEngine::Vertex vertices[] = {
		//FACE
		YOEngine::Vertex({-vSize, -vSize,  vSize}, 0, {0, 0}),
		YOEngine::Vertex({-vSize,  vSize,  vSize}, 0, {0, 1}),
		YOEngine::Vertex({ vSize, -vSize,  vSize}, 0, {1, 0}),

		YOEngine::Vertex({ vSize, -vSize,  vSize}, 0, {1, 0}),
		YOEngine::Vertex({ vSize,  vSize,  vSize}, 0, {1, 1}),
		YOEngine::Vertex({-vSize,  vSize,  vSize}, 0, {0, 1}),
		//TOP
		YOEngine::Vertex({-vSize,  vSize,  vSize}, 0, {0, 0}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		YOEngine::Vertex({ vSize,  vSize,  vSize}, 0, {1, 0}),

		YOEngine::Vertex({ vSize,  vSize,  vSize}, 0, {1, 0}),
		YOEngine::Vertex({ vSize,  vSize, -vSize}, 0, {1, 1}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		//BACK
		YOEngine::Vertex({-vSize, -vSize, -vSize}, 0, {0, 0}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		YOEngine::Vertex({ vSize, -vSize, -vSize}, 0, {1, 0}),

		YOEngine::Vertex({ vSize, -vSize, -vSize}, 0, {1, 0}),
		YOEngine::Vertex({ vSize,  vSize, -vSize}, 0, {1, 1}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		//BOTTOM
		YOEngine::Vertex({-vSize, -vSize,  vSize}, 0, {0, 0}),
		YOEngine::Vertex({-vSize, -vSize, -vSize}, 0, {0, 1}),
		YOEngine::Vertex({ vSize, -vSize,  vSize}, 0, {1, 0}),

		YOEngine::Vertex({ vSize, -vSize,  vSize}, 0, {1, 0}),
		YOEngine::Vertex({ vSize, -vSize, -vSize}, 0, {1, 1}),
		YOEngine::Vertex({-vSize, -vSize, -vSize}, 0, {0, 1}),
		//LEFT
		YOEngine::Vertex({-vSize, -vSize, -vSize}, 0, {0, 0}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		YOEngine::Vertex({-vSize, -vSize,  vSize}, 0, {1, 0}),

		YOEngine::Vertex({-vSize, -vSize,  vSize}, 0, {1, 0}),
		YOEngine::Vertex({-vSize,  vSize,  vSize}, 0, {1, 1}),
		YOEngine::Vertex({-vSize,  vSize, -vSize}, 0, {0, 1}),
		//RIGHT
		YOEngine::Vertex({ vSize, -vSize,  vSize}, 0, {0, 0}),
		YOEngine::Vertex({ vSize,  vSize,  vSize}, 0, {0, 1}),
		YOEngine::Vertex({ vSize, -vSize, -vSize}, 0, {1, 0}),

		YOEngine::Vertex({ vSize, -vSize, -vSize}, 0, {1, 0}),
		YOEngine::Vertex({ vSize,  vSize, -vSize}, 0, {1, 1}),
		YOEngine::Vertex({ vSize,  vSize,  vSize}, 0, {0, 1}),
	};
	YOEngine::Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	float counter = 0.0f;

	shader.enable();

	while (!window.closed()) {
		transform.getRotation().X() = counter;
		transform.getRotation().Y() = counter;
		//transform.getRotation().Z() = counter;

		window.clear();

		texture.enable();
		shader.update(transform, camera);
		mesh.draw();

		window.update();
		counter += 0.01f;
	}

	return 0;
}
