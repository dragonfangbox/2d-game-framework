#include <stdio.h>
#include <stdlib.h>

#include "src/debug.h"
#include "src/glad.h"
#include "src/image.h"
#include "src/sprite.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "src/shader.h"
#include "src/graphics/renderer.h"

void keyPressedCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebufferSizeCallBack(GLFWwindow* window, int width, int height);

int main() {

	//TODO put all this glfw stuff into the renderer
	// update the projection matrix inside the framebufferSizeCallBack func( make sure the resend the new matrix to the shader)
	// yuh
	
	if(!renderer_glfwInit(3, 3)) {
		printf("GLFW FAILED TO LOAD\n");
		return 1;
	}

	GLFWwindow* win = renderer_newWindow(920, 780, "aklfhihjkafg");
	glfwSetKeyCallback(win, keyPressedCallback);
	glfwSetFramebufferSizeCallback(win, framebufferSizeCallBack);

	if(!renderer_glInit()) {
		printf("GLAD FAILED TO LOAD\n");
		return 1;
	}

	glViewport(0, 0, 920, 780);

	renderer_init();

	char* vertshadersrc = ReadShader("./src/shaders/vertshader.vert");
	char* fragshadersrc = ReadShader("./src/shaders/fragshader.frag");

	uint vertShader;
	CreateShader(&vertShader, vertshadersrc, GL_VERTEX_SHADER);

	uint fragShader;
	CreateShader(&fragShader, fragshadersrc, GL_FRAGMENT_SHADER);

	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	unsigned char* image = image_loadImage("assets/scribble.xcf");
	uint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D()

	Sprite x;
	setSpriteImage(&x, image);
	initSprite(&x);

	while(!glfwWindowShouldClose(win)) {
		glfwPollEvents();

		glClearColor(0.2, 0.4, 0.7, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program);
		renderer_drawSprite(&x);

		glfwSwapBuffers(win);
	}

	free(vertshadersrc);
	free(fragshadersrc);
	image_freeImage(image);

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}


void keyPressedCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		printf("closing wndow...\n");
	    glfwSetWindowShouldClose(window, GLFW_TRUE);
	} else  {
		switch(action){
		case GLFW_PRESS:
			switch(key) {
				// cases for each key in here
			}
			break;
		}
	}
}

void framebufferSizeCallBack(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
