#pragma once

enum eScene {
	SCENE_LOGO,
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT
};

class Scene;

class SceneManager
{
	// Singleton
private:
	static SceneManager* _instance;

public:
	static SceneManager& GetInstance();

private:
	SceneManager();		// 다른 곳에서 실수로 생성하지 않도록, 생성자를 프라이빗으로 만든다.

public:
	~SceneManager();

private:
	Scene* _scene;

public:
	void ChangeScene(eScene scene);
	void Update(int deltaTime);
	void Render();
	void KeyDown(int keyCode);
	void KeyUp(int keyCode);
};