#include "raylib.h"
#include "Code_Utilities_Light_v2.h"
#include "Game.h"
#include "Screen.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Snake.h"
#include "Life.h"
using namespace BdB;

int main()
{
	snake_game::Game{}.run();

	return 0;
}
