#pragma once

#include "SDL.h"
#include <iostream>

class MenuButton
{
public:
	MenuButton();
	~MenuButton();

	static bool IsButtonPressed(MenuButton *button)	{ return button->m_buttonpressed; }
	static bool IsButtonActive(MenuButton *button)	{ return button->m_active; }

	static void ButtonPressed(MenuButton *button, bool bp)	{ button->ButtonPressed = bp; }
	static void ButtonActive(MenuButton *button, bool bp)	{ button->ButtonActive = bp; }

	static void SetButton(MenuButton *button, std::string name, int xpos, int ypos, int xsize, int ysize, bool active, bool pressed, SDL_Texture *textureup, SDL_Texture *texturedown);

	static int GetPosX(MenuButton *button) { return button->m_xPos; };
	static int GetPosY(MenuButton *button) { return button->m_yPos; };

	static int GetSizeX(MenuButton *button) { return button->m_xSize; };
	static int GetSizeY(MenuButton *button) { return button->m_ySize; };

	static SDL_Texture *GetTextureUp(MenuButton *button) { return button->m_buttontextureup; };
	static SDL_Texture *GetTextureDown(MenuButton *button) { return button->m_buttontexturedown; };

private:
	std::string m_name;
	int m_xPos, m_yPos;
	int m_xSize, m_ySize;
	bool m_active, m_buttonpressed;
	SDL_Texture *m_buttontextureup, *m_buttontexturedown;
};

