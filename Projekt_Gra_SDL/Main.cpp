#include "Gra.h"

const int SzerokoscEkranu = 600;
const int WysokoscEkranu = 800;

int main(int argc, char* args[])
{
	Gra *gra = new Gra();

	srand(time(nullptr));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	gra->init("Spaceship", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SzerokoscEkranu, WysokoscEkranu, false);
	SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);

	while (gra->czyChodzi())
	{
		frameStart = SDL_GetTicks();

		gra->ObslugaEvent();
		gra->aktualizacja();
		gra->renderowanie();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)  SDL_Delay(frameDelay - frameTime);
	}
	gra->czyszczenie();

	return 0;
}