#include<iostream>
using  namespace std;

//class Date
//{
//public:
//#include<iostream>
//	Date(int year, int month, int day)
//	:_year(year)
//	,	_month(month)
//	,_day(day)
//	{
//		
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2019,1,15);
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, const int i)
//		:_ref(a)
//		, _i(i)
//		, _aobj(10)
//	{}
//private:
//	int& _ref;
//	const int _i;
//	A _aobj;
//};

//class Time
//{
//public:
//	Time(int hous = 1)
//		:_hous(hous)
//	{
//		cout << _hous<< endl;
//	}
//private:
//	int _hous;
//};
//
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};

//class Array
//{
//public:
//	Array(int size)
//		//:_size(size)
//		//, _array((int*)malloc(sizeof(int)*_size))
//		:_array((int*)malloc(sizeof(int)*_size))
//		, _size(size)
//	{
//		
//		cout << _array << _size << endl;
//	}
//private:
//	int* _array;
//	int _size;
//};
//int main()
//{
//	Array a(1);
//	return 0;
//}

//class Date
//{
//public:
//	  Date(int year)
//		:_year(year)
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date d1(2018);
//	d1 = 2019;
//	return 0;
//}

class A
{
public:
	//A(int scout)
	//	:_scout(scout)  //这里不能使用这个，因为这不是A的非静态成员或基类；
	//{
	//	++_scout
	//}
	A()
	{
		++_scout;
	}
	A(const A& a)
	{
		++_scout;
	}
	static int Getcount()
	{
		return _scout;
	}
private:
	static int _scout;
};

int A::_scout = 0;
int main()
{
	cout << A::Getcount() << endl;
	A a1,a2,a4;
	A a3(a1);
	cout << A::Getcount() << endl;
	return 0;
}