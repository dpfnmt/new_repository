//#include<iostream>
//#include<string>
//using namespace std;
//
////�жϻ���
//bool IsCrival(const string& s)
//{
//	size_t begin = 0;
//	size_t end = s.size() - 1;
//	while (begin < end)
//	{
//		//�����ʼ�ͽ�β��ͬ������false
//		if (s[begin] != s[end])
//		return false;
//		//����begin++��end--
//		begin++;
//		end--;
//	}
//	return true;
//}
//int main()
//{
//	//���ȴ��������ַ���str1,str2;
//	string str1, str2;
//	//���������ַ���
//	getline(cin, str1);
//	getline(cin, str2);
//	size_t count = 0;
//	for (size_t i = 0; i <= str1.size();i++)
//	{
//		//��str2���뵽str��ͬ��λ��
//		string str = str1;
//		str.insert(i, str2);
//		//�ж��Ƿ����
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
	//���ȣ�����һ�����飬����Щ�������뵽��������
	int n; 
	cin >> n;
	vector<int> vi(n);
	for (size_t i = 0; i < n; ++i)
		cin >> vi[i];
	
	//����һ����� result���������ܺͣ�sum1,sum2
	int result = vi[0];
	int sum1 = 0, sum2 = 0; 
	
	for (int i = 0; i < vi.size(); i++)
	{ 
		// ���㵽num[i]������������� 
		sum2 = sum1 >= 0 ? sum1 + vi[i] : vi[i];
		//���sum2��result�󣬸��½��
		if(sum2 > result) 
			result = sum2;
		//������ߵĺͱ�0С����ôֱ�Ӹ���Ϊ0�������´μ���
		if (sum2 < 0) 
			sum2 = 0; 
		//Ȼ��sum2��ֵ��ֵ��sum1
		sum1 = sum2;
	}
	cout << result << endl; 
	return 0;
}