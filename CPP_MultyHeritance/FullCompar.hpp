#pragma once 
#ifndef FULLCOMPAR_HPP
#define FULLCOMPAR_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparator.hpp"

class FullCompar : public Comparator
{
public:
    bool IsCompar(const Toys& toy, const Frame& frame) const override
    {
        if (!toy.GetForm().IsEqual(frame.GetForm()))
        {
            return false;
        }

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

#endif // !FULLCOMPAR_HPP