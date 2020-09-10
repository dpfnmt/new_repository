#include<stdio.h>
#include<iostream>
using  namespace std;

//int main()
//{
//	//volatile const int  a = 7;
//	 const int  a = 7;
//	 //int  *p = (int*)&a;
//	 int  *p = (int*)&a;
//	*p = 8;
//	cout << a;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 8;
//	int* const p = &a;
//	*p = 9; // 正确
//	int  b = 7;
//	p = &b; // 错误
//	return 0;
//}


//int main()
//{
//	int a = 7;
//	const int * const b = &a;
//	cout << b << endl;
//	return 0;
//}

//void Cpf(int *const a)
//{
//	cout << *a << " ";
//	*a = 9;
//}
//
//int main(void)
//{
//	int a = 8;
//	Cpf(&a);
//	cout << a; // a 为 9
//	system("pause");
//	return 0;
//}

//class Myclass{
//public:
//	Myclass(int a, int b, int c);
//	void GetNumber();
//	void GetSum();
//private:
//	int A, B, C;
//	static int Sum;
//};
//
//int Myclass::Sum = 0;
//
//Myclass::Myclass(int a, int b, int c)
//{
//	A = a;
//	B = b;
//	C = c;
//	Sum += A + B + C;
//}
//
//void Myclass::GetNumber()
//{
//	cout << "Number=" << A << "," << B << "," << C << endl;
//}
//
//void Myclass::GetSum()
//{
//	cout << "Sum=" << Sum << endl;
//}
//
//void main(){
//	Myclass M(3, 7, 10), N(14, 9, 11);
//	M.GetNumber();
//	N.GetNumber();
//	M.GetSum();
//	N.GetSum();
//}

//int main()
//{
//	int a = 2;
//	int *b = &a;
//	//free(b);
//	printf("%p", &b);
//
//	return 0;
//}

//void test()
//{
//	int *p = (int *)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//	free(p);
//
//}
//int main()
//{
//	test();
//	while (1);//程序直接就崩溃了呢
//	
//}

#include<string.h>
#include<stdlib.h>

void GetMemory2(char **p, int num)
{
	*p = (char *)malloc(num);
}
int main()
{
	char *str = NULL;
	GetMemory2(&str, 100);
	strcpy(str, "hello");
	printf(str);

	return 0;
}