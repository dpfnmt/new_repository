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
		vector<int> v;  //这里还没有使用智能指针，会出现内存没有释放，
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
//	// 讲tmp指针委托给了sp对象，用时老师的话说给tmp指针找了一个可怕的女朋友！天天管着你，直到你godie^^
//		SmartPtr<int> sp(tmp);
//	// _MergeSort(a, 0, n - 1, tmp);
//	// 这里假设处理了一些其他逻辑
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