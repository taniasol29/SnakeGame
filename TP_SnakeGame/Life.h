#ifndef LIFE_H
#define LIFE_H
#include "raylib.h"
#include "Snake.h"

namespace snake_game
{
	class Life
	{
	public:
		Life();
		~Life();

		void draw();

		void setTexture(Texture* texture);
		void setSnake(Snake* snake);

	private:
		Vector2 _heartSize{ 38.0f, 38.0f };
		Texture* texture;
		Snake* snake;
	};

	
}







#endif // !LIFE_H

