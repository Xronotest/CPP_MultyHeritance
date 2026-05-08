#include <string>
#include <iostream>
#include <ctime> 

#include "Comparison.hpp"
#include "Scene.hpp"
#include "Player.hpp"

Scene::Scene(int dif)
{
	_loop = 1;
	_shoise = 0;
	_dif = dif;
	_points = 0;
	Scene::Start();
}

void Scene::Start()
{
	std::cout << "Сложность: "<< _dif << "\n" 
		<< "Свойств: " << Features::GetFtrCount() << "\n" 
		<< "ИГРА НАЧАЛАСЬ!\n\n";

	Player player(_dif);
	Panel panel(_dif);

	do {

	_shoise = MoveList();
	if (_shoise == 1)
	{
		player.SeeToys();
	}
	else if (_shoise == 2)
	{
		panel.SeeFrames();
	}
	else if (_shoise == 3)
	{
		std::cout << "Какую (номер): ";
		std::cin >> _shoise;
		player.SetHand(_shoise - 1);
	}
	else if (_shoise == 4)
	{
		std::cout << "Какую (номер): ";
		std::cin >> _shoise;
		player.SetSecondHand(_shoise - 1);
	}
	else if (_shoise == 5)
	{
		player.InspectToy();
	}
	else if (_shoise == 6)
	{
		player.InspectSecondToy();
	}
	else if (_shoise == 7)
	{
		std::cout << "Какое (номер): ";
		std::cin >> _shoise;
		panel.InspectFrame(_shoise - 1);
	}
	else if (_shoise == 8)
	{
		std::cout << "Какое (номер): ";
		std::cin >> _shoise;
		_points += player.UseToy(panel.GetFrame(_shoise - 1));
	}
	else if (_shoise == 9)
	{
		std::cout << "Какое (номер): ";
		std::cin >> _shoise;
		_points += player.UseSecondToy(panel.GetFrame(_shoise - 1));
	}
	else if (_shoise == 0)
	{
		player.ClearPlayer();
		panel.ClearPanel();
		_loop = 0;

	}

	} while (_loop == 1);

}

int Scene::MoveList()
{
	int choise;
	std::cout << "Список действий \n"
		<< "1 - Посмотреть игрушки \n"
		<< "2 - Посмотреть отверстия \n"
		<< "3 - Взять игрушку в первую руку \n"
		<< "4 - Взять игрушку во вторую руку \n"
		<< "5 - Осмотреть игрушку в первой руке \n"
		<< "6 - Осмотреть игрушку во второй руке \n"
		<< "7 - Осмотреть отверстие \n"
		<< "8 - Вставить игрушку из первой руки в отверстие \n"
		<< "9 - Вставить игрушку из второй руки в отверстие \n"
		<< "0 - Конец игры \n"
		<< "Выбор: ";
	std::cin >> choise;
	return choise;
}

int Scene::GetPoints()
{
	return _points;
}
