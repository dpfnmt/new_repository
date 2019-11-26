#include<iostream>
using namespace std;

//class Base {
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base::func2" << endl; 
//	}
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() 
//	{ 
//		cout << "Derive::func1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Derive::func3" << endl;
//	}
//	virtual void func4() 
//	{ 
//		cout << "Derive::func4" << endl;
//	}
//private:
//	int b;
//};

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
int main()
{
	Base1 b1;
	Base2 b2;
	Derive d;
	return 0;
}