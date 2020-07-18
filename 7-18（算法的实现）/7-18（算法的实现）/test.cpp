#include<iostream>

using namespace std;

int main()
{
	//首先可以写出不是闰年的日期的总数
	int array[13] = {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year,month,day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month -1];
		sum += day;
		//这里判断是否位闰年，如果是，那么在总数上加1，反之不加
		if ((year % 4 == 0 && year % 100 == 0 ) || (year % 400 == 0))
		{
				sum += 1;
		}
		cout << sum << endl;
	}
	return 0;
}