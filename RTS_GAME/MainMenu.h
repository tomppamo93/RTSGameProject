#pragma once

#include "SDL.h"
#include "MenuButton.h"
#include "SDLCore.h"
#include "GameLoop.h"

#define MMButtonCount 5

class MainMenu
{
public:
	MainMenu(SDLCore *SDLC);
	~MainMenu();

	void QuitGame(SDLCore *SDLC);
	int MMLoop(GameLoop *game, SDLCore *SDLC);



private:
	int index;
	SDL_Texture *m_background;
	MenuButton m_button[MMButtonCount];
};

