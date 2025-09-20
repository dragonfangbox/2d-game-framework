#ifndef SHADER_H 
#define SHADER_H

#include "glad.h"

char* ReadShader(char fileName[]);
void CreateShader(unsigned int *shader, const char* shaderSource, GLenum shaderType);

#endif
