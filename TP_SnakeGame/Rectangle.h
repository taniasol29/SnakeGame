#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "raylib.h"
#include "Shape.h"


namespace snake_game
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(float, float, Color);
		~Rectangle();

		const Vector2& getRectSize() const;
		void draw();

	private:
		Vector2 _rectangleSize{ 40.0f, 40.0f };
	};
}



#endif // !RECTANGLE_H

