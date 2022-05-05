#include "Shape.h"



namespace snake_game
{
	Shape::Shape() { }

	Shape::~Shape() { }

	void Shape::setPos(int x, int y)
	{
		_point.x = x;
		_point.y = y;
	}

	int Shape::getPosX() { return _point.x; }
	
	int Shape::getPosY() { return _point.y; }

	void Shape::setColor(Color color) { _color = color; }
	
	Color Shape::getColor() { return _color; }
}
