#include "SceneManager.h"
#include <stdio.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "LogoScene.h"
#include "ResultScene.h"

#include <sdl.h>

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
	_scene = NULL;
}

SceneManager::~SceneManager()
{
	if (NULL != _scene) {
		_scene->Deinit();
		delete _scene;
	}
}

// Singleton
SceneManager& SceneManager::GetInstance()
{
	if (NULL == _instance)
	{
		_instance = new SceneManager();
	}
	return *_instance;
}

void SceneManager::ChangeScene(eScene scene) {
	if (NULL != _scene) {
		_scene->Deinit();
		delete _scene;
	}
	
	switch (scene) {
	case eScene::SCENE_LOGO:
		_scene = new LogoScene();
		break;
	case eScene::SCENE_TITLE:
		_scene = new TitleScene();
		break;
	case eScene::SCENE_GAME:
		_scene = new GameScene();
		break;
	case eScene::SCENE_RESULT:
		_scene = new ResultScene();
		break;
	}
	if(NULL != _scene)
		_scene->Init();
}
void SceneManager::Update(int deltaTime) {
	_scene->Update(deltaTime);
}
void SceneManager::Render() {
	_scene->Render();
}
void SceneManager::KeyDown(int keyCode) {
	_scene->KeyDown(keyCode);
}
void SceneManager::KeyUp(int keyCode) {
	_scene->KeyUp(keyCode);
}