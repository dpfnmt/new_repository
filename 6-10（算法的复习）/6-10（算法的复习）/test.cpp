#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//在字符和数组中寻找数字的最长排序
//
//int main()
//{
//	string str, cur, ret;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			cur += str[i];
//		}
//		else
//		{
//			if (ret.size() < cur.size())
//			{
//				ret = cur;
//			}
//			else
//			{
//				cur.clear();
//			}
//		}
//	}
//	cout << ret;
//	return 0;
//}

//在一堆数字里面找到大于2/1的数字
//#include<algorithm>
//int main()
//{
//	int n;
//	vector<int> vi;
//	while(cin >> n)
//		vi.push_back(i);
//	sort(vi.begin(), vi.end());
//	cout << vi[vi.size() / 2 - 1] << endl;
//	return 0;
//}

//计算糖果的问题
//输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。

//int main()
//{
//	//首先创建四个变量将这几个数表示出来
//	int A = 0, B = 0, B1 = 0, B2 = 0, C = 0, a, b, c, d;
//	a = A - B;
//	b = B - C;
//	c = A + B;
//	d = B + C;
//	//给这四个变量进行输值；
//	cin >> a >> b >> c >> d;
//	if (-30 <= a <= 30 && -30 <= b <= 30 && -30 <= c <= 30 && -30 <= a <= 30)
//	{
//		//这里有个细节，就是B1，B2，因为A，C算出来就算有一个解，但是B不止一个，所以判断一下，B才能正确
//		A = (a + c) / 2;
//		C = (d - b) / 2;
//		B1 = (c - a) / 2;
//		B2 = (b + d) / 2;
//		if (B1 != B2)
//		{
//			cout << "No" << endl;
//		}
//		cout << A << " " << B1 << " " << C;
//	}
//	return 0;
//}

//进制转化

int main()
{
	//首先，创建两个字符串，一个保留进位制，一个为最高16进制的位数0-F
	string str, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool falg = false;
	//当m为负数时，先将他变成正数
	if (m < 0)
	{
		m = 0 - m;
		falg = true;
	}
	//将m的数值通过模取余数的方法放到str字符串中
	while (m)
	{
		str += table[m%n];
		//再通过除法，取出商，然后循环
		m /= n;
	}
	if (falg)
		str += '-';
	//因为这里算出来的是正序的，但是我们需要的是反序的数字串，在通过反序的方法进行打印
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}