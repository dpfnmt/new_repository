#include<iostream>

using namespace std;

int main()
{
	//���ȿ���д��������������ڵ�����
	int array[13] = {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year,month,day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month -1];
		sum += day;
		//�����ж��Ƿ�λ���꣬����ǣ���ô�������ϼ�1����֮����
		if ((year % 4 == 0 && year % 100 == 0 ) || (year % 400 == 0))
		{
				sum += 1;
		}
		cout << sum << endl;
	}
	return 0;
}