#include <stdio.h>
#include <sdl.h>

#include "ResultScene.h"

#include "SceneManager.h"
#include "GameSystem.h"
#include "Sprite.h"

ResultScene::ResultScene()
{
	_backgroundSprite = NULL;
}

ResultScene::~ResultScene()
{
	Deinit();
}

void ResultScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr.csv", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance().GetWindowWidth() / 2, GameSystem::GetInstance().GetWindowHeight() / 2);
}

void ResultScene::Deinit()
{

}

void ResultScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}

void ResultScene::Render()
{
	_backgroundSprite->Render();
}

void ResultScene::KeyUp(int keyCode)
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