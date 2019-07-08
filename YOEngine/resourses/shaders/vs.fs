#version 400 core

varying vec2 texCoord;

uniform sampler2D diffuse;

void main(){
	gl_FragColor = texture2D(diffuse, texCoord);
}