houssem: main.o collision.o
	gcc main.c collision.c -o houssem -lSDL_mixer  -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image

execute:
	./houssem
