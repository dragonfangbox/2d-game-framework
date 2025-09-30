#ifndef TYPES_H
#define TYPES_H

#include "linmath.h"
#include <stdbool.h>

typedef unsigned int uint;

typedef struct {
	vec3 pos;
	vec2 texCoord;
	vec4 color;
} Vertex;

#endif
