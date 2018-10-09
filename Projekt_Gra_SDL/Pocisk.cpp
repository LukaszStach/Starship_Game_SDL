#include "Pocisk.h"

Pocisk::~Pocisk()
{
	SDL_DestroyTexture(pociskTextura);
}

void Pocisk::wczytanie(const char* sciezka)
{
	tmpSurface = IMG_Load(sciezka);
	pociskTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Pocisk::pozycja()
{
		przesowaniePocisku = przesowaniePocisku + 9 - przyspSamolotu;
		pociskTexturaR.h = 13;
		pociskTexturaR.w = 6;
		pociskTexturaR.x = pozycjaStartowaX + 18;
		pociskTexturaR.y = pozycjaStartowaY - 10 - przesowaniePocisku;

		if (pociskTexturaR.y < 0)
		{
			czyPociskAktywny = false;
			czyPociskAktywny2 = false;
			pociskTexturaR.x = pozycjaStartowaX + 18;
			pociskTexturaR.y = pozycjaStartowaY - 10;
			przesowaniePocisku = 0;
		}

		pozycjaPociskuX = pociskTexturaR.x;
		pozycjaPociskuY = pociskTexturaR.y;
}

void Pocisk::wyswietlanie()
{

	SDL_RenderCopy(Gra::renderer, pociskTextura, nullptr, &pociskTexturaR);
}

void Pocisk::pozycjaSamolotu(int x, int y, int gora, int dol)
{
	pozycjaStartowaX = x; 
	pozycjaStartowaY = y;
	if ((gora == 1 && dol == 1 )||( gora == 0 && dol == 0)) przyspSamolotu = 0;
	else if (gora == 1 && dol == 0) przyspSamolotu = -4;
	else przyspSamolotu = 4;
}

