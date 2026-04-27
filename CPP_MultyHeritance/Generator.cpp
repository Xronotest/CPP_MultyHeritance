#include <iostream>
#include <string>

#include "Frame.hpp"
Form squareForm(Form::Shapes::square);
Form triangleForm(Form::Shapes::triangle);
Form circleForm(Form::Shapes::circle);
Form starForm(Form::Shapes::star);
Form hexagonForm(Form::Shapes::hexagon);

class Generator
{
public:
	void Generate(int dif)
	{
		Form arrForm[]
		{
		squareForm,
		triangleForm,
		circleForm,
		starForm,
		hexagonForm
		};

		for (int i = 0; i < dif; i++)
		{

		}
	}
};