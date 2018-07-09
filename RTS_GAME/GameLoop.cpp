#include "GameLoop.h"
#include "SDL.h"
#include "SDLCore.h"
#include <iostream>

#define MainMenuIndex 0
#define OptionsMenuIndex 1


GameLoop::GameLoop()
{
	m_quit = false;
	m_MenuIndex = MainMenuIndex;

	std::cout << "GameLoop alustettu." << std::endl;
}

GameLoop::~GameLoop()
{
}

//Tässä funktiossa ajetaan pelin päärutiinia
void GameLoop::StartGame(SDLCore *SDLC)
{
	MainMenu *MM = new MainMenu(SDLC);
	OptionsMenu *OM = new OptionsMenu(SDLC);

	while (!m_quit)
	{
		switch (m_MenuIndex)
		{
		case MainMenuIndex:
			MM->MMLoop(this, SDLC);
			break;
		case OptionsMenuIndex:

			break;
		default:
			break;
		}
		SDL_Delay(20);
	}
	
	delete OM;
	delete MM;
}


