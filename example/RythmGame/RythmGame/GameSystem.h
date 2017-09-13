#pragma once
#include "SDL.h"

class GameSystem
{
	// Singleton
private:
	static GameSystem* _instance;

public:
	static GameSystem& GetInstance();

private:
	GameSystem();		// 다른 곳에서 실수로 생성하지 않도록, 생성자를 프라이빗으로 만든다.

public:
	~GameSystem();

	// Window Info
public:
	int GetWindowWidth();
	int GetWindowHeight();

	void Quit();


	// GameInfo
private:
	int _gameTimeTick;
	int _trackHeight;

public:
	void SetGameTime(float sec);
	int GetGameTimeTick();
	void SetTrackHeight(int height);
	int GetTrackHeight();


	// SDL
private:
	SDL_Renderer* _sdlRenderer;

public:
	void SetRender(SDL_Renderer* sdlRenderer);
	SDL_Renderer* GetRenderer();
};