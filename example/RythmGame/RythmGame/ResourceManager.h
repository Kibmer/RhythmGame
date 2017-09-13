#pragma once
#include <iostream>
#include <map>
#include <string>

#include "SDL_Image.h"

class ResourceManager
{
	// Singleton
private:
	ResourceManager();

public:
	~ResourceManager();

private:
	static ResourceManager * _instance;

private:
	std::map < std ::string, SDL_Texture* > _textureMap;

public:
	static ResourceManager* GetInstance();
	SDL_Texture* FindTexture(std::string filePath);

};