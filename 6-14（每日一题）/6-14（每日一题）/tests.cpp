#include <iostream>
using namespace std;

class Person{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//#include <fstream>
//
//int main()
//{
//	//cout << sizeof(Derive) << endl;
//	//Derive d;
//	//PrintVTable((VFPTR*)(*(int*)&d));
//	//PrintVTable((VFPTR*)(*(int*)((char*)&d+sizeof(Base1))));
//
//	FILE* fout = fopen("test.txt", "r");
//	if (fout == nullptr)
//	{
//		cout << errno << endl;
//	}
//
//	ifstream ifs;
//	ifs.open("test.txt");
//
//	return 0;
//}
