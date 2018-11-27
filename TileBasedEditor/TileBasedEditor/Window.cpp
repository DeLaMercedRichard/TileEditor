#include "Window.h"
#include "SDL.h"
#include <iostream>

Window::Window(int width_, int height_) {
	screenSurface = nullptr;
	window = nullptr;
	renderer = nullptr;
	if (width_ % 2 == 0) width = width_ + 1;
	else width = width_;
	if (height_ % 2 == 0) height = height_ + 1;
	else height = height_;
}

bool Window::OnCreate() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Tile Based Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Window::OnDestroy() {
	if (renderer) SDL_DestroyRenderer(renderer);
	if (screenSurface) SDL_FreeSurface(screenSurface);
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();

}

Window::~Window() {}

SDL_Window* Window::GetSDL_Window() {
	return window;
}

SDL_Renderer * Window::GetRenderer()
{
	return renderer;
}

SDL_Surface * Window::GetScreenSurface()
{
	return screenSurface;
}

void Window::ClearWindow()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Window::EventHandler()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			this->OnDestroy();
			break;
		default:
			break;
		}
		switch (event.key.keysym.sym)
		{
		case SDLK_0:
			std::cout << "0 was pushed\n";
			break;
		default:
			break;
		}
	}
}