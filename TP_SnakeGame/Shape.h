#ifndef SHAPE_H
#define SHAPE_H
#include "raylib.h"
#include <vector>
using namespace std;


namespace snake_game
{
	class Shape
	{
	public:
		Shape();
		virtual ~Shape();

		void setPos(int, int);
		int getPosX();
		int getPosY();

		void setColor(Color);
		Color getColor();

		virtual void draw() = 0;

	protected:
		Color _color;
		Vector2 _point;
	};
}


#endif // !SHAPE_H

