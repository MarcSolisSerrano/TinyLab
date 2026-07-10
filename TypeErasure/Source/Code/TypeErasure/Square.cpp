#include "Square.h"
#include <cassert>


Square::Square(float side) : _side(side)
{
	assert(_side> 0.f);
}