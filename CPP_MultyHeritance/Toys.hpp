#pragma once 
#ifndef TOYS_HPP
#define TOYS_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Form.hpp"
#include "Features.hpp"

class Toys
{
public:
	Toys(const Form& form, std::string name, int ftrCount) :form_(std::make_unique<Form>(form))
	{
		name_ = name;
		ftrsCount_ = ftrCount;
		ftrArr_ = GenerateFtr();
	}


	Features** GenerateFtr()
	{

		ftrArr_ = new Features * [ftrsCount_];
		int tempArr[5]{ 0, 1, 2, 3, 4 };
		int maxCount = 5;

		for (int i = 0; i < ftrsCount_; ++i)
		{
			int temp = rand() % maxCount;
			int index = tempArr[temp];

			ftrArr_[i] = new Features(Features::GetFeature(index));

			tempArr[temp] = tempArr[maxCount - 1];
			maxCount--;
		}
		return ftrArr_;
	}

	void CleareFtr()
	{
		for (int i = 0; i < ftrsCount_; ++i)
		{
			delete ftrArr_[i];
			ftrArr_[i] = nullptr;
		}

		delete[] ftrArr_;
		ftrArr_ = nullptr;
	}

	 Features GetFeature(int index)const 
	 { 
		 return *ftrArr_[index];
	 }

	const Form& GetForm()const { return *form_; }

	bool IsSame(const Toys& other)const { return this == &other; }

	static Toys GetToy(int index, std::string name, int ftrCount)
	{
		switch (index)
		{
		case 0:
			return Toys(Form::Shapes::square, name, ftrCount);
		case 1:
			return Toys(Form::Shapes::circle, name, ftrCount);
		case 2:
			return Toys(Form::Shapes::star, name, ftrCount);
		case 3:
			return Toys(Form::Shapes::triangle, name, ftrCount);
		case 4:
			return Toys(Form::Shapes::hexagon, name, ftrCount);
		}
	}

	std::string GetName()
	{
		return name_;
	}
private:
	std::unique_ptr<Form> form_;
	std::string name_;
	Features** ftrArr_;
	int ftrsCount_;
};



#endif // !TOYS_HPP

