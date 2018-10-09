#include "Samolot.h"

Samolot::~Samolot()
{
	SDL_DestroyTexture(samolotTexturaLewo);
	SDL_DestroyTexture(samolotTexturaPrawo);
	SDL_DestroyTexture(samolotTexturaProsto);
	SDL_DestroyTexture(samolotTexturaPozycja);
}

void Samolot::wczytanie(const char* sciezkaProsto, const char* sciezkaLewo, const char* sciezkaPrawo)
{
	tmpSurface = IMG_Load(sciezkaProsto);
		samolotTexturaProsto = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	tmpSurface = IMG_Load(sciezkaLewo);
		samolotTexturaLewo= SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	tmpSurface = IMG_Load(sciezkaPrawo);
		samolotTexturaPrawo = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);

	samolotTexturaPozycja = samolotTexturaProsto;
	SDL_FreeSurface(tmpSurface);
}

void Samolot::przemieszczanie(bool pozycjaSamolot[4])
{
	if (pozycjaSamolot[0] || pozycjaSamolot[1] || pozycjaSamolot[2] || pozycjaSamolot[3]) 
	{
		
		if (pozycjaSamolot[0] && samolotTexturaR.y >= 5) { ypos -= 5; samolotTexturaPozycja = samolotTexturaProsto; }
		else ypos -= 0;
		if (pozycjaSamolot[1] && samolotTexturaR.y <= 738) { ypos += 5; samolotTexturaPozycja = samolotTexturaProsto; }
		else ypos += 0;
		if (pozycjaSamolot[2] && samolotTexturaR.x >= 2 && pozycjaSamolot[3] == false) { xpos -= 4; samolotTexturaPozycja = samolotTexturaLewo; }
		else xpos -= 0;
		if (pozycjaSamolot[3] && samolotTexturaR.x <= 600 - 45 && pozycjaSamolot[2] == false) { xpos += 4; samolotTexturaPozycja = samolotTexturaPrawo; }
		else xpos += 0;
		if (pozycjaSamolot[3] && pozycjaSamolot[2]) samolotTexturaPozycja = samolotTexturaProsto;
	}
	else samolotTexturaPozycja = samolotTexturaProsto;
	/////////////////////////////
	samolotTexturaR.h = 56;
	samolotTexturaR.w = 44;
	samolotTexturaR.x = 300 -16 + xpos;
	samolotTexturaR.y = 700 + ypos;

	pozycjaSamolotuX = samolotTexturaR.x;
	pozycjaSamolotuY = samolotTexturaR.y;
}

void Samolot::wyswietlanie()
{
	SDL_RenderCopy(Gra::renderer, samolotTexturaPozycja, nullptr, &samolotTexturaR);
}
