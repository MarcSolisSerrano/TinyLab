#pragma once
#include <utility>


class Shape {
private:
	struct ShapeConcept {
	public:
		virtual void Draw() const = 0;
		virtual std::unique_ptr<ShapeConcept> Clone() const = 0;
		virtual ~ShapeConcept() = default;
	};

	template <typename T>
	struct ShapeModel : public ShapeConcept {

		ShapeModel(T&& object) : _object(std::forward<T>(object)) 
		{};

		void Draw() const override final
		{
			::Draw(_object);
		}

		std::unique_ptr<ShapeConcept> Clone() const override final
		{
			return std::make_unique<ShapeModel>(*this);
		}

		virtual ~ShapeModel() = default;

		T _object;
	};

	friend void Draw(const Shape& shape)
	{
		shape._modelImpl->Draw();
	}

	std::unique_ptr<ShapeConcept> _modelImpl;

public:
	template<typename T>
	Shape(T&& object) : _modelImpl{ new ShapeModel<T>(std::forward<T>(object)) }
	{};

	Shape(const Shape& shape);
	Shape(Shape&& shape) noexcept = default;
	Shape& operator=(const Shape& shape);
	Shape& operator=(Shape&& shape) noexcept = default;

};

Shape::Shape(const Shape& shape) : _modelImpl{shape._modelImpl->Clone()}
{}

Shape& Shape::operator=(const Shape& shape)
{
	_modelImpl = shape._modelImpl->Clone();

	return *this;
}
