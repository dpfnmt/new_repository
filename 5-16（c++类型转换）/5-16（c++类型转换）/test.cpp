#include<iostream>
#include<stdlib.h>
using namespace std;

//int main()
//{
//	int i = 1;
//	//��ʽ����ת����������ͣ�
//	double d = i;
//	printf("%d,%.2f\n", i, d);
//	int* p = &i;
//
//	//��ʾ���͵�ǿ��ת�������������
//	int assress = (int)p;
//	cout << assress << endl;
//}

int main()
{
	 volatile const int a = 3; 
	int*p = const_cast<int*>(&a);

	*p = 4;
	cout << a << endl;
	return 0;
}