#include <stdio.h>
#include "SDL.h"
#include "GameSystem.h"


// 헤더에서 선언한 정적 멤버들을 다시 선언해줘야만, 일반 멤버 변수처럼 사용할 수 있다.
GameSystem* GameSystem::_instance = NULL;

GameSystem::GameSystem()
{
}

GameSystem::~GameSystem()
{

}

// Singleton
GameSystem& GameSystem::GetInstance()
{
	if (NULL == _instance)
	{
		_instance = new GameSystem();
	}
	return *_instance;
}

int GameSystem::GetWindowWidth()
{
	return 1024;
}

int GameSystem::GetWindowHeight()
{
	return 800;
}

void GameSystem::Quit()
{
	SDL_Event quitEvent;
	quitEvent.type = SDL_QUIT;
	SDL_PushEvent(&quitEvent);	// 큐 데이터 타입
}

void GameSystem::SetGameTime(float sec)
{
	_gameTimeTick = (int)(sec * 1000.0f);
}

int GameSystem::GetGameTimeTick()
{
	return _gameTimeTick;
}

void GameSystem::SetTrackHeight(int height)
{
	_trackHeight = height;
}

int GameSystem::GetTrackHeight()
{
	return _trackHeight;
}

void GameSystem::SetRender(SDL_Renderer* sdlRenderer)
{
	_sdlRenderer = sdlRenderer;
}

SDL_Renderer* GameSystem::GetRenderer()
{
	return _sdlRenderer;
}