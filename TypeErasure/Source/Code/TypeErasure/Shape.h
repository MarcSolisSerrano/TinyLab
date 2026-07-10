#pragma once
#include <utility>


class Shape {
private:
	struct ShapeConcept {
	public:
		virtual void Draw() const = 0;
		virtual ~ShapeConcept() = default;
	};

	template <typename T>
	struct ShapeModel : public ShapeConcept {

		ShapeModel(T&& object) : _object(std::forward<T>(object)) 
		{};

		void Draw() const override
		{
			::Draw(_object);
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

	Shape(const Shape& shape) = delete;
	Shape(Shape&& shape) noexcept = default;
	Shape& operator=(const Shape& shape) = delete;
	Shape& operator=(Shape&& shape) noexcept = default;

};