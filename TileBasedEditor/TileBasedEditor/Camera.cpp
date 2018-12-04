#include "Camera.h"
/*
Navigation Tips:
Movement 
Limits
Constructor
ReticleDisplay
Update
HandleEvents
*/
/*
Movement
*/
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
/*Setting Limits*/
/*
Xboundary and Yboundary minmal value set to 0 by default
*/
bool Camera::setCameraBounds(int xboundarymax_, int yboundarymax_)
{
	hasBounds = true;
	xboundary_max = xboundarymax_;
	yboundary_max = yboundarymax_;
	xboundary_min = 0;
	yboundary_min = 0;
	return hasBounds;
}
bool Camera::setCameraBounds(int xboundarymax_, int yboundarymax_, int xboundarymin_, int yboundarymin_)
{
	hasBounds = true;
	xboundary_max = xboundarymax_;
	yboundary_max = yboundarymax_;
	xboundary_min = xboundarymin_;
	yboundary_min = yboundarymin_;
	return hasBounds;
}

bool Camera::setCameraBounds()
{
	hasBounds = false;
	
	return hasBounds;
}
/*Toggles Reticle*/
void Camera::displayReticle(SDL_Renderer *renderer)
{
	reticle = IMG_Load("Crosshair.png");
	/**Sets Transparency of Image*/
	SDL_SetColorKey(reticle, SDL_TRUE, SDL_MapRGB(reticle->format, 0, 0xFF, 0xFF));
	reticle_texture = SDL_CreateTextureFromSurface(renderer, reticle);
	reticle_width = reticle->w;
	reticle_height = reticle->h;
	SDL_FreeSurface(reticle);
	hasReticle = true;
}
/*Constructor*/
Camera::Camera(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{

	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;
	//SDL_RECT camera(0,0,SCREENWIDTH,SCREENHEIGHT)
	camera = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	reticle = nullptr;
	reticle_texture = nullptr;
	xposition = 0;
	yposition = 0;
	default_x_position = xposition;
	default_y_position = yposition;

}
void Camera::Update(float time)
{
	setCameraBoundary();
	renderReticle();

}
void renderReticle()
{

}
void Camera::setCameraBoundary()
{
	if (!hasBounds)
	{
		camera.x = xposition;
		camera.y = yposition;
	}
	else
	{
		/*Setting Boundaries for Camera if There is a Boundary Set*/
		if (camera.x < xboundary_min)
		{
			camera.x = xboundary_min;
		}
		if (camera.x > xboundary_max)
		{
			camera.x = xboundary_max;
		}
		if (camera.y < yboundary_min)
		{
			camera.y = yboundary_min;
		}
		if (camera.y > yboundary_max)
		{
			camera.y = yboundary_max;
		}
	}
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
