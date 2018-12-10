#include <iostream>
#include <SDL.h>
#include "FileHandler.h"


int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	std::vector<std::shared_ptr<GameObject>> objects;

	objects = FileHandler::ReadFile("test.txt");

	FileHandler::WriteFile(objects, "writeTest.txt");

	std::vector<std::string> files = FileHandler::GetFilesInDirectory("C:/Users/JF/Downloads/" , ".bmp");

	return 0;
}