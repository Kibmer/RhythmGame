#pragma once
#include "sdl_ttf.h"
#include "Texture.h"

class Font : public Texture
{
public:
	Font(const char *fileName, int fontSize);
	~Font();

public:
	void SetText(const char* text);
private:
	TTF_Font* _sansFont;
};