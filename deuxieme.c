#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "coll.h"




void deuxieme (SDL_Event event,SDL_Rect positionfond, SDL_Rect positionperso2)

{




                if (event.key.keysym.sym == SDLK_s)
                positionperso2.y+=3;

                if (event.key.keysym.sym == SDLK_z)
                positionperso2.y-=3;

                if (event.key.keysym.sym == SDLK_d)
                {positionperso2.x+=3;
                positionfond.x   +=1;}

               if (event.key.keysym.sym == SDLK_q)
                  {positionperso2.x-=3;
                  positionfond.x   -=1;}







}
