#include<iostream>
#include<algorithm>

using  namespace std;


int Count(int n)
{
	int count = 0;
	if (n < 0 | n >= 500000)
		return -1;
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		int change = sqrt(i);
		for (int j = 2; j <= change; j++)
		{
			if (i%j == 0)
			{
				//如果除数和商相同的时候，只需要加一个就可以了
				if (i / j == j)
					sum += j;
				//否则表示不相同，那么需要两个都加上
				else
					sum += j + (i / j);
			}
		}
		//开始的时候，我们是由2开始的，所以和要加上1，判断是否相等
		if (sum + 1 == i)
			count++;
	}
	cout << count << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
}
//int main()
//{
//	int n;
//	vector<int> v;
//	//int j = 0;
//	int a[2500];
//	while (cin >> n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			//首先将里面的除数都找出来
//			if (n % i == 0)
//
//				//a[i] = i;
//				//找出来之后，可以将他们相同的去掉。
//			v.push_back(i);
//			vector<int>::iterator it = v.begin();
//			while (it != v.end())
//			{
//				cout << *it <<" ";
//				it++;
//			}
//			//cout << endl;
//			//cout << a[j] << endl;
//		}
//
//	}
//	return 0;
//}