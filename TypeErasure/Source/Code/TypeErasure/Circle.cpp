#include "Circle.h"
#include <cassert>


Circle::Circle(float radius) : _radius(radius)
{
	assert(_radius > 0);
}
