#include "MenuButton.h"



MenuButton::MenuButton()
{
	
}


MenuButton::~MenuButton()
{
}




void MenuButton::SetButton(MenuButton *button, std::string name, int xpos, int ypos, int xsize, int ysize, bool active, bool pressed, SDL_Texture *textureup, SDL_Texture *texturedown)
{
	button->m_name = name;

	button->m_xPos = xpos;
	button->m_yPos = ypos;
	button->m_xSize = xsize;
	button->m_ySize = ysize;

	button->m_active = active;
	button->m_buttonpressed = pressed;

	button->m_buttontextureup = textureup;
	button->m_buttontexturedown = texturedown;
}