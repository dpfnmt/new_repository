#include<iostream>

using namespace std;

int  SelectNum(int n)
{
	if (n < 0)
		return 0;
	int sum = 0;
	while (n > 1)
	{
		int n1 = n / 3;
		int n2 = n % 3;
		sum = sum + n1;
		n = n1 + n2;
		if (n == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << SelectNum(n) << endl;;
	}
	return 0;
}