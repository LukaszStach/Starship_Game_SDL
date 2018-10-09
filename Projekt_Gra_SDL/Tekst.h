#pragma once
#include "Gra.h"
#include <sstream>

class Tekst
{
private:
	TTF_Font * Sans = nullptr;
	SDL_Color bialy = { 255, 255, 255};
	SDL_Surface* tmpSurface;

	SDL_Texture* tekstTextura = nullptr;
	SDL_Rect tekstTexturaR;

	int texW = 0;
	int texH = 0;

public:
	Tekst() {};
	~Tekst();

	void wczytanie(const char* sciezkaCzcionki, const char* Tekst, int RozmiarCzcionki, int x, int y);
	void aktualizacjaPunktow(int punkty, int x, int y);
	void wyswietlanie();
};
