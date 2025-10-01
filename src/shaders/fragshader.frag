#version 330

in vec2 texCoord;
in vec4 color;

out vec4 fragment;

uniform sampler2D tex0;

void main() {
	fragment = texture(tex0, texCoord) * vec4(color);
};
