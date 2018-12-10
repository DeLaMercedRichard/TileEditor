#include "GameObject.h"
#include <string>

GameObject::GameObject(std::string imageN_, int type_, float x_, float y_) {
	imageName = imageN_;
	type = type_;
	x = x_;
	y = y_;
}

std::string GameObject::GetParams() {

	auto string = imageName + " " + std::to_string(type) + " " + std::to_string((int)x) + " " + std::to_string((int)y);

	return string;

}
