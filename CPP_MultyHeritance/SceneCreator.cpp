#include <string>
#include <iostream>
#include <ctime> 

#include "Comparison.hpp"
#include "Scene.hpp"
#include "SceneCreator.hpp"

int SceneCreator::_points = 0;
int SceneCreator::_dif = 0;
int SceneCreator::_loop = 0;

void SceneCreator::Start()
{
	do
	{
		SceneCreator::CreateGame();
	} while (_loop == 1);
}

void SceneCreator::CreateGame()
{
	_points = 0;
	int choise;
	std::cout << "Создать игру? \n"
		<< "0 - Нет \n"
		<< "Всё остально - Да \n"
		<< "Выбор: ";
	std::cin >> choise;
	if (choise == 0)
	{
		std::cout << "Ваши очки за все игры: " << _points;
	}
	else
	{
		std::cout << "Выберите действие\n"
			<< "0 - Почему руки 2?\n"
			<< "Всё остальное - Начать игру\n"
			<< "Выбор: ";
		std::cin >> choise;

		if (choise == 0)
		{
			std::cout << "Первая рука работает через индексы напрямую с хранилищем игрушек.\n"
				<< "То есть выбирая игрушку ты выбираешь её мысленно. \n"
				<< "(Оно существует потому что я сначала сделал так, а потом осознал, а удалять обидно)\n\n"
				<< "Вторая рука - это сама игрушка которую ты забираешь из хранилища и игрушки в нём больше нет. \n"
				<< "Если ты взял игрушку во вторую руку, то ты всё ещё можешь взять другую поменяв их местами.\n";
		}

		std::cout << "Выберите сложность (1-3): ";
		std::cin >> _dif;
		Features::SetFtrCount(_dif);

		std::cout << "Желаете изменить кол-во свойств? (Не больше 5) \n"
			<< "На вашей сложности их будет " << Features::GetFtrCount() << "\n"
			<< "0 - Да \n"
			<< "Всё остальное - Нет \n"
			<< "Выбор: ";
		std::cin >> choise;
		if (choise == 0)
		{
			std::cout << "На сколько: ";
			std::cin >> choise;

			Features::SetFtrCount(_dif + (choise), true);
		}
		Scene scene(_dif);

		_points += scene.GetPoints();
	}
}
