#include "Dzwiek.h"


Dzwiek::~Dzwiek()
{
	Mix_FreeChunk(dzwiek);
}

void Dzwiek::wczytanie(const char * sciezka)
{
	dzwiek = Mix_LoadWAV(sciezka);
}

void Dzwiek::odtwarzanie()
{
	Mix_PlayChannel(-1, dzwiek, 0);
}
