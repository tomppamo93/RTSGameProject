#pragma once

#include "SDL.h"
#include "MenuButton.h"
#include "SDLCore.h"
#include "GameLoop.h"

#define MMButtonCount 5

class MenuButton;

class MainMenu
{
public:
	MainMenu(SDLCore *SDLC);
	~MainMenu();

	static void QuitGame(SDLCore *SDLC);
	int MMLoop(SDLCore *SDLC, GameLoop *Game);

	bool GetQuit() { return m_quit; }

private:
	bool m_quit;
	SDL_Texture *m_background, *m_quitmenu;
	MenuButton m_button[MMButtonCount];
};