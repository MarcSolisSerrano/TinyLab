#pragma once
#include <utility>



struct ShapeConcept {
public:
	virtual void Draw() const = 0;
	virtual ~ShapeConcept() = default;
};


template <typename T>
struct ShapeModel : public ShapeConcept {

	ShapeModel(T&& shape) : _shape(std::forward<T>(shape)) {};

	void Draw() const override
	{
		::Draw(_shape);
	}

	virtual ~ShapeModel() = default;

private:
	T _shape;
};