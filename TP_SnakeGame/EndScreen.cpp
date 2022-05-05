#include "EndScreen.h"
#include "Game.h"

namespace snake_game
{
	EndScreen::EndScreen(Game* game) : Screen(game)
	{
		endGameTexture = LoadTexture("ressources/gameOver4.png");
		setTexture(endGameTexture);
	}
	void EndScreen::draw()
	{
		Fruit& fruit = game->getFruit();
		
		DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
		DrawTextureV(endGameTexture, Vector2{ 350, 100 }, RAYWHITE);
		DrawTextEx(*font, TextFormat("FINAL SCORE: %i", fruit.getGameScore()),
		    Vector2{ 480, 460 }, 50, 5, WHITE);
		DrawTextEx(*font, "PRESS ENTER to RETURN to TITLE SCREEN", Vector2{ 340, 550 }, 30, 5, SKYBLUE);
	}
	void EndScreen::setTexture(Texture& texture)
	{
		endGameTexture.width = (int)_endGameSize.x;
		endGameTexture.height = (int)_endGameSize.y;
	}
}