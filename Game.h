#pragma once
#include"SDLCore.h"


class Game
{
public:
	Game();
	~Game();

private:
	SDL_Texture *m_Game_UI;
	SDL_Texture *m_GameTextures[];
};

Game::Game()
{
}

Game::~Game()
{
}