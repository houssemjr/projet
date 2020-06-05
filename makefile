prog: quiz.o main.o
	gcc quiz.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image
main.o: main.c
	gcc -c main.c -lSDL -lSDL_ttf -lSDL_image
quiz.o: quiz.c
	gcc -c quiz.c -lSDL -lSDL_ttf -lSDL_image
