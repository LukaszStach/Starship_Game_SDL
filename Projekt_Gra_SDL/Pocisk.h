#pragma once
#include "Gra.h"

class Pocisk
{
private:
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* pociskTextura = nullptr;

	int przesowaniePocisku = 0;
	int pozycjaStartowaX = 0;
	int pozycjaStartowaY = 0;
	int przyspSamolotu = 0;

public:
	Pocisk() {};
	~Pocisk();
	SDL_Rect pociskTexturaR;

	void wczytanie(const char* sciezka);
	void pozycja();
	void wyswietlanie();
	void pozycjaSamolotu(int x, int y, int gora, int dol);

	bool czyPociskAktywny = false;
	bool czyPociskAktywny2 = false;

	int pozycjaPociskuX;
	int pozycjaPociskuY;
};

