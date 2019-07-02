#include <iostream>

#include "src/YOEngine.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 800

using namespace YOEngine;


int STARTENGINE() {
	Window window(DISPLAY_WIDTH, DISPLAY_HEIGHT, "window");
	Event event(window);
	Shader shader("src/shaders/vs");
	Texture texture("src/textures/bricks.jpg");
	Camera camera({ 0, 0, -300 }, 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 1, 1000.0f);
	Transform transform;

	Vertex vertices[] = {
		Vertex({-0.5, -0.5, 0}, {0, 0}),
		Vertex({0, 0.5, 0}, {0.5, 1.0}),
		Vertex({0.5, -0.5, 0}, {1.0, 0.0})
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	YO_FLOAT counter = 0.0f;
	
	shader.enable();
	while (!window.closed()) {

		float sinCounter = sinf(counter);
		float absSinCounter = abs(sinCounter);

		transform.getRotation().X() = counter;

		window.clear();
				
		shader.enable();
		texture.enable(0);
		shader.update(transform, camera);
		mesh.draw();

		window.update();
		counter += 0.0001f;
	}

	return 0;
}
