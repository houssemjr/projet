#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quiz.h"

const char* getQuestion(Question *t,int q){
	if(q==0)
		return t->reponse1;
	if(q==1)
		return t->reponse2;
	if (q==2)
		return t->reponse3;
}//	

int main() {

	int running = 1;
	int currentChoice = 0;
	srand(time(NULL));
	int qid = random()%5;
	int choices[3] = {0,1,2};
//Generation alea 
	for(int i = 0; i<5; i++)
        {
		int t = random()%3;
		int t2 = random()%3;
		int t3 = choices[t];
		choices[t] = choices[t2];
		choices[t2] = t3;
	}

	printf("%d %d %d\n",choices[0],choices[1],choices[2]);
	Quiz q;
	QUIZ_Init(&q,"./questions1.txt");
        SDL_Rect rect1,rect2,rect3 ,rect, positionFond,choice,t;
	SDL_Surface *screen ,*msg,*imageDeFond, *arrow,*failed ,*good;
	TTF_Font *font = NULL,*font2 = NULL,*font3 = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	screen = SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE);

	SDL_Event event;

	font = TTF_OpenFont("font.ttf",50);
	SDL_Color color = {0,0,0};
	font2= TTF_OpenFont("font2.ttf",25);
	SDL_Color color2= {0,0,255};
	font3= TTF_OpenFont("font3.ttf",40);
	SDL_Color color3= {0,255,0};
	SDL_Color color4 = {255,0,0};

	


	choice.x = 80;
	choice.y = 532.8;
	positionFond.x=positionFond.y=0;

	arrow = SDL_CreateRGBSurface(0,16,16,32,0,0,0,0);
	SDL_FillRect(arrow,NULL,SDL_MapRGB(arrow->format,255,0,0));

	SDL_EnableKeyRepeat(0,0);
	
	while(running) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
					running = 0;
			}
			if(event.type == SDL_KEYDOWN) 
			{
				if(event.key.keysym.sym == SDLK_ESCAPE){
					running = 0;
				}
				if(event.key.keysym.sym == SDLK_RIGHT){
					if(currentChoice != 2)
						currentChoice++;
					else 
						currentChoice = 0;	
				}
				if(event.key.keysym.sym == SDLK_LEFT){
					if(currentChoice != 0)
						currentChoice--;
					else 
						currentChoice = 2;	
				}
				if(event.key.keysym.sym == SDLK_RETURN){
					if(choices[currentChoice] == 0){
						running = 0;
						
						t.x = 0;
						t.y = 0;
                                                good=IMG_Load("10.png");
						SDL_BlitSurface(good,NULL,screen,&t);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					else {
						running = 0;
						
						t.x = 0;
						t.y = 0;
                                                failed=IMG_Load("01.png");
						SDL_BlitSurface(failed,NULL,screen,&t);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
				}
			}
		}
	imageDeFond = IMG_Load("fond.jpg");
	SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
	SDL_Flip(screen);
			
	rect.x = 180;
	rect.y = 180;

	msg = TTF_RenderText_Solid(font, q.questions[qid].question , color);
	SDL_BlitSurface(msg,NULL,screen,&rect);
	rect1.x=93.6;
	rect1.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[0]) , color);
	SDL_BlitSurface(msg,NULL,screen,&rect1);
	rect2.x=453.6;
	rect2.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[1]) , color);
	SDL_BlitSurface(msg,NULL,screen,&rect2);
        rect3.x=770.4;
	rect3.y = 532.8;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[2]), color);
	SDL_BlitSurface(msg,NULL,screen,&rect3);
	choice.x = 80+currentChoice*338.5;
	SDL_BlitSurface(arrow,NULL,screen,&choice);


	SDL_Flip(screen);
		SDL_Delay(16);
	}


	SDL_FreeSurface(screen);
	SDL_FreeSurface(msg);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

}
