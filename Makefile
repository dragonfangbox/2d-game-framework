CC=gcc
SRCFILES=src/shader.c src/graphics/renderer.c src/sprite.c src/debug.c src/image.c

compile:
	$(CC) -Wall -o main main.c$$(pkg-config --cflags glfw3) $(SRCFILES)  $$(pkg-config --libs glfw3) src/glad.c -Iinclude -lm 
run:
	./main
