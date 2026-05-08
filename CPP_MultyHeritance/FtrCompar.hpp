#pragma once 
#ifndef FTRCOMPAR_HPP
#define FTRCOMPAR_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparator.hpp"

class FtrCompar : public Comparator
{
public:
    bool IsCompar(const Toys& toy, const Frame& frame) const override
    {
        int check = 0;
        for (size_t i = 0; i < Features::GetFtrCount(); i++)
        {
            check = 0;
            for (size_t j = 0; j < Features::GetFtrCount(); j++)
            {
                if (!toy.GetFeature(i).IsEqual(frame.GetFeature(j)))
                {
                    check++;
                    if (check == Features::GetFtrCount())
                    {
                        return false;
                    }

                }
            }
        }
        return true;
    }
};

#endif // !FTRCOMPAR_HPP