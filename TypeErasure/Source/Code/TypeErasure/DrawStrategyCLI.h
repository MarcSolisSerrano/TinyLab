#pragma once
#include "Circle.h"
#include "Square.h"
#include <iostream>


void Draw(const Circle& circle)
{
	std::cout << "Circle o ( " << circle.GetRadius() << "r )" << std::endl;
}

void Draw(const Square& square)
{
	std::cout << "Square [] ( " << square.GetSide() << " )" << std::endl;
}