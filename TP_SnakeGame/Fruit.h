#ifndef FRUIT_H
#define FRUIT_H
#include "raylib.h"
#include "Shape.h"
#include "Snake.h"

namespace snake_game
{
	class Fruit : public Shape
	{
	public:
		Fruit();
		~Fruit();

		Vector2 getRandomPos();
		const Vector2& getFruitSize() const;
		void draw();
		void setActive(bool);
		void setSnake(Snake &snake);
		void eatedBySnake();
		void setGameScore();
		int getGameScore();
		void resetScore();
		void setTexture(Texture* texture);
	private:
		Vector2 _fruitSize{ 39.0f, 39.0f };
		bool _isActive;
		Snake* snake;
		int _gameScore;
		Texture *texture;
	};
}

#endif // !FRUIT_H

