//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int N, l=0, r=0,f, f0 = 0, f1 = 1;
//	cin >> N;
//	while (1)
//	{
//		f = f0 + f1;
//		f0 = f1;
//		f1 = f;
//		//Ѱ�ұ�fС����
//		if (f < N)
//			l = N - f;
//		else
//		{
//			//Ѱ�ұ�N���ֵ
//			r = f - N;
//			break;
//		}
//	}
//	cout << min(l, r)<<endl;
//	return 0;
//}