#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void image_loadImage(Image* i, const char* fileName) {
	int width, height, n;
	unsigned char* image = stbi_load(fileName, &width, &height, &n, 0);

	i->data = image;
	i->width = width;
	i->height = height;
}

void image_freeImage(Image* i) {
	stbi_image_free(i->data);
}
