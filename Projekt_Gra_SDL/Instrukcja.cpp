#include "Instrukcja.h"


Instrukcja::~Instrukcja()
{
	SDL_DestroyTexture(instrukcjaTextura);
}

void Instrukcja::wczytanie(const char * sciezka, int xpos, int ypos, int wysokosc, int szerokosc)
{
	tmpSurface = IMG_Load(sciezka);
	instrukcjaTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	instrukcjaTexturaR = { xpos,ypos,wysokosc,szerokosc };
}

void Instrukcja::wyswietlanie()
{
	SDL_RenderCopy(Gra::renderer, instrukcjaTextura, nullptr, &instrukcjaTexturaR);
}
