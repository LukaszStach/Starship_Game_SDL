#include "Gra.h"
/////////////////////////////////////////////////////////////////////////////////////

Samolot *samolot = new Samolot;
Tlo *tlo = new Tlo;
Instrukcja *instrukcja = new Instrukcja;
Pocisk *pocisk = new Pocisk[32];
Tekst *tekst = new Tekst[6];
Wrog *wrog = new Wrog[20];
Dzwiek *dzwiek = new Dzwiek[2];
Tekst *pauza = new Tekst[4];

SDL_Renderer* Gra::renderer = nullptr;
int numerPocisku = 0;
fstream plik;
int rekord;
int wrogPosX, wrogPosY, wrogAccX, wrogAccY;
int koniecGry = 0;

//////////////////////////////////////////////////////////////////////////////////////
bool kolizja(SDL_Rect PociskR, SDL_Rect WrogR, bool czySamolot)
{
	int lewoPocisk, lewoWrog;
	int prawoPocisk, prawoWrog;
	int goraPocisk, goraWrog;
	int dolPocisk, dolWrog;

	lewoPocisk = PociskR.x;
	prawoPocisk = PociskR.x + PociskR.w;
	goraPocisk = PociskR.y;
	dolPocisk = PociskR.y + PociskR.h;
	if (czySamolot) 
	{
		lewoWrog = WrogR.x + 20;
		prawoWrog = WrogR.x + WrogR.w - 20;
		goraWrog = WrogR.y + 20;
		dolWrog = WrogR.y + WrogR.h - 20;
	}
	else
	{
		lewoWrog = WrogR.x + 5;
		prawoWrog = WrogR.x + WrogR.w - 5;
		goraWrog = WrogR.y + 10;
		dolWrog = WrogR.y + WrogR.h - 10;
	}

	if ((goraPocisk < dolWrog && lewoPocisk < prawoWrog) && (dolPocisk > goraWrog && prawoPocisk > lewoWrog)) return true;
	else return false;
}
/////////////////////////////////////////////////////////////////////

