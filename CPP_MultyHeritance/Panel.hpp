#pragma once 
#ifndef PANEL_HPP
#define PANEL_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

#include "Frame.hpp"

class Panel
{
public:
	Panel(int dif);

	Frame** GeneratePanel();
	void ClearPanel();
	void SeeFrames();
	void InspectFrame(int index);
	int GetFramesCount();
	Frame* GetFrame(int index);
private:
	int _frameCount;
	Frame** _panel;
	int _ftrsCount;
};

#endif // !PANEL_HPP