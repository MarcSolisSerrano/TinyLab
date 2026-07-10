#pragma once

class Square {
public:
	Square(float side);
	inline float GetSide() const noexcept { return _side; }

private:
	float _side;
};

