#pragma once


class Circle {
public:
	Circle(float radius);
	inline float GetRadius() const noexcept { return _radius; }

private:
	float _radius;
};