#pragma once 
#ifndef SCENECREATOR_HPP
#define SCENECREATOR_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparison.hpp"
#include "Scene.hpp"

class SceneCreator
{
public:
	static void Start();
	static void CreateGame();

private:
	static int _points;
	static int _dif;
	static int _loop;
};

#endif // !SCENECREATOR_HPP

