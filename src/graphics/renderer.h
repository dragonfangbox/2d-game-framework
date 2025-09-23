#ifndef RENDERER_H
#define RENDERER_H

#include <GLFW/glfw3.h>

int renderer_init();
int renderer_glInit();
int renderer_glfwInit(int GL_majorVersion, int GL_minorVersion);

GLFWwindow* renderer_newWindow(int width, int height, char* name);

void renderer_drawTest();

#endif
