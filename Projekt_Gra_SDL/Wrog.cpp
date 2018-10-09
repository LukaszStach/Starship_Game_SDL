#include "Wrog.h"

Wrog::~Wrog()
{
	SDL_DestroyTexture(wrogTextura);
}

void Wrog::wczytanie(const char* sciezka, int xpos, int ypos, int xacc, int yacc)
{
	tmpSurface = IMG_Load(sciezka);
	wrogTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	wrogPosX = xpos;
	wrogPosY = ypos;
	wrogAccX = xacc;
	wrogAccY = yacc;
}


void Wrog::przesuwanie()
{
	przemieszczenieY += wrogAccY;

	if (przemieszczenieX + wrogPosX > 600 - 65) lewo = true;
	else if (przemieszczenieX + wrogPosX < 0) lewo = false;

	switch(lewo)
	{
	case false:
		przemieszczenieX += wrogAccX;
		break;
	case true:
		przemieszczenieX -= wrogAccX;
		break;
	}
	wrogTexturaR.w = 64;
	wrogTexturaR.h = 64;
	wrogTexturaR.x = wrogPosX + przemieszczenieX;
	wrogTexturaR.y = wrogPosY + przemieszczenieY;

	if (wrogTexturaR.y > 800)
	{
		wrogPosX = rand() % 600; 
		wrogPosY = ((rand() % 600)+100)*-1;
		wrogAccX = (rand() % 7) + 1;
		wrogAccY = (rand() % 3) + 1;
		przemieszczenieX = 0;
		przemieszczenieY = 0;
		czyWrogAktywny = true;
	}

	//pozycjaWrogaX = wrogTexturaR.x;
	//pozycjaWrogaY = wrogTexturaR.y;
}

void Wrog::wyswietlenie()
{
	SDL_RenderCopy(Gra::renderer, wrogTextura, nullptr, &wrogTexturaR);
}
