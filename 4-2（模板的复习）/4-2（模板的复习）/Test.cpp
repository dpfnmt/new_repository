#include<iostream>
using namespace std;

//
//void fun(int& n)
//{
//	n++;
//}
//
//void main()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		fun(i);
//		cout << i << endl;
//	}
//	//return 0;
//}

//int x = 1, y = 2;
//int max2(int x, int y)
//{
//	return x > y ? x : y;
//}
//void main()
//{
//	int x = 3;
//	//cout << max1(x, y) << endl;
//	cout << max2(::x, y) << endl;
//}


//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.异常安全问题
//	int* p3 = new int[10];
//	//Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//	delete[] p3;
//}
//
//int  main()
//{
//	MemoryLeaks();
//	return 0;
//}

int main()
{
	int * p = (int*)malloc(0xffffffff);
	cout << p << endl;

	return 0;
}