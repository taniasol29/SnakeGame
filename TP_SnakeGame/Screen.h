#ifndef SCREEN_H
#define SCREEN_H
#include "raylib.h"
#include "snake.h"
#include "fruit.h"
#include "Constantes.h"


namespace snake_game
{  
	class Game;

	class Screen
	{
	public:
		Screen(Game* game);
		~Screen();

		void setFont(Font *font);
		
	protected:
		Font* font;
		Game* game;

	public:
		virtual void draw() = 0;
	};
}


#endif // !SCREEN_H

