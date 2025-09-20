#version 330

in vec2 texCoord;
in vec4 color;

out vec4 fragment;

void main() {
	fragment = vec4(color);
};
