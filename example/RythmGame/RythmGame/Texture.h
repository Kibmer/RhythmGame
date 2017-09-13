#pragma once

#include "SDL_image.h"

class Texture
{
public:
	Texture(const char* fileName);
	Texture();
	~Texture();

protected:
	SDL_Texture* _texture;
	
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	int animationTime;

public:
	void SetScale(float wScale, float hScale);
	void SetPosition(int x, int y);
	void SetAnimationTime(int time);

	int GetRenderWidth();
	int GetRenderHeight();

	void Render();

};
