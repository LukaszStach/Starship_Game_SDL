#include "Tlo.h"

Tlo::~Tlo()
{
	SDL_DestroyTexture(tloTextura);
}

void Tlo::wczytanie(const char* sciezka)
{
	tmpSurface = IMG_Load(sciezka);
	tloTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Tlo::przewijanie(int WysokoscEkranu, int SzerokoscEkranu)
{
	przesuwanie += 3;
	if (przesuwanie >= WysokoscEkranu) przesuwanie = 0;
	tloTexturaR.h = WysokoscEkranu * 2;
	tloTexturaR.w = SzerokoscEkranu;
	tloTexturaR.x = 0;
	tloTexturaR.y = -WysokoscEkranu + przesuwanie;
}

void Tlo::wyswietlanie()
{
	SDL_RenderCopy(Gra::renderer, tloTextura, nullptr, &tloTexturaR);
}
