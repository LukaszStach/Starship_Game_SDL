#pragma once
#include "Gra.h"

class Dzwiek
{
private:
	Mix_Chunk * dzwiek = nullptr;
public:
	Dzwiek() {};
	~Dzwiek();

	void wczytanie(const char* sciezka);
	void odtwarzanie();
};

