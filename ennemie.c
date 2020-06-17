#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "coll.h"
#include "d.h"
#include <time.h>

void initialiser_enemy(enemy E)
{
E.image_enemy=NULL;
E.position_enemy.x=0;
E.position_enemy.y=0;

}

int afficher_enemy(enemy E,SDL_Surface*screen)
{
SDL_Event event;

    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;

char temps[20];

    //SDL_Init(SDL_INIT_VIDEO);


    //screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   // SDL_WM_SetCaption("Afficher Ennemie", NULL);

    E.image_enemy = SDL_LoadBMP("fish.bmp");
    //SDL_SetColorKey(E.image_enemy, SDL_SRCCOLORKEY, SDL_MapRGB(E.image_enemy->format, 0, 0, 255));



    E.position_enemy.x = screen->w / 2 - E.image_enemy->w / 2;
    E.position_enemy.y = screen->h / 2 - E.image_enemy->h / 2;

    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
            E.position_enemy.x++;
            E.position_enemy.y++;

                                    /* On bouge l'ennemi */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }




        SDL_Flip(screen);
    }

    SDL_FreeSurface(E.image_enemy);
    SDL_Quit();

   return EXIT_SUCCESS;

}
