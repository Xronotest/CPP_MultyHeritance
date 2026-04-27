#pragma once 
#ifndef FRAMES_HPP
#define FRAMES_HPP

#include <string>
#include <iostream>
#include <memory>

#include "Form.hpp"
#include "Toys.hpp"

class Frames
{
public:
	Frames(const Form& form) :form_(std::make_unique<Form>(form)) {}

	bool IsSame(const Frames& other) { return this == &other; }

	const Form& GetForm()const { return *form_; }

	bool IsFit(const Toys& toy) const
	{
		return form_->IsEqual(toy.GetFrom());
	}
	//void Collect(const Toys& toy; уместен для объекта
	//который умеет хранить в себе игрушки
	//для рамки наприммер требовалось бы поле toy
	
private:
	std::unique_ptr<Form> form_;
};



#endif // !FRAMES_HPP

