#include "DrawStrategyCLI.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <vector>
#include <memory>

int main()
{
	std::vector<std::unique_ptr<ShapeConcept>> shapes;

	shapes.reserve(3);

	shapes.emplace_back(std::make_unique<ShapeModel<Circle>>(Circle(2.5f)));
	shapes.emplace_back(std::make_unique<ShapeModel<Square>>(Square(3.f)));
	shapes.emplace_back(std::make_unique<ShapeModel<Circle>>(Circle(5.f)));


	for(auto&& shape : shapes)
	{
		shape->Draw();
	}


	return 0;
}