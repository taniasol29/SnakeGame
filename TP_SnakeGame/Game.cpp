#include "Game.h"
#include "Screen.h"
#include "TitleScreen.h"
#include "GameScreen.h"
#include "EndScreen.h"
#include "TitleScreen.h"
#include "Constantes.h"
#include "Life.h"


namespace snake_game
{
	Game::Game()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE.c_str());
		SetTargetFPS(TARGET_FPS);
		//audio
		InitAudioDevice();

		currentState = TITLE;
		snake.addBodyPart(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, BLUE);
		fruit.setActive(false);
		fruit.setSnake(snake);
		fruit.setGameScore();
		life.setSnake(&snake);

		screens.push_back(new TitleScreen(this));
		screens.push_back(new GameScreen(this));
		screens.push_back(new EndScreen(this));
	}

	Game::~Game() 
	{ 
		for (int i = 0; i < screens.size(); i++)
		{
			delete screens[i];
		}
		CloseWindow(); 
	}
	
	void Game::logicPhase() 
	{ 
		switch (currentState)
		{
		case TITLE:
		{
			snake.resetSnake();
			fruit.resetScore();
			snake.resetLives();
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) { currentState = GAMEPLAY; }
		}break;
		case GAMEPLAY:
		{
			snake.update();
		}break;
		case ENDING:
		{
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) { currentState = TITLE; }
		}break;
		default: break;
		}
	}

	void Game::drawPhase()
	{
		BeginDrawing();
		{
			screens[currentState]->draw();
		}
		EndDrawing();
	}

	void Game::loadResources()
	{
		titleFont = LoadFont("ressources/fonts/Grooven-Shine.otf");
		finalScoreFont = LoadFont("ressources/fonts/BiggyJohn.ttf");
		screens[TITLE]->setFont(&titleFont);
		screens[ENDING]->setFont(&finalScoreFont);
		//audio
		music = LoadMusicStream("ressources/music/music1.mp3");
		PlayMusicStream(music);
		//pomme image dans Game screen
		fruitTexture = LoadTexture("ressources/pomme2.png");
		fruit.setTexture(&fruitTexture);
		//heart image Game screen
		heartTexture = LoadTexture("ressources/heart1.png");
		life.setTexture(&heartTexture);
	}

	void Game::run()
	{
		loadResources();
		
		while (!WindowShouldClose())
		{
			UpdateMusicStream(music);
			logicPhase();
			drawPhase();
		}
	}
}
