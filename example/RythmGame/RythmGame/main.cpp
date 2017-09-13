#include <stdio.h>
#include "SDL.h"

#include "GameSystem.h"
//#include "GameScene.h"
//#include "TitleScene.h"
#include "SceneManager.h"
#include "SDL_ttf.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

	if (TTF_Init() < 0) {
		printf("Error Init SDL Font\n");
	}
	atexit(TTF_Quit);

	int windowWidth = GameSystem::GetInstance().GetWindowWidth();
	int windowHeight = GameSystem::GetInstance().GetWindowHeight();

	SDL_Window* sdlWindow = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, 0);
	GameSystem::GetInstance().SetRender(sdlRenderer);

	SDL_GL_SetSwapInterval(0);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);

	SceneManager::GetInstance().ChangeScene("GameScene");

	int frame = 0;
	int oldFrame = 0;
	int currentTick = SDL_GetTicks();
	int oldTick = currentTick;
	SDL_Event sdlEvent;
	while (1)
	{
		currentTick = SDL_GetTicks();
		frame = (currentTick % 1000) * 60;	// 60frame
		frame /= 1000;
		if (oldFrame != frame)
		{
			oldFrame = frame;

			int deltaTime = currentTick - oldTick;
			oldTick = currentTick;

			//printf("Tick %d %d %d\n", SDL_GetTicks(), deltaTime, frame);

			if (SDL_PollEvent(&sdlEvent))
			{
				if (SDL_QUIT == sdlEvent.type)
					break;

				if (SDL_KEYUP == sdlEvent.type)
				{
					if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
					{
						SDL_Event quitEvent;
						quitEvent.type = SDL_QUIT;
						SDL_PushEvent(&quitEvent);	// 큐 데이터 타입
					}
					SceneManager::GetInstance().KeyUp(sdlEvent.key.keysym.sym);
				}

				if (SDL_KEYDOWN == sdlEvent.type)
				{
					SceneManager::GetInstance().KeyDown(sdlEvent.key.keysym.sym);
				}
			}

			SceneManager::GetInstance().Update(deltaTime);
			
			SDL_GL_SwapWindow(sdlWindow);
			SDL_RenderClear(sdlRenderer);
			{
				SceneManager::GetInstance().Render();
			}
			SDL_RenderPresent(sdlRenderer);
		}
	}
	/*
	scene->Deinit();
	delete scene;
	*/
	
	return 0;
}
