#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

#include "Toys.hpp"
#include "Player.hpp"
#include "Comparison.hpp"
#include "FullCompar.hpp"

Player::Player(int dif)
{	

	Player::_ftrsCount = Features::GetFtrCount();
	Player::_toysCount = (dif * 3) + 2;
	Player::_gamer = Player::GeneratePlayer();
	Player::_hand = -1;
	Player::_secondHand = nullptr;
}

//Player::~Player()
//{
//	ClearPlayer();
//}

Toys** Player::GeneratePlayer()
{
	std::string name;
	_gamer = new Toys * [_toysCount];

	for (int i = 0; i < _toysCount; ++i)
	{
		name = "Игрушка " + std::to_string(i + 1);
		_gamer[i] = new Toys(Toys::GetToy(rand() % 5, name, _ftrsCount));
	}
	return _gamer;
}

void Player::ClearPlayer()
{
	for (int i = 0; i < _toysCount; ++i)
	{
		_gamer[i]->CleareFtr();
		delete _gamer[i];
		_gamer[i] = nullptr;
	}

	delete[] _gamer;
	_gamer = nullptr;

	delete _secondHand;
	_secondHand = nullptr;

	_toysCount = 0;
	_hand = -1;
}

int Player::UseToy(Frame * frame, int dif)
{
	if (_hand < _toysCount && _hand >= 0 && _gamer[_hand] != nullptr && frame != nullptr)
	{
		FullCompar fullCompar;
		Comparison comparison(&fullCompar);
		if (comparison.IsFit(*_gamer[_hand], *frame))
		{
			std::cout << "Вы использовали " << _gamer[_hand]->GetName() << "\n";
			_gamer[_hand]->CleareFtr();
			delete _gamer[_hand];
		
			for (int i = _hand; i < _toysCount; ++i)
			{
				if (i + 1 < _toysCount)
				{
					_gamer[i] = _gamer[i + 1];
				}
			}
			_toysCount--;
			_gamer[_toysCount] = nullptr;
			_hand = -1;
			return 100 * dif;
		}
		else
		{
			std::cout << "Игрушка не подходит \n";
			return 0;
		}

	}
	else
	{
		std::cout << "В вашей руке пусто \n";
		return 0;
	}
}

int Player::UseSecondToy(Frame* frame, int dif)
{
	if (_secondHand != nullptr && frame != nullptr)
	{
		FullCompar fullCompar;
		Comparison comparison(&fullCompar);
		if (comparison.IsFit(*_secondHand, *frame))
		{
			std::cout << "Вы использовали " << _secondHand->GetName() << "\n";

			_secondHand->CleareFtr();
			delete _secondHand;
			_secondHand = nullptr;
			return 100 * dif;
		}
		else
		{
			std::cout << "Игрушка не подходит \n";
			return 0;
		}
	}
	else
	{
		std::cout << "В вашей второй руке пусто \n";
		return 0;
	}
}

void Player::SeeToys()
{
	if (_toysCount != 0)
	{
		std::string status;

		for (int i = 0; i < _toysCount; ++i )
		{
			if (_hand == i)
			{
				status = " (В руках)";
			}
			else
			{
				status = " ";
			}
			if (_gamer[i] != nullptr)
			{
				std::cout << i + 1 << " - " << _gamer[i]->GetName() << status << "\n";

			}
		}
		if (_secondHand != nullptr)
		{
			std::cout << "В вашей второй руке " << _secondHand->GetName() << "\n";
		}
	}
	else
	{
		std::cout << "У вас ничего нет \n";
	}

}

void Player::InspectToy()
{
	if (_hand < _toysCount && _hand >= 0 && _gamer[_hand] != nullptr)
	{
		std::cout << "Свойства: \n"
			<< "Форма: " << _gamer[_hand]->GetForm().GetName() << "\n";
		if (_ftrsCount > 0)
		{
			for (size_t i = 0; i < _ftrsCount; i++)
			{
				std::cout << "Свойство " << i + 1 << ": " << _gamer[_hand]->GetFeature(i).GetName() << "\n";
			}
		}
	}
	else
	{
		std::cout << "В вашей руке пусто\n";
	}

}

void Player::InspectSecondToy()
{
	if (_secondHand != nullptr)
	{
		std::cout << "Свойства: \n"
			<< "Форма: " << _secondHand->GetForm().GetName() << "\n";
		if (_ftrsCount > 0)
		{
			for (size_t i = 0; i < _ftrsCount; i++)
			{
				std::cout << "Свойство " << i + 1 << ": " << _secondHand->GetFeature(i).GetName() << "\n";
			}
		}
	}
	else
	{
		std::cout << "В вашей руке пусто\n";
	}

}

void Player::SetHand(int index)
{
	if (index < _toysCount && index >= 0)
	{
		_hand = index;
	}
	else
	{
		std::cout << "Тут ничего нет";
	}

}

Toys* Player::GetHand()const
{
	return _gamer[_hand];
}

void Player::SeeHand()
{
	if (_hand < _toysCount && _hand >= 0 && _gamer[_hand] != nullptr)
	{
		std::cout << "В вашей руке сейчас " << _gamer[_hand]->GetName() << "\n";
	}
	else
	{
		std::cout << "В вашей руке пусто\n";
	}

}

void Player::SetSecondHand(int index)
{
	if (index < _toysCount && index >= 0 && _gamer[index] != nullptr)
	{
		if (_secondHand == nullptr)
		{
			_secondHand = _gamer[index];
			std::cout << "Вы взяли " << _secondHand->GetName() << "\n";

			for (int i = index; i < _toysCount; ++i)
			{
				if (i + 1 < _toysCount)
				{
					_gamer[i] = _gamer[i + 1];
				}
			}
			_toysCount--;
			_gamer[_toysCount] = nullptr;
		}
		else
		{
			Toys* temp;
			std::cout << "Вы положили " << _secondHand->GetName() << "\n";
			temp = _secondHand;
			_secondHand = _gamer[index];
			std::cout << "Вы взяли " << _secondHand->GetName() << "\n";
			_gamer[index] = temp;
			temp = nullptr;
		}
	}
	else
	{
		std::cout << "Тут ничего нет \n";
	}
}

Toys* Player::GetSecondHand()const
{
	return _secondHand;
}

void Player::SeeSecondHand()
{
	if (_secondHand != nullptr)
	{
		std::cout << "В вашей второй руке " << _secondHand->GetName() << "\n";
	}
	else
	{
		std::cout << "В вашей второй руке пусто \n";
	}
}

int Player::GetToysCount()
{
	return _toysCount;
}
