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
	SceneManager();		// �ٸ� ������ �Ǽ��� �������� �ʵ���, �����ڸ� �����̺����� �����.

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