#include<iostream>
#include<algorithm>

using  namespace std;


int Count(int n)
{
	int count = 0;
	if (n < 0 | n >= 500000)
		return -1;
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		int change = sqrt(i);
		for (int j = 2; j <= change; j++)
		{
			if (i%j == 0)
			{
				//�������������ͬ��ʱ��ֻ��Ҫ��һ���Ϳ�����
				if (i / j == j)
					sum += j;
				//�����ʾ����ͬ����ô��Ҫ����������
				else
					sum += j + (i / j);
			}
		}
		//��ʼ��ʱ����������2��ʼ�ģ����Ժ�Ҫ����1���ж��Ƿ����
		if (sum + 1 == i)
			count++;
	}
	cout << count << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
}
//int main()
//{
//	int n;
//	vector<int> v;
//	//int j = 0;
//	int a[2500];
//	while (cin >> n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			//���Ƚ�����ĳ������ҳ���
//			if (n % i == 0)
//
//				//a[i] = i;
//				//�ҳ���֮�󣬿��Խ�������ͬ��ȥ����
//			v.push_back(i);
//			vector<int>::iterator it = v.begin();
//			while (it != v.end())
//			{
//				cout << *it <<" ";
//				it++;
//			}
//			//cout << endl;
//			//cout << a[j] << endl;
//		}
//
//	}
//	return 0;
//}