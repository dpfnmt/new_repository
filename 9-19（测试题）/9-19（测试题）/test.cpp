//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int l, m;
//	//首先创建一个二维数组
//	vector<vector<int>> vv;
//	while (cin >> l >> m)
//	{
//		int count = 0;
//		//判断区间不是空区间
//		if (m != 0)
//		{
//			for (int i = 0; i < m; i++)
//			{
//				//将几组的区间值输入进去
//				while (cin >> vv[i][2])
//				{
//					//求出每一组区间的的差值
//					int sum = vv[i][1] - vv[i][0];
//					//符值给count
//					count += sum;
//					//使sum为零，重复计算
//					sum = 0;
//				}
//			}
//		}
//		
//		//输出除去树的个数，使用总树减去除去树的个树
//		cout << l - count << endl;
//	}
//	return 0;
//}

//思路：把沿途目录名字记录在vector里，处理输入。具体如下：

//把vec_cur输入到path中，然后利用stringstream把input输入到path中，注意遇到…要回退
//输出注意如果path为空，则输出 /

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

int p;
string cur, input, tmp;
vector<string> path;
vector<string> vec_cur;

//进行处理文件
void deal_cur()
{
	tmp = cur;
	//在当前路径中把‘ / ’换成‘ ’
	for (size_t i = 0; i<cur.size(); ++i)
	if (tmp[i] == '/') 
		tmp[i] = ' ';
	//然后利用stringstream存到vector 的 vec_cur中
	stringstream ss(tmp);
	while (ss >> tmp)
		vec_cur.push_back(tmp);
}
//进行删除文件的过程
void deal_input()
{
	path.clear();
	size_t p;
	//把//换成/
	while ((p = input.find("//")) != string::npos)
		input.erase(p, 2);
	//把/./换成/，存到vector的input中
	while ((p = input.find("/./")) != string::npos)
		input.replace(p, 3, "/");
	//如果input[0]！ = ‘ / ’，说明是相对路径
	if (input[0] != '/') path = vec_cur;

	for (size_t i = 0; i<input.size(); ++i)
	if (input[i] == '/') input[i] = ' ';
	//把vec_cur输入到path中，然后利用stringstream把input输入到path中，注意遇到..要回退
	stringstream ss(input);
	while (ss >> tmp)
	{
		//cout<<"tmp:"<<tmp<<"\n";
		if (tmp == "..")
		{
			if (!path.empty()) path.pop_back();
		}
		else path.push_back(tmp);
	}
}
//进行打印
void print()
{
	if (!path.empty())
	{
		//如果path不为空，将/之后输入path的内容
		for (int i = 0; i<path.size(); ++i)
			cout << "/" << path[i];
	}
	//否则输出/
	else cout << "/";
	cout << "\n";
}

int main()
{
	//获取的字符串，
	cin.get();
    //进行处理
	deal_cur();
	getline(cin, input);
	deal_input();
	//打印
	print();
	return 0;
}