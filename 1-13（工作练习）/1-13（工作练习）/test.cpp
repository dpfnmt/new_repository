#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
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
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		//printf(" 第%d个虚函数地址 :0X%x,->\n", i, vTable[i]);  //只使用这个不能看出是什么调用哪里？
		//VFPTR f = vTable[i];
		//f();
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	//Base1 b;
	//Derive d;

	//PrintVTable((VFPTR*)(*(int*)&d));

	//Base1* p = &d;
	//p->func1(); //调用派生类重写的；
	//p->func2();//调用基类的，派生类里面没有的；


	Derive d;

	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);

	//VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	//PrintVTable(vTableb2);
	return 0;
}

//如何实现由整形化成字符串   使用：itoa
//由字符串转化为整形， 使用: atoi.