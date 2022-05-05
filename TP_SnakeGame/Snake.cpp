#include "Snake.h"
#include "Screen.h"
#include "Constantes.h"



namespace snake_game
{
	Snake::Snake()
	{
		direction.x = 1.0f;
		direction.y = 0.0f;
		isDead = false;
		frameCounter = 0;
		lives = SNAKE_LIVES;
	}

	Snake::~Snake() { }

	void Snake::displaySnake()
	{
		for (Rectangle it : _recs)
		{
			it.draw();
		}
	}

	void Snake::addBodyPart(float posX, float posY, Color color)
	{
		if (_recs.size() == 0)
		{
			Rectangle bodyPart(posX, posY, color);
			_recs.push_back(bodyPart);
		}
		else
		{
			Rectangle bodyPart(_recs[_recs.size() - 1].getPosX(), _recs[_recs.size() - 1].getPosY(), color);   
			_recs.push_back(bodyPart);
		}
	}

	void Snake::update()
	{
		if (frameCounter % 10 == 0)
		{
			vector<Vector2> _prevPos;
			for (int i = 0; i < _recs.size(); i++)
			{
				int previousX = _recs[i].getPosX();
				int previousY = _recs[i].getPosY();
				Vector2 pos;
				pos.x = previousX;
				pos.y = previousY;
				_prevPos.push_back(pos);
			}
			for (int i = 1; i < _recs.size(); i++)
			{
				int previousX = _prevPos[i - 1].x;
				int previousY = _prevPos[i - 1].y;
				_recs[i].setPos(previousX, previousY); 
			}
			
			int x = _recs[0].getPosX() + _recs[0].getRectSize().x * direction.x;
			int y = _recs[0].getPosY() + _recs[0].getRectSize().y * direction.y;
			_recs[0].setPos(x, y);
			checkDeath();
		}
		frameCounter++;

		if (IsKeyPressed(KEY_LEFT) && checkDirection(KEY_LEFT))
		{
			direction.x = -1.0f;
			direction.y = 0.0f;
		}
		if (IsKeyPressed(KEY_RIGHT) && checkDirection(KEY_RIGHT))
		{
			direction.x = 1.0f;
			direction.y = 0.0f;
		}
		if (IsKeyPressed(KEY_UP) && checkDirection(KEY_UP))
		{
			direction.x = 0.0f;
			direction.y = -1.0f;
		}
		if (IsKeyPressed(KEY_DOWN) && checkDirection(KEY_DOWN))
		{
			direction.x = 0.0f;
			direction.y = 1.0f;
		}
	}

	Rectangle Snake::getSnakeBodyPart(int i) { return _recs[i]; }

	int Snake::getCounterTail() { return _recs.size(); }

	bool Snake::checkDirection(KeyboardKey keyPressed)
	{
		if (direction.x != 0)
		{
			return keyPressed == KEY_UP || keyPressed == KEY_DOWN;
		}
		else if (direction.y != 0)
		{
			return keyPressed == KEY_LEFT || keyPressed == KEY_RIGHT;
		}

		return false;
	}

	void Snake::checkDeath()
	{
		checkBodyCollision();
		const Vector2 &recSize = _recs[0].getRectSize();
		if (_recs[0].getPosX() < 0 || _recs[0].getPosX() > SCREEN_WIDTH - recSize.x)
		{
			lives--;
			resetSnake();
		}
		else if (_recs[0].getPosY() < 0 || _recs[0].getPosY() > SCREEN_HEIGHT - recSize.y)
		{
			lives--;
			resetSnake();
		}
		if (lives <= 0) { isDead = true; }	
	}

	void Snake::resetSnake()
	{
		isDead = false;
		_recs.clear();
		addBodyPart(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, BLUE);
	}

	void Snake::resetLives()
	{
		lives = SNAKE_LIVES;
	}

	void Snake::checkBodyCollision()
	{
		if (getCounterTail() > 1)
		{
			for (int i = 1; i < _recs.size(); i++)
			{
				if ((_recs[0].getPosX() == _recs[i].getPosX()
					&& (_recs[0].getPosY() == _recs[i].getPosY())))
				{
					lives--;
					resetSnake();
				}
			}
		}
	}

	int Snake::getLives()
	{
		return lives;
	}
}
