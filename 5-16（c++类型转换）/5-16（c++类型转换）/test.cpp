#include<iostream>
#include<stdlib.h>
using namespace std;

//int main()
//{
//	int i = 1;
//	//隐式类型转换，相关类型，
//	double d = i;
//	printf("%d,%.2f\n", i, d);
//	int* p = &i;
//
//	//显示类型的强制转换，不想管类型
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