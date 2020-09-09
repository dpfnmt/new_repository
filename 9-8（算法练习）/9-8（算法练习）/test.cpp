#include<iostream>

using namespace std;

int  SelectNum(int n)
{
	if (n < 0)
		return 0;
	int sum = 0;
	while (n > 1)
	{
		//喝过收集之后的瓶盖
		int n1 = n / 3;
		//剩余的瓶盖
		int n2 = n % 3;
		//总共能喝瓶数
		sum = sum + n1;
		//还能兑换的瓶盖
		n = n1 + n2;
		//如果还剩下两个，那么在总数上在加1
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