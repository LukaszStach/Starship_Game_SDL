#pragma once
#include "Gra.h"

class Tlo
{
private:
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* tloTextura = nullptr;
	SDL_Rect tloTexturaR;
	int przesuwanie = 0;

public:
	Tlo() {};
	~Tlo();

	void wczytanie(const char* sciezka);
	void przewijanie(int WysokoscEkranu, int SzerokoscEkranu);
	void wyswietlanie();
};