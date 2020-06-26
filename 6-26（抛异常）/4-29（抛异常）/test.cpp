#include<iostream>
using namespace std;

double division(int a, int b) throw (const char*)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "division by zero condition!";
	else
		return ((double)a / (double)b);
}

void func()
{
	//int* array = new int[10];
	int* array2 = new int[20];
	//int* array3 = new int[20];
	//int* array4 = new int[20];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete:" << array2 << endl;
		delete[] array2;
		throw;
	}

	// ...

	delete[] array2;
	cout << "delete:" << array2 << endl;
}

int main()
{
	try {
		func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (...){
		cout << "unkown exception" << endl;
	}
	return 0;
}

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}