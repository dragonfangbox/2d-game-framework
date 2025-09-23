#ifndef RENDERER_H
#define RENDERER_H

int renderer_glInit();
int renderer_glfwInit();
int renderer_init();
int renderer_glfwInit(int GL_majorVersion, int GL_minorVersion);

void renderer_drawTest();

#endif
