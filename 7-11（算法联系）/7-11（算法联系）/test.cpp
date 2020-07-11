#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		//创建一个加数变量，和一个更新后的变数变量
		int count = 0, maxcount = 0;
		while (n)
		{
			//把数编程二进制的数
			if (n & 1)
			{
				++count;
				maxcount = max(count, maxcount);
			}
			else
			{
				//当1不是连续的时候，重新计算
				count = 0;
			}
			//将现在值进行右移，重新计算1的个数
			n = n >> 1;
		}
		cout << maxcount << endl;

	}
	return 0;
}