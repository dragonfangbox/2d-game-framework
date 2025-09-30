#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
	unsigned char* data;
	int width;
	int height;
} Image;

void image_loadImage(Image* i, const char* fileName);
void image_freeImage(Image* i);

#endif
