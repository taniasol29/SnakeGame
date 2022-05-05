#include "TitleScreen.h"
#include "Constantes.h"



namespace snake_game
{
    TitleScreen::TitleScreen(Game* game) : Screen(game)
    {
       snakeTexture = LoadTexture("ressources/Snake1.png");
       setTexture(snakeTexture);
    }

    void TitleScreen::draw()
	{
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GOLD);
        DrawTextureV(snakeTexture, Vector2{ 930, 320 }, RAYWHITE);
        DrawTextEx(*font, GAME_TITLE.c_str(), Vector2{280, 220}, 100, 10, BLUE);
        DrawTextEx(*font, "PRESS ENTER to PLAY", Vector2{430, 400}, 30, 5, DARKGREEN);
	}
    
    void TitleScreen::setTexture(Texture& texture)
    {
        snakeTexture.width = _snakeSize.x;
        snakeTexture.height = _snakeSize.y;
    }
}