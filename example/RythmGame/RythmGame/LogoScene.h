#pragma once

#include "Scene.h"

class Sprite;

class LogoScene : public Scene
{
public:
	LogoScene();
	~LogoScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

private:
	Sprite* _backgroundSprite;

public:
	void KeyUp(int keyCode);
};