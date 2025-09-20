#include <stdlib.h>
#include <stdio.h>

#include "sprite.h"
#include "linmath.h"
#include "types.h"

// finish writing this function, make it heap allocated 
// to avoid stack mem limits with many quads

void initSprite(Sprite* s) {
	s->vertexData = malloc(sizeof(Vertex) * 4);
	if(!s->vertexData) {
		printf("sprite failed to malloc\n");
		return;
	}

	s->vertexData[0] = (Vertex){{0.5, 0.5, 0}, {0, 0}, {1, 0, 0 ,1}}; // top right
	s->vertexData[1] = (Vertex){{0.5, -0.5, 0}, {0, 0}, {0, 1, 0 ,1}}; // bottom right
	s->vertexData[2] = (Vertex){{-0.5, 0.5, 0}, {0, 0}, {0, 0, 1 ,1}}; // top left
	s->vertexData[3] = (Vertex){{-0.5, -0.5, 0}, {0, 0}, {1, 0, 1 ,1}}; // bottom left
	
	mat4x4_identity(s->model);
	mat4x4_translate(s->model, 0.5, 0, 0);
}
