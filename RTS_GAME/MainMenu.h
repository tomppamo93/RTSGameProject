#pragma once

#include "SDL.h"
#include "MenuButton.h"
#include "SDLCore.h"

#define MMButtonCount 5

class MainMenu
{
public:
	MainMenu(SDLCore *SDLC);
	~MainMenu();

	void QuitGame(SDLCore *SDLC);
	int MMLoop(SDLCore *SDLC);

	bool GetQuit() { return m_quit; };

private:
	int index;
	bool m_quit;
	SDL_Texture *m_background;
	MenuButton m_button[MMButtonCount];
};