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

	Image test;
	if(!image_loadImage(&test, "/home/josiah/programming/c/openglstuff/2d-game-framework/assets/scribble1.png")) {
		debug_printf("image load failed");
	}

	uint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, test.width, test.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, test.data);

	glUseProgram(program);
	glUniform1i(glGetUniformLocation(program, "tex0"), 0);

	Sprite x;
	setSpriteImage(&x, &test);
	initSprite(&x);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), x.vertexData, GL_STATIC_DRAW);

	while(!glfwWindowShouldClose(win)) {
		glfwPollEvents();

		glClearColor(0.2, 0.4, 0.7, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glUseProgram(program);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//	renderer_drawSprite(&x);

		glfwSwapBuffers(win);
	}

	free(vertshadersrc);
	free(fragshadersrc);
	image_freeImage(&test);

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
