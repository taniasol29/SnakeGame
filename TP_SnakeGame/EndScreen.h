#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include "raylib.h"
#include "Screen.h"

namespace snake_game
{
	class EndScreen : public Screen
	{
	public:
		EndScreen(Game* game);
		void draw();
		void setTexture(Texture& texture);
	private:
		Texture endGameTexture;
		Vector2 _endGameSize{ 600.f, 300.f };
	};
}



#endif // !ENDSCREEN_H
