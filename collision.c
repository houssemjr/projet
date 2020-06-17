#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "coll.h"


int collisionright (SDL_Rect positionperso,SDL_Rect posbarriere1)

{
int s;
if(positionperso.x+positionperso.w<posbarriere1.x)
                s=0;
            else
                s=1;

return s;
}
int collisionleft(SDL_Rect positionperso,SDL_Rect posbarriere1,SDL_Rect posbarriere2)
{  int s;
            if(positionperso.x > posbarriere2.x + posbarriere2.w)
                s=0;
            else
                s=1;
return s;
}



