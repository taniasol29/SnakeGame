#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>


namespace snake_game
{
	//screen 
	enum GameState { TITLE = 0, GAMEPLAY, ENDING };
	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;
	static const std::string GAME_TITLE = "SNAKE GAME";
	static const int TARGET_FPS = 60;

	//snake
	static const int SNAKE_LIVES = 3;



}
#endif // !CONSTANTES_H

