#ifndef RENDERER_H
#define RENDERER_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "../sprite.h"

int renderer_glInit();
int renderer_glfwInit(int GL_majorVersion, int GL_minorVersion);
int renderer_init();

GLFWwindow* renderer_newWindow(int width, int height, char* name);

void renderer_drawSprite(Sprite* s);
// void renderer_drawTest();

#endif
