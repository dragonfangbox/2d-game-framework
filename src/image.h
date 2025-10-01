#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
	unsigned char* data;
	int width;
	int height;
	int channels;
} Image;

int image_loadImage(Image* i, const char* fileName);
void image_freeImage(Image* i);

#endif
