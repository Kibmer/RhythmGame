#include <stdio.h>
#include <sdl.h>

#include "LogoScene.h"

#include "SceneManager.h"
#include "GameSystem.h"
#include "Sprite.h"

LogoScene::LogoScene()
{
	_backgroundSprite = NULL;
}

LogoScene::~LogoScene()
{
	Deinit();
}

void LogoScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr.csv", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance().GetWindowWidth() / 2, GameSystem::GetInstance().GetWindowHeight() / 2);
}

void LogoScene::Deinit()
{

}

void LogoScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}

void LogoScene::Render()
{
	_backgroundSprite->Render();
}

void LogoScene::KeyUp(int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance().ChangeScene(eScene::SCENE_TITLE);
		break;
	default:
		break;
	}
}