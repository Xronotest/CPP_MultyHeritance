#pragma once 
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

#include "Toys.hpp"
#include "Panel.hpp"

class Player
{
public:
    Player(int dif);
    //~Player();

    Toys** GeneratePlayer();
    void ClearPlayer();

    int UseToy(Frame* frame, int dif);
    int UseSecondToy(Frame* frame, int dif);

    void SeeToys();
    void InspectToy();
    void InspectSecondToy();

    void SetHand(int index);
    Toys* GetHand() const;
    void SeeHand();

    void SetSecondHand(int index);
    Toys* GetSecondHand() const;
    void SeeSecondHand();

    int GetToysCount();

private:
    int _toysCount;
    Toys** _gamer;
    int _hand;
    Toys* _secondHand;
    int _ftrsCount;
};

#endif // !PLAYER_HPP