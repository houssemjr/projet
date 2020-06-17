void  af_mm (mm * m, hero h, écran SDL_Surface *, int mini)
{
	si (mini == 1 )
	{
		m-> pos_hero . x = (SCREEN_WIDTH_GAME / 2 ) - (m-> image -> w / 2 ) + h. position . x / 52 ;
		m-> pos_hero . y = (. h poste . y / 52 ) - 2 ;
	}
	sinon  si (mini == - 1 )
	{
		m-> pos_hero . x = (SCREEN_WIDTH_GAME / 2 ) - (m-> image -> w / 2 ) + h. position . x / 13,5 ;
		m-> pos_hero . y = ( position h . y / 13,5 );
	}
	SDL_BlitSurface (m-> image , NULL , écran, & m-> pos_image );
	SDL_BlitSurface (m-> hero , NULL , screen, & m-> pos_hero );
}
