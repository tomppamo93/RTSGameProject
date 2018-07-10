#pragma once
#include"SDLCore.h"


class Game
{
public:
	Game(SDL_Texture *Textures[] , int TextureCount, SDLCore SDLC, std::string FileName[]);
	~Game();
	int GraphicLoop(SDL_Texture *Textures[],SDLCore SDLC);
	
	SDL_Texture *GetTexture(int index) { return m_GameTextures[index]; };
	void SetTexture(SDL_Texture *tex, int index) { m_GameTextures[index] = tex; };

	SDLCore SDLC;
private:
	
	SDL_Texture *m_GameTextures[];
};


