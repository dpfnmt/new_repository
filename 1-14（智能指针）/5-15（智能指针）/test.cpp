#include<iostream>
#include<vector>
using namespace std;

	template<class T>
	class SmartPtr {
	public:
		SmartPtr(T* ptr)
			: _ptr(ptr)
		{}
		~SmartPtr()
		{
			cout << _ptr << endl;
			delete[] _ptr;
		}
	private:
		T* _ptr;
	};

	void func()
	{
		vector<int> v;  //���ﻹû��ʹ������ָ�룬������ڴ�û���ͷţ�
		v.at(0) = 10;

		int* p = new int;
		SmartPtr<int> sp1(p);


		/*vector<int> v(10);
		size_t pos;
		cin >> pos;
		v.at(pos) = 10;

		int* p = new int;
		SmartPtr<int> sp1(p);*/
	}
	int main()
	{
		try{
			func();

		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		return 0;
	}


//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	// ��tmpָ��ί�и���sp������ʱ��ʦ�Ļ�˵��tmpָ������һ�����µ�Ů���ѣ���������㣬ֱ����godie^^
//		SmartPtr<int> sp(tmp);
//	// _MergeSort(a, 0, n - 1, tmp);
//	// ������账����һЩ�����߼�
//	vector<int> v(1000000000, 10);
//	// ...
//}
//
//int main()
//{
//	try {
//		int a[5] = { 4, 5, 2, 3, 1 };
//		MergeSort(a, 5);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << "shenhuojiushihaso" << endl;
//	return 0;
//}