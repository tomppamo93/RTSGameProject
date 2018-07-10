#include "Game.h"


Game::Game(SDL_Texture *Textures[],int TextureCount, SDLCore SDLC, std::string FileName[])
{

	for (int i = 0; i < TextureCount; i++)
	{

		SDLC.LoadTextureFromFile(SDLC.GetRenderer(), SDLC.GetResPath("") + FileName[i], Textures[i]);


	}


}

Game::~Game()
{

}

int Game::GraphicLoop(SDL_Texture *Textures[] ,SDLCore SDLC)
{




	return 0;
}

