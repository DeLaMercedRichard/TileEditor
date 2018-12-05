#pragma once
#include <iostream>

class GameObject {
	std::string imageName, type;
	float x, y;

public:
	GameObject(std::string imageN_, std::string type_, float x_, float y_);
};