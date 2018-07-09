#pragma once

#include "MainMenu.h"
#include "OptionsMenu.h"
#include "SDL.h"
#include "SDLCore.h"
#include "SDL_ttf.h"
#include <iostream>

class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	bool GetQuit() { return m_quit; };
	void SetQuit(bool quit) { m_quit = quit; };

	int GetMenuIndex() { return m_MenuIndex; };
	void SetMenuIndex(bool mi) { m_MenuIndex = mi; };

	void StartGame(SDLCore *SDLC);

private:
	bool m_quit;
	int m_MenuIndex;
};