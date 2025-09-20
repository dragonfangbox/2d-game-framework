#ifndef SPRITE_H
#define SPRITE_H

#include "types.h"
#include "linmath.h"

typedef struct {
	vec2 pos;
	mat4x4 model;
	Vertex* vertexData ;
} Sprite;

void initSprite(Sprite* s);

#endif
