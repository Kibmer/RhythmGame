#pragma once

#include "Scene.h"

class Sprite;

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();


private:
	Sprite* _backgroundSprite;

public:
	void KeyUp(int keyCode);
};