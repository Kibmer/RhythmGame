#include "SceneManager.h"
#include <stdio.h>
#include "TitleScene.h"
#include "GameScene.h"

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

void SceneManager::ChangeScene(const char* str) {
	if (NULL != _scene) {
		_scene->Deinit();
		delete _scene;
	}
	
	/*switch (scene) {
	case scene::SCENE_TITLE:
		~~~~
		break;
	}*/
}
void SceneManager::Update(int deltaTime) {

}
void SceneManager::Render() {

}
void SceneManager::KeyDown(int keyCode) {

}
void SceneManager::KeyUp(int keyCode) {

}