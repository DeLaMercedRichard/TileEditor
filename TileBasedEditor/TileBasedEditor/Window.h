#pragma once
#include <SDL.h>

class Window {
private:
	struct SDL_Window* window;
	struct SDL_Renderer* renderer;
	struct SDL_Surface* screenSurface;
	int width, height;

public:
	Window(int width_, int height_);
	~Window();
	bool OnCreate();
	void OnDestroy();
	SDL_Window* GetSDL_Window();
	SDL_Renderer* GetRenderer();
	SDL_Surface* GetScreenSurface();
	inline int GetW() { return width; }
	inline int GetH() { return height; }

	void ClearWindow();
	void EventHandler();
};
