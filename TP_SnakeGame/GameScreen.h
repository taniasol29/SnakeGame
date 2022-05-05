#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "raylib.h"
#include "Screen.h"


namespace snake_game
{
	class GameScreen : public Screen
	{
	public:
		GameScreen(Game* game);
		void draw();
	private:
		void drawGrid();
	};
}


#endif // !GAMESCREEN_H

