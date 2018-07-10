#include "GameLoop.h"
#include "MainMenu.h"

GameLoop::GameLoop()
{
	m_quit = false;
	m_MenuIndex = MainMenuIndex;

	std::cout << "GameLoop alustettu." << std::endl;
}

GameLoop::~GameLoop()
{
}

//Tässä funktiossa ajetaan pelin päärutiinia
void GameLoop::StartGame(SDLCore *SDLC, GameLoop *Game)
{
	MainMenu *MM = nullptr;
	OptionsMenu *OM = nullptr;

	while (!m_quit)
	{
		switch (m_MenuIndex)
		{
		case MainMenuIndex:
			//Jos Mainmenua ei ole niin se luodaan
			if (MM == nullptr)
			{
				MM = new MainMenu(SDLC);
			}

			//Jos optionsmenu on vielä olemassa se poistetaan
			if (OM != nullptr)
			{
				delete OM;
			}
			//Käynnistetään MainMenu luuppi
			MM->MMLoop(SDLC, Game);
			m_quit = MM->GetQuit();

			break;
		case OptionsMenuIndex:
			//Jos Optionsmenua ei ole niin se luodaan
			if (OM == nullptr)
			{
				OM = new OptionsMenu(SDLC);
			}

			//Jos Mainmenu on vielä olemassa se poistetaan
			if (MM != nullptr)
			{
				delete MM;
			}
				
			break;
		default:
			break;
		}
	}


	if (OM != nullptr)
	{
		delete OM;
	}

	if (MM != nullptr)
	{
		delete MM;
	}
}


