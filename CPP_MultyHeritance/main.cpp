#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <windows.h>
#include <clocale>

#include "Player.hpp"
#include "SceneCreator.hpp"

//class UltimateBase
//{
//public:
//	UltimateBase() = default;
//	UltimateBase(const std::string& name):name_(name){}
//	std::string GetName()const { return name_; }
//	void SetName(const std::string& name) { name_ = name; }
//private:
//	std::string name_;
//};
//
//class Bar: virtual public UltimateBase
//{
//public:
//	Bar() = default;
//	Bar(int val):val1(val) {};
//	void Say() { std::cout << "Hellp"; }
//private:
//	int val1;
//};
//
//class BarDeriver :public Bar
//{
//	BarDeriver():Bar(){}
//	BarDeriver(int val1, int val2) :Bar(val1),val2(val2){}
//private:
//	int val2;
//};
//
//class Foo : virtual public UltimateBase
//{
//public:
//	Foo() = default;
//	Foo(int val) :val1(val){}
//	void Say() { std::cout << "World"; }
//private:
//	int val1;
//};
//
//class FooBar : public Bar, public Foo
//{
//public:
//	FooBar() :Bar(), Foo() {}
//	FooBar(int val1, int val2) :Bar(val1), Foo(val2) {}
//
//	void Say()
//	{
//		Bar::Say();
//		std::cout << ' ';
//		Foo::Say();
//	}
//
//private:
//	int val2;
//};
/*FooBar obj;
	obj.Say();*/

int Features::count_ = 0;

int main()
{
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(2151);
	setlocale(LC_ALL, "ru_RU.UTF-8");
	srand(time(nullptr));

	SceneCreator::Start();

	return 0;
}