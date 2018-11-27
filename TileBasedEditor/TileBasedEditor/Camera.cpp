#include "Camera.h"





void Camera::moveRight()
{
	xposition += cameraSpeed;
}

void Camera::moveLeft()
{
	xposition -= cameraSpeed;
}

void Camera::moveUp()
{
	yposition += cameraSpeed;
}

void Camera::moveDown()
{
	yposition -= cameraSpeed;
}

void Camera::resetCamera()
{
	xposition = default_x_position;
	yposition = default_y_position;
}

bool Camera::setCameraBounds(int xboundary_, int yboundary_)
{
	hasBounds = true;
	xboundary = xboundary_;
	yboundary = yboundary_;
	return hasBounds;
}

bool Camera::setCameraBounds()
{
	hasBounds = false;
	
	return hasBounds;
}

Camera::Camera(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{

	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;
	//SDL_RECT camera(0,0,SCREENWIDTH,SCREENHEIGHT)
	camera = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	xposition = 0;
	yposition = 0;
	default_x_position = xposition;
	default_y_position = yposition;

}
void Camera::Update(float time)
{
	camera.x = xposition;
	camera.y = yposition;
}
void Camera::HandleEvents(SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN)
	{
		//Adjust the velocity
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: moveUp(); break;
		case SDLK_DOWN: moveDown(); break;
		case SDLK_LEFT: moveLeft(); break;
		case SDLK_RIGHT: moveRight(); break;
		case SDLK_KP_ENTER: resetCamera(); break;
		}
	}
	
}

Camera::~Camera()
{
}
