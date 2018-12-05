#ifndef  CAMERA_H
#define CAMERA_H
#include <SDL.h>


class Camera 
{
private:
	/*
	Camera Parameters
	*/
	int xposition, yposition;
	bool hasBounds, hasReticle;
	int default_x_position, default_y_position;
	int cameraSpeed;
	/*Reference Misc*/
	int reticle_xposition, reticle_yposition;
	int reticle_width, reticle_height;
	int screenWidth, screenHeight;
	int xboundary_max, yboundary_max, xboundary_min, yboundary_min;
	/*
	Camera Functions
	*/
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void resetCamera();
	/*
	Update Functions
	*/
	void setCameraBoundary();
	//void renderReticle();
	SDL_Surface *reticle;
	SDL_Texture *reticle_texture;

	

public:
	/*
	Camera Objects
	*/
	bool setCameraBounds(int xboundarymax_, int yboundarymax_, int xboundarymin_, int yboundarymin_);
	bool setCameraBounds(int xboundarymax_, int yboundarymax_);
	bool setCameraBounds();
	SDL_Rect camera;

	/*
	Camera Methods
	*/
	void displayReticle(SDL_Renderer *renderer);
	Camera(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	
	void HandleEvents(SDL_Event &event);
	~Camera();
};
#endif // ! CAMERA_H


