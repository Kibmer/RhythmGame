#pragma once

#include "Scene.h"

class Sprite;

class ResultScene : public Scene
{
public:
	ResultScene();
	~ResultScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();


private:
	Sprite* _backgroundSprite;

public:
	void KeyUp(int keyCode);
};