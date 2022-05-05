#include "Life.h"
#include "raylib.h"
#include "Constantes.h"

namespace snake_game
{
	Life::Life()
	{
	}
	Life::~Life()
	{
	}
	void Life::draw()
	{
		float offset = 40.f;
		for (int i = 1; i <= snake->getLives(); i++)
		{
			DrawTextureV(*texture, Vector2{SCREEN_WIDTH - offset * i, 0 }, RAYWHITE);
		}
	}
	void Life::setTexture(Texture* texture)
	{
		this->texture = texture;
		this->texture->width = _heartSize.x;
		this->texture->height = _heartSize.y;
	}
	void Life::setSnake(Snake* snake)
	{
		this->snake = snake;
	}
}