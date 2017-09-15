#include <stdio.h>
#include <sdl.h>

#include "TitleScene.h"

#include "SceneManager.h"
#include "GameSystem.h"
#include "Sprite.h"

TitleScene::TitleScene()
{
	_backgroundSprite = NULL;
}

TitleScene::~TitleScene()
{
	Deinit();
}

void TitleScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr.csv", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance().GetWindowWidth() / 2, GameSystem::GetInstance().GetWindowHeight() / 2);
}

void TitleScene::Deinit()
{

}

void TitleScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}

void TitleScene::Render()
{
	_backgroundSprite->Render();
}

void TitleScene::KeyUp(int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance().ChangeScene(eScene::SCENE_GAME);
		break;
	default:
		break;
	}
}