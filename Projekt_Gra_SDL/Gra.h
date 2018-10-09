#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Samolot.h"
#include "Tlo.h"
#include "Pocisk.h"
#include "Tekst.h"
#include "Wrog.h"
#include "Instrukcja.h"
#include "Dzwiek.h"

using namespace std;

class Gra
{
private:
	SDL_Window * okno = nullptr;
	SDL_Event event;
	bool CzyProgramDziala = false;
	int SzerokoscEkranu;
	int WysokoscEkranu;
	bool wycisz = false;
	bool pozycjaSamolot[4];
	int wynikGry = 0;

public:
	Gra() {};
	~Gra() {};
	void pauzaGry();
	void init(const char* naglowek, int xpos, int ypos, int szerokosc, int wysokosc, bool pelnyEkran);
	void ObslugaEvent();
	void aktualizacja();
	void renderowanie();
	void czyszczenie();
	bool czyChodzi();

	static SDL_Renderer* renderer;
};