#include<iostream>
using namespace std;

class A{};
class B : public A {};
class Person {
public:
	virtual A* f()
	{
		return new A;
	}
};
class Student : public Person {
public:
	virtual B* f()
	{
		return new B;

	}
};

void func(Person& ps)
{
	ps.f();
}
int main()
{
	Person p;
	func(p);

	Student s;
	func(s);
}
