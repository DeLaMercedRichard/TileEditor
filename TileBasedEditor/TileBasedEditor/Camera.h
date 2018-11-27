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
	bool hasBounds;
	int default_x_position, default_y_position;
	int cameraSpeed;
	/*Reference Misc*/
	int reticle_xposition, reticle_yposition;
	int screenWidth, screenHeight;
	int xboundary, yboundary;
	/*
	Camera Functions
	*/
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void resetCamera();
	

	

public:
	/*
	Camera Objects
	*/
	bool setCameraBounds(int xboundary_, int yboundary_);
	bool setCameraBounds();
	SDL_Rect camera;
	/*
	Camera Methods
	*/
	Camera(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	void Update(float time);
	void HandleEvents(SDL_Event &event);
	~Camera();
};
#endif // ! CAMERA_H


