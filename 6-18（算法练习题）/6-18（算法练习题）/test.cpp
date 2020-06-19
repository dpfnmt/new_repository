//#include<iostream>
//#include<string>
//using namespace std;
//
////判断回文
//bool IsCrival(const string& s)
//{
//	size_t begin = 0;
//	size_t end = s.size() - 1;
//	while (begin < end)
//	{
//		//如果开始和结尾不同，返回false
//		if (s[begin] != s[end])
//		return false;
//		//否则begin++，end--
//		begin++;
//		end--;
//	}
//	return true;
//}
//int main()
//{
//	//首先创建两个字符串str1,str2;
//	string str1, str2;
//	//输入两个字符串
//	getline(cin, str1);
//	getline(cin, str2);
//	size_t count = 0;
//	for (size_t i = 0; i <= str1.size();i++)
//	{
//		//将str2插入到str不同的位置
//		string str = str1;
//		str.insert(i, str2);
//		//判断是否回文
//		if (IsCrival(str))
//			count++;
//		
//	}
//	cout << count << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> vi(n);
//	
//	for (size_t i = 0; i < n; i++)
//		cin >> vi[i];
//
//	int result = vi[0];
//	int sum1 = 0, sum2 = 0;
//
//	for (int i = 0; i < vi.size(); i++)
//	{
//		sum2 = sum1 >= 0 ? sum1 + vi[i] : vi[i];
//		if (sum2 > result)
//			result = sum2;
//
//		if (sum2 < 0)
//			sum2 = 0;
//
//		sum1 = sum2;
//	}
//	cout << result << endl;
//	return 0;
//}

#include<iostream>
#include<vector>

using namespace std;

int main() 
{
	//首先，创建一个数组，将这些数字输入到数组里面
	int n; 
	cin >> n;
	vector<int> vi(n);
	for (size_t i = 0; i < n; ++i)
		cin >> vi[i];
	
	//创建一个结果 result，和两个总和，sum1,sum2
	int result = vi[0];
	int sum1 = 0, sum2 = 0; 
	
	for (int i = 0; i < vi.size(); i++)
	{ 
		// 计算到num[i]的子数组的最大和 
		sum2 = sum1 >= 0 ? sum1 + vi[i] : vi[i];
		//如果sum2比result大，更新结果
		if(sum2 > result) 
			result = sum2;
		//如果两者的和比0小，那么直接更新为0，便于下次计算
		if (sum2 < 0) 
			sum2 = 0; 
		//然后将sum2的值赋值给sum1
		sum1 = sum2;
	}
	cout << result << endl; 
	return 0;
}