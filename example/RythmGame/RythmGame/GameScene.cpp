#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sdl_mixer.h"
#include "sdl_ttf.h"

#include "GameSystem.h"
#include "Sprite.h"
#include "Track.h"
#include "GameScene.h"
#include "Font.h"


GameScene::GameScene()
{
	_backgroundSprite = NULL;
	_textFont = NULL;
}

GameScene::~GameScene()
{
	Deinit();
}

void GameScene::Init()
{
	/*
	float gameTime = 60.0f * 2.0f;
	int trackHeight = GameSystem::GetInstance().GetWindowHeight() * 60;
	GameSystem::GetInstance().SetGameTime(gameTime);
	GameSystem::GetInstance().SetTrackHeight(trackHeight);
	*/
	char filePath[256];
	sprintf(filePath, "../Resources/%s", "gameplay.csv");
	FILE* fp = fopen(filePath, "r");
	if (NULL == fp)
	{
		printf("File Open Error %s\n", filePath);
	}

	char backgroundSprName[256];
	char musicFileName[256];
	float gameTimeMin;

	char buffer[1024];
	char* record = fgets(buffer, sizeof(buffer), fp);
	while (true)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;

		{
			char* token = strtok(record, ",\n");
			if (!strcmp(token, "Background"))
			{
				token = strtok(NULL, ",\n");
				strcpy(backgroundSprName, token);
			}
			else if (!strcmp(token, "MusicName"))
			{
				token = strtok(NULL, ",\n");
				strcpy(musicFileName, token);
			}
			else if (!strcmp(token, "PlayTime"))
			{
				token = strtok(NULL, ",\n");
				gameTimeMin = atof(token);
			}
		}
	}

	int BPM = 120;
	int tempo = BPM / 60;

	float gameTime = 60.0f * gameTimeMin;
	int trackHeight = GameSystem::GetInstance().GetWindowHeight() * (gameTime * tempo);
	trackHeight /= 2;
	GameSystem::GetInstance().SetGameTime(gameTime);
	GameSystem::GetInstance().SetTrackHeight(trackHeight);

	fclose(fp);

	//_backgroundSprite = new Sprite("backgroundspr.csv", true);
	_backgroundSprite = new Sprite(backgroundSprName, true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance().GetWindowWidth() / 2, GameSystem::GetInstance().GetWindowHeight() / 2);

	_track = new Track();
	_track->Init();

	_gameDuration = 0;

	//Font
	/*TTF_Font* sansFont = TTF_OpenFont("../Resources/Font/arialbd.ttf", 24);
	SDL_Color black = { 0, 0, 0 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sansFont, "Print test txt", black);
	_textTexture = SDL_CreateTextureFromSurface(GameSystem::GetInstance().GetRenderer(), surfaceMessage);
	*/
	_textFont = new Font("arialbd.ttf", 24);


	// 음악 플레이
	int result = Mix_Init(MIX_INIT_MP3);		// mp3 플레이를 위한 세팅
	if (MIX_INIT_MP3 == result)
	{
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		//Mix_Music* music = Mix_LoadMUS("../Resources/Music/PSY - GANGNAM STYLE.mp3");
		char musicFilePath[256];
		sprintf(musicFilePath, "../Resources/Music/%s", musicFileName);
		Mix_Music* music = Mix_LoadMUS(musicFilePath);
		if (NULL != music)
		{
			printf("Play Music\n");

			char text[256];
			sprintf(text, "Score %d", 50);
			_textFont->SetText(text);

			Mix_PlayMusic(music, 1);
		}
		else
		{
			printf("Error LoadMusic\n");
		}
	}
	else
	{
		printf("Error init MP3\n");
	}
}

void GameScene::Deinit()
{
	_track->Deinit();
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}
	if (NULL != _textFont)
	{
		delete _textFont;
		_textFont = NULL;
	}
}

void GameScene::Update(int deltaTime)
{
	if(_gameDuration <= GameSystem::GetInstance().GetGameTimeTick() + 2000)
	{
		_backgroundSprite->Update(deltaTime);
		_track->Update(deltaTime);

		_gameDuration += deltaTime;
	}
	else
	{
		GameSystem::GetInstance().Quit();
	}
}

void GameScene::Render()
{
	_backgroundSprite->Render();
	_track->Render();

	/*
	SDL_Rect destRect;

	destRect.x = 100;
	destRect.y = 100;
	destRect.w = 250;
	destRect.h = 250;
	SDL_RenderCopy(GameSystem::GetInstance(),GetRenderer(), _textFont, NULL, &destRect);
	*/
	_textFont->Render();
}

void GameScene::KeyDown(int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		_track->KeyDown();
		break;
	}
}

void GameScene::KeyUp(int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		_track->KeyUp();
		break;
	}
}
