#pragma once

#include "Scene.h"

class Sprite;
class Track;

class Font;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	// Input
public:
	void KeyDown(int keyCode);
	void KeyUp(int keyCode);
	
	// Game
private:
	Sprite* _backgroundSprite;
	Track* _track;
	int _gameDuration;

	//SDL_Texture* _textTexture;
	Font* _textFont;
};