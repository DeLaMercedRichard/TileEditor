#include "FileHandler.h"
#include "GameObject.h"
#include <filesystem>
#include <fstream>
#include <iostream>




std::vector<std::shared_ptr<GameObject>> FileHandler::ReadFile(std::string fileName_) {
	
	//the vector that will be returned through the read file method
	std::vector<std::shared_ptr<GameObject>> objects;

	std::ifstream objectFile(fileName_);
	//temp variables that will be used to read in from the file and populate the vector
	std::string imgName;
	int type;
	float x, y;
	//a loop that will loop over each line of the given file, and will construct new gameObjects based on the given parameters
	//in the file
	while (objectFile >> imgName >> type >> x >> y) {
		//add the reference to the object created by the factory with the specified parameters to the vector of objects
		objects.emplace_back(std::make_shared<GameObject>(imgName, type, x, y));
	}

	objectFile.close();

	return objects;
}

void FileHandler::WriteFile(std::vector<std::shared_ptr<GameObject>> objectVec_, std::string saveName_) {

	//open the file stream to write to with the given name in the method call
	std::ofstream saveFile(saveName_);

	//iterate over the vector of gameobjects and write its parameters to the file
	for (auto &i : objectVec_) {
		
		saveFile << i->GetParams() << std::endl;
	}

	//close the file
	saveFile.close();
	
}

std::vector<std::string> FileHandler::GetFilesInDirectory(std::string filePath_, std::string fileExt_) {
	//vector of file string names
	std::vector<std::string> files;

	//iterate recursively over the filepath and check for the specified extension, then add the string name of the file
	//that has the corresponding extension to the vector of strings
	for (auto& directory : std::filesystem::recursive_directory_iterator(filePath_)) {
		if (directory.path().extension() == fileExt_) {
			files.emplace_back(directory.path().filename().string());
		}
	}

	return files;
}