#include "renderer.h"

#include "../sprite.h"
#include "../types.h"
#include "../glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// this file should be the only file that includes glad, rendering should happen here

static uint VBO;
static uint VAO;
static uint EBO;
static mat4x4 ortho;

static int indices[6] = {
	0, 1, 2,
	2, 3, 1
};

int renderer_glInit() {
	return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

int renderer_init() {
	mat4x4_identity(ortho);
	mat4x4_ortho(ortho, 1, 1, 1, 1, 1, 1);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	return 1;
}

// other initalizing stuff here.
// im thinking that sprite.h and .c should basically just be a definition of what a sprite is 
// and this file handles the rendering of sprite things. the sprite c file can handle things like
// changing positon, rotation, scale, etc

void renderer_drawTest() {
	Sprite x;
	initSprite(&x);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), x.vertexData, GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	
}

