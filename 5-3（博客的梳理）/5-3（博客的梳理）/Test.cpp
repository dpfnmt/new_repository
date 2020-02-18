#include<iostream>
#include<string>
using namespace std;


//int main()
//{
//	try
//	{
//		char* p = new char[0x7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}

//void func1()
//{
//	//throw 10;//调用func1了，然后直接输出了。
//
//	throw 10.12909;//捕获最后的异常
//}
//void func2()
//{
//	string str("error");
//	throw str;
//	
//	try
//	{
//		string str("error");
//	    throw str;
//	}
//	catch (const string& str)
//	{
//		cout << str << endl;
//	}
//}
//int main()
//{
//	try
//	{
//		func1();
//		func2();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)//捕获整形异常
//	{
//		cout << i << endl;
//	}
//	catch (const string& str)//捕获string异常
//	{
//		cout << str << endl;
//	}
//	catch(...) //捕获任意异常，知道发生异常，但是不知道发生什么异常。
//	{
//		cout << "未知异常" << endl;
//	}
//	cout << "end" << endl;
//	return 0;
//}

//下面事除法的演示

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
//void Func()
//{
//	//如果这里增加这个的时候。
//	int* p = new int[10];
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//      
//	delete[] p; //这里当分母为偶数的时候，那么就不能被有效的释放了，所以这里上面要自己截获异常。
//	cout << p << endl;
//}
void Func()
{
	//如果这里增加这个的时候。
	int* p = new int[10];   //异常安全问题
	try{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	//第一种解决
	//catch (const char* errmsg)
	//{
	//	delete[] p; //这里当分母为偶数的时候，那么就不能被有效的释放了，所以这里上面要自己截获异常。
	//	cout << p << endl;
	//	throw errmsg;
	//}
	//第二种解决，当不知道什么异常的时候
	catch (...)
	{
		delete[] p; 
		cout << p << endl;
		throw;
	}
	delete[] p;  //如果只是用上面的话，只释放，但是没有抛出异常，这里问题很大，不能告诉外面处理的人，
	cout << p << endl;
}
int main()
{
	try 
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
	return 0;
}