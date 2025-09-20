#include <stdlib.h>
#include <stdio.h>
#include "glad.h"

char* ReadShader(char fileName[]) {
	FILE *file = fopen(fileName, "r");
	if(!file) {
		printf("Failed to open file");
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* shaderSource = malloc(fileSize + 1);
	if(!shaderSource) {
		printf("memory alloc failure\n");
		fclose(file);
		return NULL;
	}

	fread(shaderSource, 1, fileSize, file);
	shaderSource[fileSize] = '\0';

	fclose(file);
	return shaderSource;
}

void CreateShader(unsigned int *shader, const char* shaderSource, GLenum shaderType) {
	GLint success;
	GLint logLen;

	*shader = glCreateShader(shaderType);
	glShaderSource(*shader, 1, &shaderSource, NULL);
	glCompileShader(*shader);
	
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		char* log = malloc(logLen); 
		if(!log) {
			printf("malloc failed\n");
		}
		glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLen);
		glGetShaderInfoLog(*shader, logLen, NULL, log);
		printf("SHADER COMPILATION FAILED: %s\n", log);
	}
	
}

