#pragma once
#include "Gra.h"

class Wrog
{
private:
	SDL_Surface * tmpSurface = nullptr;
	SDL_Texture* wrogTextura = nullptr;

	int przemieszczenieX=0;
	int przemieszczenieY=0;
	bool lewo = false;

	int wrogPosX;
	int wrogPosY;
	int wrogAccX;
	int wrogAccY;

public:
	bool czyWrogAktywny = false;

	Wrog() {};
	~Wrog();
	SDL_Rect wrogTexturaR;

	void wczytanie(const char* sciezka, int xpos, int ypos, int xacc, int yacc);
	void przesuwanie();
	void wyswietlenie();

	//int pozycjaWrogaX;
	//int pozycjaWrogaY;
};

