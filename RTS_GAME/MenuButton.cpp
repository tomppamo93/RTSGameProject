#include "MenuButton.h"



MenuButton::MenuButton()
{
	
}


MenuButton::~MenuButton()
{
}




void MenuButton::SetButton(MenuButton *button, std::string name, int xpos, int ypos, int xsize, int ysize, bool active, bool pressed)
{
	button->m_name = name;

	button->m_xPos = xpos;
	button->m_yPos = ypos;
	button->m_xSize = xsize;
	button->m_ySize = ysize;

	button->m_active = active;
	button->m_buttonpressed = pressed;
}