#pragma once

#include "MenuButton.h"
#include "SDLCore.h"

#define OPButtonCount 4

class OptionsMenu
{
public:
	OptionsMenu(SDLCore *SDLC);
	~OptionsMenu();
	int OPLoop(SDLCore *SDLC);

	bool GetBack() { return m_back; };

private:
	bool m_back;
	int index;
	
	SDL_Texture *m_background;
	MenuButton m_button[OPButtonCount];
};

