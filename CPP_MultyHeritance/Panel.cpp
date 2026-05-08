#include <iostream>
#include <string>
#include <cstdlib> 

#include "Frame.hpp"
#include "Panel.hpp"


Panel::Panel(int dif)
{
	_ftrsCount = Features::GetFtrCount();
	_frameCount = 5;
	_panel = Panel::GeneratePanel();
}


Frame** Panel::GeneratePanel()
{
	std::string name;
	_panel = new Frame * [_frameCount];

	for (int i = 0; i < _frameCount; ++i)
	{
		name = "Отверстие " + std::to_string(i + 1);
		_panel[i] = new Frame(Frame::GetFrame(rand() % 5, name, _ftrsCount));
	}
	return _panel;
}

void Panel::ClearPanel()
{
	for (int i = 0; i < _frameCount; ++i)
	{
		_panel[i]->CleareFtr();
		delete _panel[i];
		_panel[i] = nullptr;
	}

	delete[] _panel;
	_panel = nullptr;
}

void Panel::SeeFrames()
{
	if (_frameCount != 0)
	{
		for (int i = 0; i < _frameCount; ++i)
		{
			if (_panel[i] != nullptr)
			{
				std::cout << i + 1 << " - " << _panel[i]->GetName() << "\n";

			}
		}
	}
}

void Panel::InspectFrame(int index)
{
	if (index < _frameCount && index >= 0 && _panel[index] != nullptr)
	{
		std::cout << "Свойства: \n"
			<< "Форма: " << _panel[index]->GetForm().GetName() << "\n";
		if (_ftrsCount > 0)
		{
			for (size_t i = 0; i < _ftrsCount; i++)
			{
				std::cout << "Свойство " << i + 1 << ": " << _panel[index]->GetFeature(i).GetName() << "\n";
			}
		}
	}
	else
	{
		std::cout << "В вашей руке пусто\n";
	}

}

int Panel::GetFramesCount()
{
	return _frameCount;
}

Frame* Panel::GetFrame(int index)
{
	return _panel[index];
}