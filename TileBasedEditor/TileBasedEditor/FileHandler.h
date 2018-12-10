#pragma once
#include <memory>
#include <vector>
#include <string>



class GameObject;
struct FileHandler {

public:
	//method that takes in a string name corresponding to the filename that the user wishes to load, and will populate
	//a vector of gameobjects to populate the editor
	static std::vector<std::shared_ptr<GameObject>> ReadFile(std::string fileName_);

	//method that takes in a vector of object pointers from the editor scene, in order to be written to a file for later
	//use
	static void WriteFile(std::vector<std::shared_ptr<GameObject>> objectVec_, std::string saveName_);

	//method that takes in a filepath and returns a string vector of all the files that have the specified file extension
	static std::vector<std::string> GetFilesInDirectory(std::string filePath_, std::string fileExt_);

};