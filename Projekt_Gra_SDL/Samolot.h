#pragma once
#include "Gra.h"

class Samolot
{
private:
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* samolotTexturaProsto = nullptr;
	SDL_Texture* samolotTexturaLewo = nullptr;
	SDL_Texture* samolotTexturaPrawo = nullptr;
	SDL_Texture* samolotTexturaPozycja = nullptr;

	int xpos = 0;
	int ypos = 0;
public:
	Samolot() {};
	~Samolot();

	SDL_Rect samolotTexturaR;

	void wczytanie(const char* sciezkaProsto, const char* sciezkaLewo, const char* sciezkaPrawo);
	void przemieszczanie(bool pozycjaSamolot[4]);
	void wyswietlanie();

	int pozycjaSamolotuX;
	int pozycjaSamolotuY;
};

