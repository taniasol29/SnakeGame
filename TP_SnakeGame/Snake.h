#ifndef SNAKE_H
#define SNAKE_H
#include "raylib.h"
#include "Rectangle.h"

namespace snake_game
{
	class Snake 
	{
	public:
		Snake();
		~Snake();

		void displaySnake();
		void addBodyPart(float, float, Color);

		void update();
		Rectangle getSnakeBodyPart(int i);
		int getCounterTail();
		bool checkDirection(KeyboardKey keyPressed);
		void checkDeath();
		bool isSnakeDead() { return isDead; }
		void resetSnake();
		void resetLives();
		void checkBodyCollision();
		int getLives();

	private:
		vector<Rectangle> _recs;
		vector<Vector2> _tail;
		Vector2 direction;
		bool isDead;
		int frameCounter;
		int lives;
	};
}









#endif // !SNAKE_H

