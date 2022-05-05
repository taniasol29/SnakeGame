#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "Screen.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Snake.h"
#include "Fruit.h"
#include "TitleScreen.h"
#include "Life.h"
#include <vector>

namespace snake_game
{
    class Game
    {
    public:
        Game();
        ~Game();

        void run();
        Snake& getSnake() { return snake; }
        Fruit& getFruit() { return fruit; }
        Life& getLife() { return life; }
        void setState(GameState state) { currentState = state; }
 
    private:
        vector<Screen*> screens;
        GameState currentState;
        Snake snake;
        Fruit fruit;
        Life life;
        Music music;
        Font titleFont;
        Font finalScoreFont;
        Texture fruitTexture;
        Texture heartTexture;

    private:
        void logicPhase();
        void drawPhase();
        void loadResources(); 
    };
}

#endif // !GAME_H

