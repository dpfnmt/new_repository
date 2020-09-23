//#include<math.h>
//#include<stdio.h>
//
//int main()
//{
//	int n;
//	double m, sum;
//	while (scanf("%lf%d", &m, &n))
//	{
//		for (sum = 0.0; n--; m = sqrt(m))
//			sum += m;
//		printf("%.2lf\n", sum);
//	}
//	return 0;
//}
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//
//#include<iostream>
//
//using namespace std;
//
//int SumAdd(int a, int b)
//{
//	if (a < b)
//		return 0;
//	else if (a == b)
//		return 1;
//	else if (b == 0)
//		return 1;
//	else
//		return SumAdd(a-1,b-1) + SumAdd(a - 1, b);
//}
//int main()
//{
//	int m, n;
//	int count = 0;
//	while (cin >> m >> n)
//	{
//		if (m <= 0 || m >= 100)
//		{
//			return 0;;
//		}
//		count = SumAdd(m, n);
//		cout << count << endl;
//	}
//	
//	return 0;
//}
#include<stdio.h>

int SumAdd(int a, int b)
{
	if (a < b)
		return 0;
	else if (a == b)
		return 1;
	else if (b == 0)
		return 1;
	else
		return SumAdd(a - 1, b - 1) + SumAdd(a - 1, b);
}
int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n))
	{
		if (m <= 0 || m >= 100)
		{
			return 0;;
		}
		int ret = SumAdd(m, n);
		printf("%d\n",ret);
	}

	return 0;
}
//int main()
//{
//	int n, m;
//	int count = 0;
//	int sum = 1;
//	int Add = 1;
//	while (cin >> m >> n)
//	{
//		int C = m - n;
//		for (int i = m; i > C; i--)
//		{
//			count = count * m;
//		}
//		for (int j = n; j > 0; j--)
//		{
//			sum = sum*n;
//		}
//		Add = count / sum;
//	}
//	 //Add = count / sum;
//	 cout << Add << endl;
//	return 0;
//}
//int main()
//{
//	int n, unit, ten, hund;
//	while (cin >> n)
//	{
//		if (n <= 100)
//		{
//			cout << "no" << endl;;
//		}
//		else
//		{
//			for (int i = 100; i < n; i++)
//			{
//				unit = i % 10;
//				ten = (i / 10) % 10;
//				hund = i / 100;
//				if (i == hund*hund*hund + ten*ten*ten + unit*unit*unit)
//					cout << i << " ";
//			}
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int m = 0, n = 0, count = 0;
//	while (cin >> m >> n)
//	{
//		for (int i = m; i <= n; i++)
//		{
//			int hund = i / 100;
//			int ten = (i - (hund*100))/10;
//			int one = i-hund*100-ten*10;
//			if (i == (hund*hund*hund + ten*ten*ten + one*one*one))
//			{
//				count++;
//				if (count == 1)
//					cout << i;
//				else if (count > 1)
//					cout << " " << i;
//				
//			}
//		}
//		if (count == 0)
//		{
//			cout << "no" << endl;;
//		}
//	}
//	return  0;
//}
//int main()
//{
//	double n, m;
//	cout.flags(ios::fixed);
//	cout.precision(2);
//	while (cin >> n >> m)
//	{
//		double sum = 0.0;
//		while (m > 0)
//		{
//			sum += n;
//			n = sqrt(n);
//			m -= 1;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}