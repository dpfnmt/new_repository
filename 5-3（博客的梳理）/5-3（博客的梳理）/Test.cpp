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
//	//throw 10;//����func1�ˣ�Ȼ��ֱ������ˡ�
//
//	throw 10.12909;//���������쳣
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
//	catch (int i)//���������쳣
//	{
//		cout << i << endl;
//	}
//	catch (const string& str)//����string�쳣
//	{
//		cout << str << endl;
//	}
//	catch(...) //���������쳣��֪�������쳣�����ǲ�֪������ʲô�쳣��
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	cout << "end" << endl;
//	return 0;
//}

//�����³�������ʾ

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
//void Func()
//{
//	//����������������ʱ��
//	int* p = new int[10];
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//      
//	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
//	cout << p << endl;
//}
void Func()
{
	//����������������ʱ��
	int* p = new int[10];   //�쳣��ȫ����
	try{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	//��һ�ֽ��
	//catch (const char* errmsg)
	//{
	//	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
	//	cout << p << endl;
	//	throw errmsg;
	//}
	//�ڶ��ֽ��������֪��ʲô�쳣��ʱ��
	catch (...)
	{
		delete[] p; 
		cout << p << endl;
		throw;
	}
	delete[] p;  //���ֻ��������Ļ���ֻ�ͷţ�����û���׳��쳣����������ܴ󣬲��ܸ������洦����ˣ�
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