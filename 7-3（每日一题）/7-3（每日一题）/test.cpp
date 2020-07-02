#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (c + b > a) && (a + c > b))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

	}
	return 0;
}

//int main()
//{
//	double a, r;
//	while (cin >> a >> r)
//	{
//		double c = 6.48 * r;
//		if (a <= c)
//		{
//			cout << "Yes" << endl;
//		}
//		else
//		{
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}

// 牛客网的——青蛙跳台阶的问题

//第一种方法
///* int jumpFloor  =1;
//while(--number)
//{
//jumpFloor *= 2;
//}
//return jumpFloor;
//*/

//第二种方法
//return 1 << (number - 1);
