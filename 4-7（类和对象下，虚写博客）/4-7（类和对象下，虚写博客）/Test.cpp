#include<iostream>
using namespace std;

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//public:
//	int _b;
//};
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//		cout << b._b << endl;
//		cout << n << endl;
//	}
//private:
//	int _a = 10;
//	B b = 20;
//	//int* p = (int*)malloc(sizeof(int)*4);
//	static int n;
//};
//
//int A::n = 30;
//
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 2019, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator << (ostream& _cout ,const Date& d)
{
	_cout <<d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

int main()
{
	Date d;
	cout << d <<endl;
	//d1 << cout; 
	return 0;
}