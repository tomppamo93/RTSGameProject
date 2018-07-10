#include "MenuButton.h"
#include "MainMenu.h"
#include "GameLoop.h"

MenuButton::MenuButton()
{
	
}


MenuButton::~MenuButton()
{
}

void MenuButton::SetButton(MenuButton *button, std::string name, int xpos, int ypos, int xsize, int ysize, bool active, bool pressed, SDL_Texture *texup, SDL_Texture *texdown, SDL_Texture *texhover, int index)
{
	button->m_name = name;

	button->m_xPos = xpos;
	button->m_yPos = ypos;
	button->m_xSize = xpos + xsize;
	button->m_ySize = ypos + ysize;
	button->m_index = index;

	button->m_active = active;
	button->m_buttonpressed = pressed;
	button->m_buttontextureup = texup;
	button->m_buttontexturedown = texdown;
	button->m_buttontexturemouseover = texhover;
}

//Funktio palauttaa truen jos hiiri on napin p‰‰ll‰
bool MenuButton::CheckMousePosition(SDLCore *SDLC, MenuButton *button)
{
	if (MenuButton::GetPosX(button) <= SDLC->GetEvent()->button.x && MenuButton::GetSizeX(button) >= SDLC->GetEvent()->button.x && MenuButton::GetPosY(button) <= SDLC->GetEvent()->button.y && MenuButton::GetSizeY(button) >= SDLC->GetEvent()->button.y)
	{
		return true;
	}
	return false;
}


//Kun nappia painetaan alas mit‰ tapahtuu?
int MenuButton::ButtonPressedDown(SDLCore *SDLC, MenuButton *button, int Bcount)
{
	for (int i = 0; i < Bcount; i++)
	{
		if (MenuButton::CheckMousePosition(SDLC, &button[i]))
		{
			SDLC->RenderTexture(MenuButton::GetTextureDown(&button[i]), SDLC->GetRenderer(), MenuButton::GetPosX(&button[i]), MenuButton::GetPosY(&button[i]));
			break;
		}
	}
	SDL_RenderPresent(SDLC->GetRenderer());
	return 0;
}


int MenuButton::ButtonPressedUp(SDLCore *SDLC, MenuButton *button, int Bcount, GameLoop *Game)
{
	for (int i = 0; i < Bcount; i++)
	{
		if (!MenuButton::CheckMousePosition(SDLC, &button[i]))
		{
			SDLC->RenderTexture(MenuButton::GetTextureUp(&button[i]), SDLC->GetRenderer(), MenuButton::GetPosX(&button[i]), MenuButton::GetPosY(&button[i]));
		}

		if (MenuButton::CheckMousePosition(SDLC, &button[i]))
		{
			switch (Game->GetMenuIndex())
			{
			case MainMenuIndex:
				
				switch (i)
				{
				case StartGameButton:

					break;
				case OptionsButton:
					Game->SetMenuIndex(OptionsMenuIndex);
					break;
				case LoadGameButton:
					break;
				case CreditsButton:
					break;
				case QuitGameButton:
					MainMenu::QuitGame(SDLC);
					break;
				default:
					break;
				}
				break;
			case OptionsMenuIndex:

				break;
			default:
				break;
			}
		}

	}
	SDL_RenderPresent(SDLC->GetRenderer());
	return 0;
}