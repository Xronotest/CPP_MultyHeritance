#pragma once 
#ifndef FORMCOMPAR_HPP
#define FORMCOMPAR_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparator.hpp"

class FormCompar : public Comparator
{
public:
    bool IsCompar(const Toys& toy, const Frame& frame) const override
    {
        return toy.GetForm().IsEqual(frame.GetForm());
    }
};

#endif // !FORMCOMPAR_HPP