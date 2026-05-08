#pragma once 
#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <iostream>
#include <ctime> 

#include "Comparison.hpp"

class Scene
{
public:

	Scene(int dif);
	void Start();

	int MoveList();

	int GetPoints();

private:
	int _points;
	int _loop;
	int _shoise;
	int _dif;

};

#endif // !SCENE_HPP

