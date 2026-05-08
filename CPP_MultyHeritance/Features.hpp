#pragma once 
#ifndef FEATURES_HPP
#define FEATURES_HPP

#include <iostream>
#include <string>
#include <ctime>



class Features
{
public:
	enum class Variants
	{
		colored,
		heavy,
		smooth,
		easy,
		little
	};
	Features(Variants variant)
	{
		variant_ = variant;
		switch (variant)
		{
		case Variants::colored:
			name_ = "colored";
			break;
		case Variants::heavy:
			name_ = "heavy";
			break;
		case Variants::smooth:
			name_ = "smooth";
			break;
		case Variants::easy:
			name_ = "easy";
			break;
		case Variants::little:
			name_ = "little";
			break;
		}
	};

	std::string GetName()const
	{
		return name_;
	}

	Variants GetVariant()const
	{
		return variant_;
	}

	virtual bool operator ==(const Features& rso)const
	{
		return variant_ == rso.variant_;
	}

	virtual bool IsEqual(const Features& rso)const
	{
		return *this == rso;
	}

	static void SetFtrCount(int dif)
	{
		count_ = dif - 1;
	}

	static void SetFtrCount(int count, bool changed)
	{
		if (count > 5)
		{
			count = 5;
		}
		else if (count < 0)
		{
			count = 0;
		}
		count_ = count;
	}

	static int GetFtrCount()
	{
		return count_;
	}

	static Features GetFeature(int index)
	{
		switch (index)
		{
		case 0:
			return Features::Variants::colored;
		case 1:
			return Features::Variants::heavy;
		case 2:
			return Features::Variants::smooth;
		case 3:
			return Features::Variants::easy;
		case 4:
			return Features::Variants::little;
		}
	}

private:
	Variants variant_;
	std::string name_;
	static int count_;

};

#endif // !FEATURES_HPP