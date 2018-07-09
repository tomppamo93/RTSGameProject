#include "MainMenu.h"

MainMenu::MainMenu(SDLCore *SDLC)
{
	//Alustetaan mainmenu
	SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Mainmenu_bg.png", m_background);
	std::string BName[MMButtonCount] = { "Start Game", "Options", "Load Game", "Credits", "Quit Game" };
	
		for (int i = 0; i < MMButtonCount; i++)
		{
			int x = 50;
			int y = i * 150 + 50;
			MenuButton::SetButton(&m_button[i], BName[i], x, y, 50, 150, true, false);
			SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_down.png", MenuButton::GetTextureDown(&m_button[i]));
			SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_up.png", MenuButton::GetTextureUp(&m_button[i]));
			SDLC->LoadTextureFromFile(SDLC->GetRenderer(), SDLC->GetResPath("") + "Button_mouseover.png", MenuButton::GetTextureMouseover(&m_button[i]));
		}
}
	

MainMenu::~MainMenu()
{
}

int MainMenu::MMLoop(GameLoop *game, SDLCore *SDLC)
{
		while (SDL_PollEvent(SDLC->GetEvent()))
		{
			if (SDLC->GetEvent()->type == SDL_KEYUP)
			{
				//Kun käyttäjä painaa pakene nappia niin ikkuna menee kiinni
				if (SDLC->GetEvent()->key.keysym.sym == SDLK_ESCAPE)
				{
					QuitGame(SDLC);
				}

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

			//If user closes the window
			if (SDLC->GetEvent()->type == SDL_QUIT)
			{
				game->SetQuit(true);
			}
			SDL_Delay(20);
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