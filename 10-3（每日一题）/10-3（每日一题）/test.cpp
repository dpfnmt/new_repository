#include <iostream>
using namespace std;

class Person{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//#include <fstream>
//
//int main()
//{
//	//cout << sizeof(Derive) << endl;
//	//Derive d;
//	//PrintVTable((VFPTR*)(*(int*)&d));
//	//PrintVTable((VFPTR*)(*(int*)((char*)&d+sizeof(Base1))));
//
//	FILE* fout = fopen("test.txt", "r");
//	if (fout == nullptr)
//	{
//		cout << errno << endl;
//	}
//
//	ifstream ifs;
//	ifs.open("test.txt");
//
//	return 0;
//}

#include <string>

//void Func2()
//{
//	throw 1.11111;
//
//	throw 5;
//}
//
//void Func1()
//{
//	try
//	{
//		Func2();
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//
//	FILE* fout = fopen("test.txt", "r");
//	if (fout == nullptr)
//	{
//		string errmsg("打开文件失败");
//		throw errmsg;
//	}
//
//	cout << "Func2" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (string& s)
//	{
//		cout << s << endl;
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//double Division(int a, int b) throw (const char*)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	int* array = new int[10];
//	//int* array2 = new int[20];
//	//int* array3 = new int[20];
//	//int* array4 = new int[20];
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete:" << array << endl;
//		delete[] array;
//		throw;
//	}
//
//	// ...
//
//	delete[] array;
//	cout << "delete:" << array << endl;
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//	catch (...){
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}

//int main()
//{
//	try
//	{
//		string s("hello");
//		cout << s.at(7) << endl;
//
//		char* p1 = new char[0x7fffffff];
//		cout << p1 << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//}

//class BitException
//{
//public:
//	BitException(int errid, string errmsg, string file, int line)
//		:_errid(errid)
//		, _errmsg(errmsg)
//		, _file(file)
//		, _line(line)
//	{}
//
//protected:
//	int _errid;
//	string _errmsg;
//	string _file;
//	int _line;
//
//	//stack<string> _funcst; // 函数堆栈
//};
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		BitException e(1, "除0错误", __FILE__, __LINE__);
//		throw e;
//	}
//	return (double)a / (double)b;
//}
//
//int main()
//{
//	try
//	{
//	/*	int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;*/
//		cout << string() << endl;
//	}
//	catch (const BitException& e)
//	{
//		int i = 0;
//	}
//	catch (...)
//	{
//	}
//}


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "除0错误";
//	}
//	return (double)a / (double)b;
//}
//
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete[] _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	try
//	{
//		int* array = new int[10];
//		SmartPtr<int> sp(array);
//
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//	}
//}

// 1.RAII
// 2.像指针一样的行为
// 3.拷贝问题 如何解决？
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete[] _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//struct AA
//{
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	//int* p = new int(1);
//	SmartPtr<int> sp(new int(10));
//	SmartPtr<int> copy(sp);
//
//	/**p = 2;
//	*sp = 20;
//	sp.operator*() = 20;
//	cout << *sp << endl;
//
//	SmartPtr<AA> spaa(new AA);
//	(*spaa)._a1 = 10;
//	spaa->_a2 = 20;
//
//	spaa.operator->()->_a1 = 100;
//
//	cout << spaa->_a1 << endl;
//	cout << spaa->_a2 << endl;*/
//
//	return 0;
//}

#include <memory>
#include <thread>
#include <mutex>

// 1.C++98 auto_ptr 管理权转移，设计缺陷，严禁使用
// 2.C++11 unique_ptr 防拷贝，简单粗暴的设计，鼓励使用
// 3.C++11 shared_ptr 引用计数，支持拷贝，鼓励使用

void test_auto_ptr()
{
	auto_ptr<int> ap(new int);
	*ap = 10;
	cout << *ap << endl;

	auto_ptr<int> copy(ap);
	cout << *ap << endl;
	cout << *copy << endl;
}

