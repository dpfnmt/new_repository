//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.reserve(n);
//	for (auto& str : v)
//		cin >> str;
//	bool sym = true, sym1 = true;
//	//���ȸ����ַ����ĳ��Ƚ��бȽ�
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (v[i - 1].size() >= v[i].size())
//			 sym  = false;
//		     break;
//	}
//	//����ASCII���бȽ�
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (v[i - 1] >= v[i])
//			sym1 = false;
//		      break;
//	}
//	if (sym && sym1)
//		cout << "both" << endl;
//	else if (!sym && sym1)
//		 cout << "lexicographically" << endl;
//	else if (sym && !sym1)
//		cout << "lengths" << endl;
//	else if (!sym && !sym1)
//		cout << "none" << endl;
//
//	return 0;
//}

//#include<iostream> 
//#include<vector> 
//#include<string> 
//
//using namespace std; 
//
//int main() 
//{
//	int n; 
//	cin>>n; 
//	vector<string> v; 
//	v.resize(n); 
//	for(auto& str : v) 
//		cin>>str; bool 
//		lenSym = true, lexSym = true; 
//	// ����Ҫע���i=1��ʼ������ǰ��Ƚϣ��Ƚϳ��� 
//	for(size_t i = 1; i < v.size(); ++i) 
//	{ 
//		if(v[i-1].size() >= v[i].size()) 
//		{
//			lenSym = false; 
//			break; 
//		}
//	}
//	//�Ƚ�ASCII�� 
//	for(size_t i = 1; i < v.size(); ++i) 
//	{ 
//		if(v[i-1] >= v[i]) 
//		{ 
//			lexSym = false; 
//			break; 
//		} 
//	}
//	if (lenSym&& lexSym)
//		cout << "both" << endl; 
//	else if (!lenSym && lexSym) 
//		cout << "lexicographically" << endl;
//	else if (lenSym && !lexSym) 
//		cout << "lengths" << endl; 
//	else if (!lenSym&&!lexSym) 
//		cout << "none" << endl; 
//
//	return 0; 
//}

#include<iostream>

using namespace std;

int gcb(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		//�����ߵĳ˻��������Լ��
		cout << a*b / gcb(a, b) << endl;
	}

	return 0;
}