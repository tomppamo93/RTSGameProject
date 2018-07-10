#include "MainMenu.h"



MainMenu::MainMenu(SDLCore *SDLC)
{
	m_quit = false;
	//Alustetaan mainmenu
	m_background = SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Mainmenu_bg.png");
	m_quitmenu = SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Quitmenu_bg.png");
	std::string BName[MMButtonCount] = { "Start Game", "Options", "Load Game", "Credits", "Quit Game" };

	SDLC->RenderTexture(m_background, SDLC->GetRenderer(), 0, 0);
	
		for (int i = 0; i < MMButtonCount; i++)
		{
			int x = 50;
			int y = i * 150 + 50;
			MenuButton::SetButton(&m_button[i], BName[i], x, y, 150, 50, true, false
				, SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_up.png")
				, SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_down.png")
				, SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_mouseover.png"), 0);

			SDLC->RenderTexture(MenuButton::GetTextureUp(&m_button[i]), SDLC->GetRenderer(), MenuButton::GetPosX(&m_button[i]), MenuButton::GetPosY(&m_button[i]));
		}
	
		SDL_RenderPresent(SDLC->GetRenderer());
}
	

MainMenu::~MainMenu()
{
}

int MainMenu::MMLoop(SDLCore *SDLC, GameLoop *Game)
{
	while (!m_quit)
	{
		
		while (SDL_PollEvent(SDLC->GetEvent()))
		{
			SDL_Delay(20);
			if (SDLC->GetEvent()->button.button == SDL_BUTTON_LEFT)
			{
				switch (SDLC->GetEvent()->button.type)
				{
				case SDL_MOUSEBUTTONDOWN:

					MenuButton::ButtonPressedDown(SDLC, m_button, MMButtonCount);

					break;

				case SDL_MOUSEBUTTONUP:

					MenuButton::ButtonPressedUp(SDLC, m_button, MMButtonCount, Game);

					break;
				default:
					break;
				}
			}

			if (SDLC->GetEvent()->type == SDL_KEYUP)
			{
				//Kun käyttäjä painaa pakene nappia niin ikkuna menee kiinni
				if (SDLC->GetEvent()->key.keysym.sym == SDLK_ESCAPE)
				{
					QuitGame(SDLC);
				}


			}

			//If user closes the window
			if (SDLC->GetEvent()->type == SDL_QUIT)
			{
				m_quit = true;
			}
		}
	}
	return 0;
}






//Funktio joka aktivoidaan kun käyttäjä haluaa poistua
void MainMenu::QuitGame(SDLCore *SDLC)
{
	SDL_SetRenderDrawColor(SDLC->GetRenderer(), 255, 0, 0, 255);
	SDL_Rect QuitBox;
	SDL_Surface *Text1 = NULL;
	SDL_Texture *Texture = NULL;
	SDL_Color textcolor = { 255, 255, 255, 255 };

	int wi, hi;
	SDL_GetWindowSize(SDLC->GetWindow(), &wi, &hi);

	QuitBox.h = 200;
	QuitBox.w = 400;
	QuitBox.x = wi / 2 - (QuitBox.w / 2);
	QuitBox.y = hi / 2 - (QuitBox.h / 2);

	//Piirretään neliöitä
	SDL_RenderDrawRect(SDLC->GetRenderer(), &QuitBox);

	SDL_SetRenderDrawColor(SDLC->GetRenderer(), 0, 0, 255, 255);

	QuitBox.h = 50;
	QuitBox.w = 100;
	QuitBox.x = wi / 2 + 50;
	QuitBox.y = hi / 2;

	SDL_RenderDrawRect(SDLC->GetRenderer(), &QuitBox);

	QuitBox.h = 50;
	QuitBox.w = 100;
	QuitBox.x = wi / 2 - 150;
	QuitBox.y = hi / 2;

	SDL_RenderDrawRect(SDLC->GetRenderer(), &QuitBox);


	SDLC->RenderText("YES", "Arial.ttf", textcolor, 24, SDLC->GetRenderer(), (wi / 2 - 125), (hi / 2 + 12));
	SDLC->RenderText("NO", "Arial.ttf", textcolor, 24, SDLC->GetRenderer(), (wi / 2 + 85), (hi / 2 + 12));

	SDL_RenderPresent(SDLC->GetRenderer());
}
