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
		//����һ��������������һ�����º�ı�������
		int count = 0, maxcount = 0;
		while (n)
		{
			//������̶����Ƶ���
			if (n & 1)
			{
				++count;
				maxcount = max(count, maxcount);
			}
			else
			{
				//��1����������ʱ�����¼���
				count = 0;
			}
			//������ֵ�������ƣ����¼���1�ĸ���
			n = n >> 1;
		}
		cout << maxcount << endl;

	}
	return 0;
}