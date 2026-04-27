#pragma once 
#ifndef TOYS_HPP
#define TOYS_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

class Toys
{
public:
	Toys(const Form& form):form_(std::make_unique<Form>(form)){}

	const Form& GetFrom()const { return *form_; }

	bool IsSame(const Toys& other)const { return this == &other; }
private:
	std::unique_ptr<Form> form_;


};



#endif // !TOYS_HPP

