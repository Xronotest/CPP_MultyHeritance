#pragma once 
#ifndef FRAMES_HPP
#define FRAMES_HPP

#include <string>
#include <iostream>
#include <memory>

#include "Form.hpp"
#include "Toys.hpp"

class Frame
{
public:
	Frame(const Form& form, std::string name, int ftrCount) :form_(std::make_unique<Form>(form))
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

	bool IsSame(const Frame& other) { return this == &other; }

	const Form& GetForm()const { return *form_; }

	//bool IsFit(const Toys& toy) const
	//{
	//	return form_->IsEqual(toy.GetForm());
	//}
	//void Collect(const Toys& toy; уместен для объекта
	//который умеет хранить в себе игрушки
	//для рамки наприммер требовалось бы поле toy
	
	static Frame GetFrame(int index, std::string name, int ftrCount)
	{
		switch (index)
		{
		case 0:
			return Frame(Form::Shapes::square, name, ftrCount);
		case 1:
			return Frame(Form::Shapes::circle, name, ftrCount);
		case 2:
			return Frame(Form::Shapes::star, name, ftrCount);
		case 3:
			return Frame(Form::Shapes::triangle, name, ftrCount);
		case 4:
			return Frame(Form::Shapes::hexagon, name, ftrCount);
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



#endif // !FRAMES_HPP

