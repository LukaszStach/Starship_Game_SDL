#include "Tekst.h"

Tekst::~Tekst()
{
	SDL_DestroyTexture(tekstTextura);
	TTF_CloseFont(Sans);
}

void Tekst::wczytanie(const char* sciezkaCzcionki, const char* Tekst, int RozmiarCzcionki,  int x, int y)
{
	Sans = TTF_OpenFont(sciezkaCzcionki , RozmiarCzcionki);
	tmpSurface = TTF_RenderText_Solid(Sans, Tekst, bialy);
	tekstTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	SDL_QueryTexture(tekstTextura, nullptr, nullptr, &texW, &texH);
	tekstTexturaR = { x, y, texW, texH };
}

void Tekst::aktualizacjaPunktow(int punkty, int x, int y)
{
		stringstream strs;
		strs << punkty;
		string temp_str = strs.str();
		const char* punktyChar = (const char*)temp_str.c_str();

		tmpSurface = TTF_RenderText_Solid(Sans, punktyChar, bialy);
		tekstTextura = SDL_CreateTextureFromSurface(Gra::renderer, tmpSurface);
		SDL_QueryTexture(tekstTextura, nullptr, nullptr, &texW, &texH);
		tekstTexturaR = { x, y, texW, texH };
		SDL_FreeSurface(tmpSurface);
}

void Tekst::wyswietlanie()
{
	SDL_RenderCopy(Gra::renderer, tekstTextura, nullptr, &tekstTexturaR);
}

