#include<iostream>
using namespace std;

//大小端的问题
//大端模式，是将高字节保存在低地址中，把低字节保存在高地址中，就像字符串的顺序在处理，地址由小到大，数据由高到低
//小端模式，将高存放到高，低存放到低中，这种将地址的高低和数据的权位有校的结合了起来
//int main()
//{
//	int i = 1;
//	char j = *(char*)&i;
//	if (j == 1)
//	{
//		printf("小端模式\n");
//	}
//	else
//		printf("大端模式\n");
//
//	return 0;
//}

//

​int GetBraceMatchCount(const string& str)
{
	stack<char> s;
	char c, b;
	int l = s.length();
	int count = 0;
	for (int i = 0; i < l; i++)
	{
		if (str[i] = '{')
		{
			s.push(str[i]);
		}
		else if (str[i] == '}')
		{
			if (s.empty())
				return 0;
			else if (c = s.top(), c == '{')
				s.pop();
			else
				count++;
		}
		return count;
	}
}