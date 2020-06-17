#ifndef D_H_INCLUDED
#define D_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "coll.h"


typedef struct{

int key[SDLK_LAST];
}
touches;

typedef struct
{

SDL_Rect  position_enemy;
SDL_Surface * image_enemy;


} enemy;

typedef struct
{
        SDL_Surface * temps;
	SDL_Rect position_temps;

	int heure;

	int minute;

	int seconde;


	TTF_Font *police;

	int tempsactuel;
	int tempsprecedent;



}temps;



void updateclavier (touches * etatclavier);
void ennemi (SDL_Rect posennemi);


void initialiser_enemy(enemy E);
int afficher_enemy(enemy E,SDL_Surface*screen);






#endif // D_H_INCLUDED