void test_unique_ptr()
{
	unique_ptr<int> up(new int);
	*up = 10;
	cout << *up << endl;

	//unique_ptr<int> copy(up);
	//cout << *ap << endl;
	//cout << *copy << endl;
}

void test_shared_ptr()
{
	shared_ptr<int> sp(new int);
	*sp = 10;
	cout << *sp << endl;

	shared_ptr<int> copy(sp);
	cout << *sp << endl;
	cout << *copy << endl;
}

namespace BIT
{
	template<class T>
	class AutoPtr
	{
	public:
		AutoPtr(T* ptr)
			:_ptr(ptr)
		{}

		~AutoPtr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}


		// BIT::AutoPtr<int> copy(ap);
		AutoPtr(AutoPtr<T>& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class UniquePtr
	{
	public:
		UniquePtr(T* ptr)
			:_ptr(ptr)
		{}

		~UniquePtr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// C++11 防拷贝
		//UniquePtr(UniquePtr<T>& ap) = delete;
	private:
		// 防拷贝 C++98 1.只声明不实现 2.私有
		UniquePtr(UniquePtr<T>& ap);
	private:
		T* _ptr;
	};

	template<class T>
	class SharedPtr
	{
	public:
		SharedPtr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		~SharedPtr()
		{
			/*if (--(*_pcount) == 0)
			{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			delete _pcount;
			}*/

			Realase();
		}

		SharedPtr(const SharedPtr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			//++(*_pcount);
			AddRefCount();
		}

		// sp1 = sp2
		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{
			//if (this != &sp)
			if (_ptr != sp._ptr)
			{
				/*if (--(*_pcount) == 0)
				{
				delete _ptr;
				delete _pcount;
				}*/

				Realase();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				//++(*_pcount);
				AddRefCount();
			}

			return *this;
		}

		void AddRefCount() //增加
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Realase() //释放
		{
			bool deleteflag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				cout << "delete" << _ptr << endl;
				delete _pcount;
				delete _ptr;
				deleteflag = true;
			}
			_pmtx->unlock();

			if (deleteflag == true)
				delete _pmtx;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
	};
}

void TestAutoPtr()
{
	BIT::AutoPtr<int> ap(new int);
	BIT::AutoPtr<int> copy(ap);
}

void TestUniquePtr()
{
	BIT::UniquePtr<int> ap(new int);
	//BIT::UniquePtr<int> copy(ap);
}

void TestSharedPtr()
{
	BIT::SharedPtr<int> sp(new int);
	BIT::SharedPtr<int> copy(sp);

	BIT::SharedPtr<int> sp1(new int);
	BIT::SharedPtr<int> sp2(sp1);

	//sp = sp1;
	//copy = sp1;

	sp1 = sp1;
	sp1 = sp2;
}

//int main()
//{
//	//test_auto_ptr();
//	//test_shared_ptr();
//	//TestAutoPtr();
//	//TestUniquePtr();
//	//TestSharedPtr();
//
//	return 0;
//}

//#include <thread>
//#include <mutex>
//
//// 线程安全
//mutex mtx;
//void func(int* pcount, int n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 不是原子操作
//		mtx.lock();
//		++(*pcount);
//		mtx.unlock();
//	}
//}
//
//int main()
//{
//	int count = 0, n = 1000000;
//	thread t1(func, &count, n);
//	thread t2(func, &count, n);
//
//	t1.join();
//	t2.join();
//
//	cout << count << endl;
//}

#include <thread>


void SharePtrFunc(BIT::SharedPtr<int>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		BIT::SharedPtr<int> copy(sp);
	}
}

int main()
{
	BIT::SharedPtr<int> sp(new int);
	std::thread t1(SharePtrFunc, sp, 10000);
	std::thread t2(SharePtrFunc, sp, 10000);

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;
}