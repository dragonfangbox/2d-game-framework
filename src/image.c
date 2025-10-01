#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int image_loadImage(Image* i, const char* fileName) {
	int width, height, n;

	stbi_set_flip_vertically_on_load(1);
	unsigned char* image = stbi_load(fileName, &width, &height, &n, STBI_rgb_alpha);
	if(image == NULL) {
		printf("Failed to load image\n");
		return 0;
	}

	i->data = image;
	i->width = width;
	i->height = height;
	i->channels = n;

	return 1;
}

void image_freeImage(Image* i) {
	stbi_image_free(i->data);
}
