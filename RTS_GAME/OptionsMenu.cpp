#include "OptionsMenu.h"



OptionsMenu::OptionsMenu(SDLCore *SDLC)
{
	m_back = false;

	SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Mainmenu_bg.png", m_background);
	std::string BName[OPButtonCount] = { "Back", "Apply", "Resolution", "Keybindings"};

	for (int i = 0; i < OPButtonCount; i++)
	{
		int x = 50;
		int y = i * 150 + 50;
		MenuButton::SetButton(&m_button[i], BName[i], x, y, 150, 50, true, false);
		SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_down.png", MenuButton::GetTextureDown(&m_button[i]));
		SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_up.png", MenuButton::GetTextureUp(&m_button[i]));
		SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_mouseover.png", MenuButton::GetTextureMouseover(&m_button[i]));
	}

}


OptionsMenu::~OptionsMenu()
{
}

int OptionsMenu::OPLoop(SDLCore *SDLC)
{
	while (!m_back)
	{


		while (SDL_PollEvent(SDLC->GetEvent()))
		{
			if (SDLC->GetEvent()->button.button == SDL_BUTTON_LEFT)
			{
				switch (SDLC->GetEvent()->button.type)
				{
				case SDL_MOUSEBUTTONDOWN:

					
					break;

				case SDL_MOUSEBUTTONUP:

					break;
				default:
					break;
				}
			}


		}
	}


	return 0;
}