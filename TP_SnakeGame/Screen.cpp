#include "Screen.h"
#include "Constantes.h"



namespace snake_game
{
    Screen::Screen(Game* game)
	{
        this->game = game;
	}

	Screen::~Screen() { }

    void Screen::setFont(Font* font)
    {
        this->font = font;
    }
}
