#pragma once

#include "SDL.h"
#include "SDLCore.h"
#include <iostream>
#include "GameLoop.h"

#define StartGameButton 0
#define OptionsButton 1
#define LoadGameButton 2
#define CreditsButton 3
#define QuitGameButton 4

class MenuButton
{
public:
	MenuButton();
	~MenuButton();
	static bool CheckMousePosition(SDLCore *SDLC, MenuButton *button);

	static bool IsButtonPressed(MenuButton *button)	{ return button->m_buttonpressed; }
	static bool IsButtonActive(MenuButton *button)	{ return button->m_active; }

	static void ButtonPressed(MenuButton *button, bool bp)	{ button->m_buttonpressed = bp; }
	static void ButtonActive(MenuButton *button, bool bp)	{ button->m_active = bp; }

	static void SetButton(MenuButton *button, std::string name, int xpos, int ypos, int xsize, int ysize, bool active, bool pressed, SDL_Texture *texup, SDL_Texture *texdown, SDL_Texture *texhover, int index);

	static int GetPosX(MenuButton *button) { return button->m_xPos; };
	static int GetPosY(MenuButton *button) { return button->m_yPos; };

	static int GetSizeX(MenuButton *button) { return button->m_xSize; };
	static int GetSizeY(MenuButton *button) { return button->m_ySize; };

	static int ButtonPressedDown(SDLCore *SDLC, MenuButton *button, int Bcount);
	static int ButtonPressedUp(SDLCore *SDLC, MenuButton *button, int Bcount, GameLoop *Game);

	static std::string GetName(MenuButton *button) { return button->m_name; };

	static SDL_Texture *GetTextureUp(MenuButton *button) { return button->m_buttontextureup; };
	static SDL_Texture *GetTextureDown(MenuButton *button) { return button->m_buttontexturedown; };
	static SDL_Texture *GetTextureMouseover(MenuButton *button) { return button->m_buttontexturedown; };

	int GetIndex() { return m_index; };
	void SetIndex(int index) { m_index = index; };

private:
	int m_index;
	std::string m_name;
	int m_xPos, m_yPos;
	int m_xSize, m_ySize;
	bool m_active, m_buttonpressed;
	SDL_Texture *m_buttontextureup, *m_buttontexturedown, *m_buttontexturemouseover;
};

