#version 400 core

attribute vec3 position;
attribute vec2 texture;

varying vec2 texCoord;

uniform mat4 transform;

void main() {
	gl_Position = transform * vec4(position, 1.5f);
	texCoord = texture;
}