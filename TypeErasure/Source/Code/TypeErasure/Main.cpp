#include "DrawStrategyCLI.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <vector>


int main()
{
	std::vector<Shape> shapes;

	shapes.reserve(3);

	shapes.emplace_back(Circle(2.5f));
	shapes.emplace_back(Square(3.f));
	shapes.emplace_back(Circle(5.f));


	for(auto&& shape : shapes)
	{
		Draw(shape);
	}


	return 0;
}