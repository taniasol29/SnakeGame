#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H
#include "raylib.h"
#include "Screen.h"

namespace snake_game
{
	class TitleScreen : public Screen
	{
	public:
		TitleScreen(Game* game);
		void draw();
		void setTexture(Texture &texture);
	private:
		Texture snakeTexture;
		Vector2 _snakeSize{ 310.0f, 370.0f };
	};
}

#endif // !TITLE_SCREEN_H

