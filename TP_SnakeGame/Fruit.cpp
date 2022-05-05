#include "Fruit.h"
#include "Constantes.h"
#include "Screen.h"
#include "raylib.h"
#include <iostream>



namespace snake_game
{
	Fruit::Fruit() { }

	Fruit::~Fruit() { }

	Vector2 Fruit::getRandomPos()
	{
		int SQUARE_SIZE = 40;
		int offsetx = (int)SCREEN_WIDTH % SQUARE_SIZE;
		int offsety = (int)SCREEN_HEIGHT % SQUARE_SIZE;

		Vector2 pos;
		pos.x = GetRandomValue(0, (SCREEN_WIDTH / SQUARE_SIZE) - 1) * SQUARE_SIZE + offsetx * 0.5;
		pos.y = GetRandomValue(0, (SCREEN_HEIGHT / SQUARE_SIZE) - 1) * SQUARE_SIZE + offsety * 0.5;
		
		return pos;
	}

	const Vector2& Fruit::getFruitSize() const { return _fruitSize; }

	void Fruit::draw()
	{
		if (!_isActive)
		{
			_isActive = true;

			Vector2 positionRandom = getRandomPos();
			setPos(positionRandom.x, positionRandom.y);
			DrawTextureV(*texture, _point, RAYWHITE);

			for (int i = 0; i < snake->getCounterTail(); i++)
			{
				while ((getPosX() == snake->getSnakeBodyPart(i).getPosX()) 
					&& (getPosY() == snake->getSnakeBodyPart(i).getPosY()))
				{
					positionRandom = getRandomPos();
					setPos(positionRandom.x, positionRandom.y);
					DrawTextureV(*texture, _point, RAYWHITE);
					i = 0;
				}
			}
		}
		else
		{
			DrawTextureV(*texture, _point, RAYWHITE);
			eatedBySnake();
		}
	}

	void Fruit::setActive(bool active) { _isActive = active; }

	void Fruit::setSnake(Snake &pSnake) { snake = &pSnake; }

	void Fruit::eatedBySnake()
	{
		if ((snake->getSnakeBodyPart(0).getPosX() < (getPosX() + getFruitSize().x)
		&& (snake->getSnakeBodyPart(0).getPosX() + snake->getSnakeBodyPart(0).getRectSize().x) > getPosX()) 
		&& (snake->getSnakeBodyPart(0).getPosY() < (getPosY() + getFruitSize().y) 
			&& (snake->getSnakeBodyPart(0).getPosY() + snake->getSnakeBodyPart(0).getRectSize().y) > getPosY()))
		{
			Rectangle rect = snake->getSnakeBodyPart(snake->getCounterTail() - 1);
			snake->addBodyPart(rect.getPosX(), rect.getPosY(), rect.getColor());
			_isActive = false;
			_gameScore++;
		}
	}

	void Fruit::setGameScore() { _gameScore = 0; }

	int Fruit::getGameScore() { return _gameScore; }

	void Fruit::resetScore()
	{
		_gameScore = 0;
	}
	void Fruit::setTexture(Texture* texture)
	{
		this->texture = texture;
		this->texture->width = _fruitSize.x;
		this->texture->height = _fruitSize.y;
	}
}
