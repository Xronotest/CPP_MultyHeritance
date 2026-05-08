#pragma once 
#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Toys.hpp"
#include "Frame.hpp"

class Comparator
{
public:
    virtual bool IsCompar(const Toys& toy, const Frame& frame) const = 0;
    virtual ~Comparator() {}
};

#endif // !COMPARATOR_HPP