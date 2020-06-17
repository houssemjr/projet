houssem: main.o ennemie.o collision.o deuxieme.o update.o
	gcc main.c ennemie.c  deuxieme.c collision.c update.c  -o houssem -lSDL_mixer  -lSDL -lSDL_image -lSDL_ttf  -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image
ennemie.o:ennemie.c
	gcc -c ennemie.c -lSDL -lSDL_image -lSDL_ttf

deuxieme.o:deuxieme.c
	gcc -c deuxieme.c -lSDL -lSDL_image
update.o:update.c
	gcc -c update.c -lSDL -lSDL_image
execute:
	./houssem
