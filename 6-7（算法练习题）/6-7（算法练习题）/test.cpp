#include<iostream>
//#include<string>
#include<vector>
#include <algorithm>

using namespace std;


int main()
{
	//������������һ����������vector
	int n;
	vector<int> vi;
	while (cin >> n)
		//������ı������뵽������
		vi.push_back(n);
	//����������������
	sort(vi.begin(), vi.end());
	//������϶�����������һ�볤����ô�������±��ֵ����ӡ�ͺ���
	cout << vi[vi.size() / 2 - 1] << endl;
	return 0;
}
//int main()
//{
//	//����һ���ַ���str�����ֳ���cur���������ı���ret
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
//				//�ҳ��������ַ���,����֮ǰ���ַ���
//				if (ret.size() < cur.size())
//				{
//					ret = cur;
//				}
//				//���û�У���ô��֮ǰ�����
//				else
//				{
//					cur.clear();
//				}
//			}
//		}
//		cout << ret;
//	return 0;
//}