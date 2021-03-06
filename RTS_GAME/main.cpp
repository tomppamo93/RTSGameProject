#include "GameLoop.h"
#include "SDLCore.h"
#include <iostream>

SDLCore *SDLC;
GameLoop *Game;

int wmain(int argc,char **argv)
{
	//SDL alustus
	SDLCore *SDLC = new SDLCore();
	if (SDLC->SDLCoreInit() != 0)
	{
		delete SDLC;
		return 0;
	}

	//Käynnistetään peli
	GameLoop *Game = new GameLoop();
	Game->StartGame(SDLC, Game);

	//Sammutetaan peli
	delete Game;
	SDL_DestroyRenderer(SDLC->GetRenderer());
	SDL_DestroyWindow(SDLC->GetWindow());
	IMG_Quit();
	SDL_Quit();
	delete SDLC;

	return 0;
}