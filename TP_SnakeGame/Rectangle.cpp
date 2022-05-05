#include "Rectangle.h"



namespace snake_game
{
	Rectangle::Rectangle(float x, float y, Color color)
		: Shape()
	{
		Shape::setPos(x, y);
		Shape::setColor(color);
	}

	Rectangle::~Rectangle() { }

	const Vector2& Rectangle::getRectSize() const
	{
		return _rectangleSize;
	}

	void Rectangle::draw()
	{
		Vector2 vec;
		vec.x = Shape::getPosX(); 
		vec.y = Shape::getPosY(); 
		
		DrawRectangleV(vec, _rectangleSize, Shape::getColor());
	}
}
