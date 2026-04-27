#include <iostream>
#include <string>

#include "Frame.hpp"

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


int main()
{
	setlocale(LC_ALL, "RUS");
	Form squareForm(Form::Shapes::square);
	Form triangleForm(Form::Shapes::triangle);
	Form circleForm(Form::Shapes::circle);
	Form starForm(Form::Shapes::star);

	Toys cubik(squareForm);
	Toys cube(squareForm);
	Toys circle(circleForm);
	Toys star(starForm);

	Frames squar(squareForm);
	Frames str(starForm);

	std::cout << cubik.IsSame(cube) << "\n";
	std::cout << cubik.IsSame(cube) << "\n";
	std::cout << cubik.IsSame(star) << "\n";
	std::cout << str.IsFit(star) << "\n";
	std::cout << str.IsFit(cube) << "\n";
	

	return 0;
}