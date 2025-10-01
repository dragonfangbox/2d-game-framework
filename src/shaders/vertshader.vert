#version 330

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec2 vTexCoord;
layout(location = 2) in vec4 vCol;

out vec2 texCoord;
out vec4 color;

void main() {
	gl_Position = vec4(vPos, 1.0);
	texCoord = vTexCoord;
	color = vCol;
};
