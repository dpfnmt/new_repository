#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//���ַ���������Ѱ�����ֵ������
//
//int main()
//{
//	string str, cur, ret;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			cur += str[i];
//		}
//		else
//		{
//			if (ret.size() < cur.size())
//			{
//				ret = cur;
//			}
//			else
//			{
//				cur.clear();
//			}
//		}
//	}
//	cout << ret;
//	return 0;
//}

//��һ�����������ҵ�����2/1������
//#include<algorithm>
//int main()
//{
//	int n;
//	vector<int> vi;
//	while(cin >> n)
//		vi.push_back(i);
//	sort(vi.begin(), vi.end());
//	cout << vi[vi.size() / 2 - 1] << endl;
//	return 0;
//}

//�����ǹ�������
//����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��

//int main()
//{
//	//���ȴ����ĸ��������⼸������ʾ����
//	int A = 0, B = 0, B1 = 0, B2 = 0, C = 0, a, b, c, d;
//	a = A - B;
//	b = B - C;
//	c = A + B;
//	d = B + C;
//	//�����ĸ�����������ֵ��
//	cin >> a >> b >> c >> d;
//	if (-30 <= a <= 30 && -30 <= b <= 30 && -30 <= c <= 30 && -30 <= a <= 30)
//	{
//		//�����и�ϸ�ڣ�����B1��B2����ΪA��C�����������һ���⣬����B��ֹһ���������ж�һ�£�B������ȷ
//		A = (a + c) / 2;
//		C = (d - b) / 2;
//		B1 = (c - a) / 2;
//		B2 = (b + d) / 2;
//		if (B1 != B2)
//		{
//			cout << "No" << endl;
//		}
//		cout << A << " " << B1 << " " << C;
//	}
//	return 0;
//}

//����ת��

int main()
{
	//���ȣ����������ַ�����һ��������λ�ƣ�һ��Ϊ���16���Ƶ�λ��0-F
	string str, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool falg = false;
	//��mΪ����ʱ���Ƚ����������
	if (m < 0)
	{
		m = 0 - m;
		falg = true;
	}
	//��m����ֵͨ��ģȡ�����ķ����ŵ�str�ַ�����
	while (m)
	{
		str += table[m%n];
		//��ͨ��������ȡ���̣�Ȼ��ѭ��
		m /= n;
	}
	if (falg)
		str += '-';
	//��Ϊ�����������������ģ�����������Ҫ���Ƿ�������ִ�����ͨ������ķ������д�ӡ
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}