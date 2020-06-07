#include<iostream>
//#include<string>
#include<vector>
#include <algorithm>

using namespace std;


int main()
{
	//创建变量，和一个变量数组vector
	int n;
	vector<int> vi;
	while (cin >> n)
		//将输入的变量插入到数组中
		vi.push_back(n);
	//将这个数组进行排序
	sort(vi.begin(), vi.end());
	//多的数肯定比这个数组的一半长，那么输出这个下标的值，打印就好了
	cout << vi[vi.size() / 2 - 1] << endl;
	return 0;
}
//int main()
//{
//	//创建一个字符串str，数字长度cur，输出结果的变量ret
//	string str, cur, ret;
//	cin >> str;
//	    for (int i = 0; i <= str.length(); i++)
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//			{
//				cur += str[i];
//			}
//			else
//			{
//				//找出更长的字符串,更新之前的字符串
//				if (ret.size() < cur.size())
//				{
//					ret = cur;
//				}
//				//如果没有，那么将之前的清空
//				else
//				{
//					cur.clear();
//				}
//			}
//		}
//		cout << ret;
//	return 0;
//}