#pragma once
#include <iostream>
//enum to be used with gameobject factory in order to better handle the creation of a gameobject should a need arise
enum TypeEnum {

	IMPASSABLE =0, PASSABLE, PLAYER, ENEMY

};
//basic representation of our gameobject class for the editor and for consistency in writing and reading format between
//editor and actual game
class GameObject {
	std::string imageName;
	int type;
	float x, y;

public:
	//basic constructor that will instantiate all variables by the given parameters
	GameObject(std::string imageN_, int type_, float x_, float y_);
	//string representation of the parameters formated for the chosen fileformat in order to simplify legibility of 
	//any writing code
	std::string GetParams();
};