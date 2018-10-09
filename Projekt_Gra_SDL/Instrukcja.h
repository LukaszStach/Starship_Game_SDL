#pragma once
#include "Gra.h"

class Instrukcja
{
private:
	SDL_Surface * tmpSurface = nullptr;
	SDL_Texture* instrukcjaTextura = nullptr;

public:
	Instrukcja() {};
	~Instrukcja();

	SDL_Rect instrukcjaTexturaR;

	void wczytanie(const char* sciezka, int xpos, int ypos, int szerokosc, int wysokosc);
	void wyswietlanie();
};

