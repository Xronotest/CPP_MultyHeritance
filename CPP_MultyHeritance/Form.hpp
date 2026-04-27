#pragma once 
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Form
{
public:
	enum class Shapes
	{
		circle,
		triangle,
		square,
		star,
		hexagon
	};
	Form(Shapes shape)
	{
		shape_ = shape;
		switch (shape)
		{
		case Shapes::circle:
			name_ = "circle";
			break;
		case Shapes::triangle:
			name_ = "triangle";
			break;
		case Shapes::square:
			name_ = "square";
			break;
		case Shapes::star:
			name_ = "star";
			break;
		case Shapes::hexagon:
			name_ = "hexagon";
			break;
		}
	};

	std::string GetName()const
	{
		return name_;
	}

	Shapes GetShape()const
	{
		return shape_;
	}

	virtual bool operator ==(const Form& rso)const
	{
		return shape_ == rso.shape_;
	}

	virtual bool IsEqual(const Form& rso)const
	{
		return *this == rso;
	}
private:
	Shapes shape_;
	std::string name_;

};



#endif // !FORM_HPP

