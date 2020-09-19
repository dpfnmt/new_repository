//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int l, m;
//	//���ȴ���һ����ά����
//	vector<vector<int>> vv;
//	while (cin >> l >> m)
//	{
//		int count = 0;
//		//�ж����䲻�ǿ�����
//		if (m != 0)
//		{
//			for (int i = 0; i < m; i++)
//			{
//				//�����������ֵ�����ȥ
//				while (cin >> vv[i][2])
//				{
//					//���ÿһ������ĵĲ�ֵ
//					int sum = vv[i][1] - vv[i][0];
//					//��ֵ��count
//					count += sum;
//					//ʹsumΪ�㣬�ظ�����
//					sum = 0;
//				}
//			}
//		}
//		
//		//�����ȥ���ĸ�����ʹ��������ȥ��ȥ���ĸ���
//		cout << l - count << endl;
//	}
//	return 0;
//}

//˼·������;Ŀ¼���ּ�¼��vector��������롣�������£�

//��vec_cur���뵽path�У�Ȼ������stringstream��input���뵽path�У�ע��������Ҫ����
//���ע�����pathΪ�գ������ /

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

int p;
string cur, input, tmp;
vector<string> path;
vector<string> vec_cur;

//���д����ļ�
void deal_cur()
{
	tmp = cur;
	//�ڵ�ǰ·���аѡ� / �����ɡ� ��
	for (size_t i = 0; i<cur.size(); ++i)
	if (tmp[i] == '/') 
		tmp[i] = ' ';
	//Ȼ������stringstream�浽vector �� vec_cur��
	stringstream ss(tmp);
	while (ss >> tmp)
		vec_cur.push_back(tmp);
}
//����ɾ���ļ��Ĺ���
void deal_input()
{
	path.clear();
	size_t p;
	//��//����/
	while ((p = input.find("//")) != string::npos)
		input.erase(p, 2);
	//��/./����/���浽vector��input��
	while ((p = input.find("/./")) != string::npos)
		input.replace(p, 3, "/");
	//���input[0]�� = �� / ����˵�������·��
	if (input[0] != '/') path = vec_cur;

	for (size_t i = 0; i<input.size(); ++i)
	if (input[i] == '/') input[i] = ' ';
	//��vec_cur���뵽path�У�Ȼ������stringstream��input���뵽path�У�ע������..Ҫ����
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
//���д�ӡ
void print()
{
	if (!path.empty())
	{
		//���path��Ϊ�գ���/֮������path������
		for (int i = 0; i<path.size(); ++i)
			cout << "/" << path[i];
	}
	//�������/
	else cout << "/";
	cout << "\n";
}

int main()
{
	//��ȡ���ַ�����
	cin.get();
    //���д���
	deal_cur();
	getline(cin, input);
	deal_input();
	//��ӡ
	print();
	return 0;
}