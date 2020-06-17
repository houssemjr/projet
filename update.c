#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "coll.h"
#include "d.h"


void updateclavier (touches * etatclavier)
{
SDL_Event event;
while (SDL_PollEvent(&event)){


switch (event.type){
case SDL_KEYDOWN:
etatclavier->key[event.key.keysym.sym]=1;
break;

case SDL_KEYUP:
etatclavier->key[event.key.keysym.sym]=0;
break;
default :
break;



}

}

}





