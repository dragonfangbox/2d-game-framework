#include <stdio.h>
#include <stdlib.h>

#include "src/debug.h"
#include "src/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "src/shader.h"
#include "src/graphics/renderer.h"

void keyPressedCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebufferSizeCallBack(GLFWwindow* window, int width, int height);

int main() {
	if(!renderer_glfwInit(3, 3)) {
		return 1;
	}

	//TODO put all this glfw stuff into the renderer
	// update the projection matrix inside the framebufferSizeCallBack func( make sure the resend the new matrix to the shader)
	// yuh

	GLFWwindow* win = glfwCreateWindow(920, 780, "AHDAHJGDH", NULL, NULL);
	glfwMakeContextCurrent(win);

	glfwSetKeyCallback(win, keyPressedCallback);
	glfwSetFramebufferSizeCallback(win, framebufferSizeCallBack);

	int res = renderer_glInit();
	if(res == 0) {
		printf("GLAD FAILED to LOAD\n");
		return 1;
	} 

	glViewport(0, 0, 920, 780);
	glEnable(GL_DEPTH_TEST);

	char* vertshadersrc = ReadShader("./src/shaders/vertshader.vert");
	char* fragshadersrc = ReadShader("./src/shaders/fragshader.frag");

	GLuint vertShader;
	CreateShader(&vertShader, vertshadersrc, GL_VERTEX_SHADER);

	GLuint fragShader;
	CreateShader(&fragShader, fragshadersrc, GL_FRAGMENT_SHADER);

	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	renderer_init();


	while(!glfwWindowShouldClose(win)) {
		glfwPollEvents();

		glClearColor(0.2, 0.4, 0.7, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program);
		


		glfwSwapBuffers(win);
	}

	free(vertshadersrc);
	free(fragshadersrc);

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
