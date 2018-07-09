#include "GameLoop.h"



#define MainMenuIndex 0
#define OptionsMenuIndex 1


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
void GameLoop::StartGame(SDLCore *SDLC)
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
			MM->MMLoop(SDLC);
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
		SDL_Delay(20);
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


