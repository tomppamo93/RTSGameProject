#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <string>

class SDLCore
{
public:
	SDLCore();
	~SDLCore();

	SDL_Event *GetEvent() { return m_event; };
	SDL_Renderer *GetRenderer() { return m_ren; };
	SDL_Window *GetWindow() { return m_win; };
	SDL_Color GetColor() { return m_color; };

	SDL_Color SetColor(SDL_Color color) { m_color = color; };

	int SDLCoreInit();
	int RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
	int RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	int RenderText(std::string text, std::string fontfile, SDL_Color color, int fontsize, SDL_Renderer *ren, int x, int y);
	int LoadTextureFromFile(SDL_Renderer *ren, std::string file, SDL_Texture *texture);

	void logSDLError(std::ostream &os, const std::string &msg);

	std::string GetResPath(const std::string &subDir);

private:
	SDL_Event *m_event;
	SDL_Renderer *m_ren;
	SDL_Window *m_win;
	SDL_Color m_color;
};

