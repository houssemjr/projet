#ifndef COLL_H_INCLUDED
#define COLL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>




int collisionright (SDL_Rect positionperso,SDL_Rect posbarriere1);
int collisionleft(SDL_Rect positionperso,SDL_Rect posbarriere1,SDL_Rect posbarriere2);





#endif // COLL_H_INCLUDED
