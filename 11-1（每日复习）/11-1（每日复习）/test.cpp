#include<iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return 29;
		else
			return monthArray[month];
	}

	// 四个成员函数
	Date(int year = 2019, int month = 1, int day = 31)
	{
		if (year > 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}

	}

	bool operator==(const Date& d)
	{
		return  _year == d._year
			&&  _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return  _year != d._year
			|| _month != d._month
			|| _day != d._day;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return  true;
		}
		if (_year < d._year)
		{
			return false;
		}
		if (_month > d._month)
		{
			return  true;
		}
		if (_month  < d._month)
		{
			return false;
		}
		if (_day > d._day)
		{
			return  true;
		}
		if (_day <= d._day)
		{
			return false;
		}
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return  true;
		}
		if (_year > d._year)
		{
			return false;
		}
		if (_month < d._month)
		{
			return  true;
		}
		if (_month  > d._month)
		{
			return false;
		}
		if (_day < d._day)
		{
			return  true;
		}
		if (_day >= d._day)
		{
			return false;
		}
	}
	bool operator>=(const Date& d)
	{
		if (_year > d._year)
		{
			return  true;
		}
		if (_year < d._year)
		{
			return false;
		}
		if (_month > d._month)
		{
			return  true;
		}
		if (_month  < d._month)
		{
			return false;
		}
		if (_day > d._day)
		{
			return  true;
		}
		if (_day < d._day)
		{
			return false;
		}
		else
			return  true;
	}

	bool operator<=(const Date& d)
	{
		if (_year < d._year)
		{
			return  true;
		}
		if (_year > d._year)
		{
			return false;
		}
		if (_month < d._month)
		{
			return  true;
		}
		if (_month  > d._month)
		{
			return false;
		}
		if (_day < d._day)
		{
			return  true;
		}
		if (_day > d._day)
		{
			return false;
		}
		else
			return true;
	}


	//d1 + 10
	Date operator+(int day)
	{
		Date fur((*this));
		fur._day += day;
		while (fur._day > GetMonthDay(fur._year, fur._month))
		{
			if (fur._month != 12)
			{
				fur._day = fur._day - GetMonthDay(fur._year, fur._month);
				fur._month++;
			}
			else
			{
				fur._day = fur._day - GetMonthDay(fur._year, 12);
				fur._year++;
				fur._month = 1;
			}
		}
		return fur;
	}
	Date operator+=(int day)
	{
		_day += day;
		while (_day>GetMonthDay(_year, _month))
		{
			if (_month != 12)
			{
				_day = _day - GetMonthDay(_year, _month);
				_month++;
			}
			else
			{
				_day = _day - GetMonthDay(_year, 12);
				_year++;
				_month = 1;
			}
			return (*this);
		}
	}
	Date operator-(int day)
	{
		Date fur((*this));
		fur._day -= day;

		while (fur._day <= 0)
		{

			if (fur._month == 1)
			{
				fur._day = fur._day + GetMonthDay(fur._year, 12);
				fur._month = 12;
				fur._year--;
			}
			else
			{
				fur._month -= 1;
				fur._day = fur._day + GetMonthDay(fur._year, fur._month);
			}
		}
		return fur;
	}
	Date operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{

			if (_month == 1)
			{
				_day = _day + GetMonthDay(_year, 12);
				_month = 12;
				_year--;
			}
			else
			{
				_month -= 1;
				_day = _day + GetMonthDay(_year, _month);
			}
		}
		return (*this);
	}
	//// 前置
	Date& operator++()
	{
		(*this) += 1;
		return (*this);
	}
	Date operator--()
	{
		(*this) -= 1;
		return (*this);
	}

	////// 后置
	Date operator++(int)
	{
		Date copy(*this);
		(*this) += 1;
		return copy;
	}
	Date operator--(int)
	{
		Date copy(*this);
		(*this) -= 1;
		return copy;
	}

	//// d1-d2
	int operator-(const Date& d)
	{
		int count = 0;
		Date copy(*this);
		if (copy<d)
		{
			while (copy != d)
			{

				copy++;
				count--;
			}
			return count;

		}
		if (copy == d)
		{
			return 0;
		}
		if (copy>d)
		{
			while (copy != d)
			{
				copy--;
				count++;
			}
			return count;

		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	/*Date d1(2019, 1 ,30);
	d1.Print();*/
	Date d;
	d.Print();
	Date d1(2018, 1, 25);
	d1.Print();
	(d1 + 8).Print();
	//d++;
	//d = (d-31);
	//d.Print();
	//d.operator -= (1);
	//--d;
	/* d.Print();*/

	//cout<<(d1 <= d)<<endl;

	return 0;
}