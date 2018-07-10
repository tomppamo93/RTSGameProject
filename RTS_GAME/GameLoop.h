#pragma once

#include "OptionsMenu.h"
#include "SDL.h"
#include "SDLCore.h"
#include "SDL_ttf.h"
#include <iostream>

#define MainMenuIndex 0
#define OptionsMenuIndex 1
#define CreditsMenuIndex 2
#define LoadGameMenuIndex 3
#define QuitMenuIndex 4

class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	bool GetQuit() { return m_quit; };
	void SetQuit(bool quit) { m_quit = quit; };

	int GetMenuIndex() { return m_MenuIndex; };
	void SetMenuIndex(int mi) { m_MenuIndex = mi; };

	void StartGame(SDLCore *SDLC, GameLoop *Game);

private:
	bool m_quit;
	int m_MenuIndex;
};