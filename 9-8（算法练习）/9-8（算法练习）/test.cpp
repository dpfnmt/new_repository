#include<iostream>

using namespace std;

int  SelectNum(int n)
{
	if (n < 0)
		return 0;
	int sum = 0;
	while (n > 1)
	{
		//�ȹ��ռ�֮���ƿ��
		int n1 = n / 3;
		//ʣ���ƿ��
		int n2 = n % 3;
		//�ܹ��ܺ�ƿ��
		sum = sum + n1;
		//���ܶһ���ƿ��
		n = n1 + n2;
		//�����ʣ����������ô���������ڼ�1
		if (n == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << SelectNum(n) << endl;;
	}
	return 0;
}