void Gra::pauzaGry()
{
	pauza[0].wyswietlanie();
	SDL_RenderPresent(renderer);

	while (true) {
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			{
				CzyProgramDziala = false;
				break;
			}
		else if (event.type == SDL_KEYDOWN)
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				CzyProgramDziala = false;
				break;
			}
			else if (event.key.keysym.sym == SDLK_RETURN)
			{
				for (int i = 1; i < 4; i++)
				{
					renderowanie();
					pauza[i].wyswietlanie();
					SDL_RenderPresent(renderer);
					SDL_Delay(1000);
				}
				break;
			}
	}
	SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Gra::init(const char * naglowek, int xpos, int ypos, int szerokosc, int wysokosc, bool pelnyEkran)
{
	int pelny_ekran = 0;
	SzerokoscEkranu = szerokosc;
	WysokoscEkranu = wysokosc;

	if (pelnyEkran) pelny_ekran = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		TTF_Init();

		okno = SDL_CreateWindow(naglowek, xpos, ypos, szerokosc+250, wysokosc, pelny_ekran);
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

		renderer = SDL_CreateRenderer(okno, -1, 0);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		CzyProgramDziala = true;
	}
	///////////

	tlo->wczytanie("Zasoby/tloFinal.png");
	samolot->wczytanie("Zasoby/SamolotProsto.png", "Zasoby/SamolotLewo.png", "Zasoby/SamolotPrawo.png");
	instrukcja->wczytanie("Zasoby/instrukcja.png", 600, 320, 250, 415);
	dzwiek[0].wczytanie("Zasoby/laser.wav");
	dzwiek[1].wczytanie("Zasoby/koniecgry.wav");

	for (int i = 0; i < 32; i++) pocisk[i].wczytanie("Zasoby/Pocisk.png");

	for (int i = 0; i < 20; i++) 
	{
		wrogPosX = rand() % 600;
		wrogPosY = ((rand() % 600)+100)*-1;
		wrogAccX = (rand() % 7) + 1;
		wrogAccY = (rand() % 3) + 1;
		wrog[i].wczytanie("Zasoby/wrog2.png", wrogPosX, wrogPosY, wrogAccX, wrogAccY);
		wrog[i].czyWrogAktywny = true;
	}

	pauza[0].wczytanie("Zasoby/Sans.ttf", "PAUZA", 100, 130, 300);
	pauza[1].wczytanie("Zasoby/Sans.ttf", "3", 100, 275, 300);
	pauza[2].wczytanie("Zasoby/Sans.ttf", "2", 100, 275, 300);
	pauza[3].wczytanie("Zasoby/Sans.ttf", "1", 100, 275, 300);

	plik.open("Zasoby/Rekord.txt");
	plik >> rekord;
	tekst[0].wczytanie("Zasoby/Sans.ttf", "Wynik:", 25, 625, 100);
	tekst[1].wczytanie("Zasoby/Sans.ttf", "", 25, 750, 100);
	tekst[2].wczytanie("Zasoby/Sans.ttf", "Rekord:", 25, 625, 200);
	tekst[3].wczytanie("Zasoby/Sans.ttf", "", 25, 750, 200);
	tekst[3].aktualizacjaPunktow(rekord, 750, 200);
	tekst[4].wczytanie("Zasoby/Sans.ttf", "Lukasz Stachowiak 132181", 18, 610, 770);
	tekst[5].wczytanie("Zasoby/Sans.ttf", "GAME OVER", 100, 10, 350);
	plik.close();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Gra::ObslugaEvent()
{
	SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				CzyProgramDziala = false;
				break;
			case SDLK_UP:
				pozycjaSamolot[0] = true;
				break;
			case SDLK_DOWN:
				pozycjaSamolot[1] = true;
				break;
			case SDLK_LEFT:
				pozycjaSamolot[2] = true;
				break;
			case SDLK_RIGHT:
				pozycjaSamolot[3] = true;
				break;
			case SDLK_SPACE:
				if (!wycisz) dzwiek[0].odtwarzanie();
				pocisk[numerPocisku].czyPociskAktywny = true;
				pocisk[numerPocisku].czyPociskAktywny2 = true;
				pocisk[numerPocisku].pozycjaSamolotu(samolot->pozycjaSamolotuX, samolot->pozycjaSamolotuY, pozycjaSamolot[0], pozycjaSamolot[1]);
				numerPocisku++;
				wynikGry -= 100;
				break;
			case SDLK_m:
				wycisz ^= true;
				break;
			case SDLK_RETURN:
				pauzaGry();
				break;
			}
		}
		else if(event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				pozycjaSamolot[0] = false;
				break;
			case SDLK_DOWN:
				pozycjaSamolot[1] = false;
				break;
			case SDLK_LEFT:
				pozycjaSamolot[2] = false;
				break;
			case SDLK_RIGHT:
				pozycjaSamolot[3] = false;
				break;
			}
		}
		switch (event.type)
		{
		case SDL_QUIT: CzyProgramDziala = false;
			break;
		};
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Gra::aktualizacja()
{
		tlo->przewijanie(WysokoscEkranu, SzerokoscEkranu);
		samolot->przemieszczanie(pozycjaSamolot);

		for (int i = 0; i < 32; i++)
			if (pocisk[i].czyPociskAktywny)
				pocisk[i].pozycja();

		for (int i = 0; i < 20; i++)
			wrog[i].przesuwanie();

		/// KOLIZJA

		for (int i = 0; i < 20; i++)
			if (wrog[i].czyWrogAktywny)
			{
				if (kolizja(samolot->samolotTexturaR, wrog[i].wrogTexturaR, 1))
				{
					if (!wycisz) dzwiek[1].odtwarzanie();
					CzyProgramDziala = false;
					koniecGry = 1;
				}
				else
					for (int j = 0; j < 32; j++)
						if (pocisk[j].czyPociskAktywny && pocisk[j].czyPociskAktywny2)
						{
							if (kolizja(pocisk[j].pociskTexturaR, wrog[i].wrogTexturaR, 0))
							{
								pocisk[j].czyPociskAktywny2 = false;
								wrog[i].czyWrogAktywny = false;
								wynikGry += 100;
							}
						}
			}

		wynikGry++;
		tekst[1].aktualizacjaPunktow(wynikGry, 750, 100);

		if (numerPocisku > 31) numerPocisku = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Gra::renderowanie()
 {
	SDL_RenderClear(renderer);

	tlo->wyswietlanie();
	samolot->wyswietlanie();
	instrukcja->wyswietlanie();

	for (int i = 0; i < 32; i++)
		if (pocisk[i].czyPociskAktywny2 && pocisk[i].czyPociskAktywny)
			pocisk[i].wyswietlanie();

	for (int i = 0; i < 20; i++)
		if (wrog[i].czyWrogAktywny)
			wrog[i].wyswietlenie();

	for (int i = 0; i < 5 + koniecGry; i++) tekst[i].wyswietlanie();

	SDL_RenderPresent(renderer);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Gra::czyszczenie()
{
	if (koniecGry) SDL_Delay(3300);
	if (wynikGry > rekord)
	{
		plik.open("Zasoby/Rekord.txt", ios::out | ios::trunc);
		ostringstream ss;
		ss << wynikGry;
		string wynikGryString = ss.str();
		plik << wynikGryString;
		plik.close();
	}

	delete[] tekst;
	delete[] pocisk;
	delete[] wrog;
	delete[] dzwiek;
	delete[] pauza;
	delete samolot;
	delete tlo;
	delete instrukcja;
	SDL_DestroyWindow(okno);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Gra::czyChodzi()
{
	if (CzyProgramDziala == false) return false;
	return true;
}
