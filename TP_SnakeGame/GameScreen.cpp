#include "GameScreen.h"
#include "Snake.h"
#include "Fruit.h"
#include "Game.h"
#include "Life.h"


namespace snake_game
{
    GameScreen::GameScreen(Game* game) : Screen(game)
    {
    }
    void GameScreen::draw()
	{
        Snake& snake = game->getSnake();
        Fruit& fruit = game->getFruit();
        Life& life = game->getLife();
        
        ClearBackground(BLANK);
        drawGrid();
        DrawText(TextFormat("SCORE: %i", fruit.getGameScore()), 10, 10, 30, SKYBLUE);
        snake.displaySnake();    
        fruit.draw();
        life.draw();
        if (snake.isSnakeDead()) { game->setState(ENDING); }
	}

    void GameScreen::drawGrid()
    {
        int posX = 0, posY = 0;
        int offset = 20;
        do
        {
            DrawLine(posX += offset, 0, posX += offset, SCREEN_HEIGHT, GRAY);
            DrawLine(0, posY += offset, SCREEN_WIDTH, posY += offset, GRAY);

        } while (posX < SCREEN_WIDTH || posY < SCREEN_HEIGHT);
    }
}