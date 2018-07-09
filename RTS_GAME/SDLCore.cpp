#include "SDLCore.h"
#include <iostream>

SDLCore::SDLCore()
{
	m_event = NULL;
	m_ren = NULL;
	m_win = NULL;
}

SDLCore::~SDLCore()
{
	TTF_Quit();
	delete m_event;
}

//SDL kirjaston alustus
int SDLCore::SDLCoreInit()
{
	//SDL alustus
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}

	//SDL ikkunan alustus
	m_win = SDL_CreateWindow("RTS Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 1024, SDL_WINDOW_OPENGL);
	if (m_win == nullptr)
	{
		logSDLError(std::cout, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}

	//SDL renderer alustus
	m_ren = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_ren == nullptr)
	{
		SDL_DestroyWindow(m_win);
		logSDLError(std::cout, "SDL_CreateRenderer");
		SDL_Quit();
		return 1;
	}

	//Luodaan SDL_event
	m_event = new SDL_Event;
	if (m_event == nullptr)
	{
		std::cout << "SDL_Event Error: " << std::endl;
		SDL_Quit();
		return 1;
	}

	//Alustetaan SDL_TTF
	if (TTF_Init() != 0)
	{
		logSDLError(std::cout, "TTF_Init");
		SDL_Quit();
		return 1;
	}

	//Alustetaan SDL_IMG
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		logSDLError(std::cout, "IMG_Init");
		SDL_Quit();
		return 1;
	}

	SDL_Color m_color = { 255, 255, 255, 255};

	std::cout << "SDL alustettu." << std::endl;

	return 0;
}

void SDLCore::logSDLError(std::ostream &os, const std::string &msg) 
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}

//Tekstuurien renderöinti funktiot
int SDLCore::RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	int w, h;

	if (SDL_QueryTexture(tex, NULL, NULL, &w, &h) != 0)
	{
		std::cout << "SDL_QueryTexture Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	RenderTexture(tex, ren, x, y, w, h);

	return 0;
}

int SDLCore::RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect TexBox;
	TexBox.h = h;
	TexBox.w = w;
	TexBox.y = y;
	TexBox.x = x;

	if (SDL_RenderCopy(ren, tex, NULL, &TexBox) != 0)
	{
		std::cout << "SDL_RenderCopy Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	return 0;
}

//Funktion avulla voidaan renderöidä tekstiä näytölle
int SDLCore::RenderText(std::string text, std::string fontfile, SDL_Color color, int fontsize, SDL_Renderer *ren, int x, int y)
{
	//Avataan fontti tiedosto
	std::string fonttifilu = "C:\\Windows\\Fonts\\" + fontfile;
	TTF_Font *font = TTF_OpenFont(fonttifilu.c_str(), fontsize);
	if (font == nullptr) 
	{
		return 1;
	}

	//Luodaan halutusta tekstistä surface
	SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surf == nullptr) 
	{
		TTF_CloseFont(font);
		return 1;
	}

	//Luodaan tekstuuri surfacesta
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surf);
	if (texture == nullptr) 
	{
		return 1;
	}

	//Renderöidään teksti
	RenderTexture(texture, ren, x, y);

	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	return 0;
}

//Funktion avulla voidaan ladata kuva tiedosto ja tallentaa se tekstuuriksi
int SDLCore::LoadTextureFromFile(SDL_Renderer *ren, std::string file, SDL_Texture *texture)
{
	texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr)
	{
		std::cout << "IMG_LoadTexture: Error" << std::endl;
		return 1;
	}
	return 0;
}

std::string SDLCore::GetResPath(const std::string &subDir) {
	//We need to choose the path separator properly based on which
	//platform we're running on, since Windows uses a different
	//separator than most systems
#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif
	//This will hold the base resource path: Lessons/res/
	//We give it static lifetime so that we'll only need to call
	//SDL_GetBasePath once to get the executable path
	static std::string baseRes;
	if (baseRes.empty()) {
		//SDL_GetBasePath will return NULL if something went wrong in retrieving the path
		char *basePath = SDL_GetBasePath();
		if (basePath) {
			baseRes = basePath;
			SDL_free(basePath);
		}
		else {
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
		//We replace the last bin/ with res/ to get the the resource path
		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
	}
	//If we want a specific subdirectory path in the resource directory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}