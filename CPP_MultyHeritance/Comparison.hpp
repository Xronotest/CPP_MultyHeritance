#pragma once 
#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparator.hpp"

class Comparison
{
public:
    Comparison(Comparator* compar)
    {
        comparison_ = compar;
    }

    bool IsFit(const Toys& toy, const Frame& frame) const
    {
        return comparison_->IsCompar(toy, frame);
    }

private:
    Comparator* comparison_;
};

#endif // !COMPARISON_HPP