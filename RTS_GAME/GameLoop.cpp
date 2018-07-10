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

//T�ss� funktiossa ajetaan pelin p��rutiinia
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

			//Jos optionsmenu on viel� olemassa se poistetaan
			if (OM != nullptr)
			{
				delete OM;
			}
			//K�ynnistet��n MainMenu luuppi
			MM->MMLoop(SDLC, Game);
			m_quit = MM->GetQuit();

			break;
		case OptionsMenuIndex:
			//Jos Optionsmenua ei ole niin se luodaan
			if (OM == nullptr)
			{
				OM = new OptionsMenu(SDLC);
			}

			//Jos Mainmenu on viel� olemassa se poistetaan
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


