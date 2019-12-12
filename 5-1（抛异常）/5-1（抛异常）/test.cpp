#include<iostream>
#include<string>

using namespace std;
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

		void AddRefCount()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Realase()
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

int main()
{
	test_auto_ptr();
	//test_shared_ptr();
	//TestAutoPtr();
	//TestUniquePtr();
	//TestSharedPtr();

	return 0;
}

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
//int  main()
//{
//	TestAutoPtr();
//	return 0;
//}
//#include <thread>
//
//
//void SharePtrFunc(BIT::SharedPtr<int>& sp, size_t n)
//{
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		BIT::SharedPtr<int> copy(sp);
//	}
//}
//
//int main()
//{
//	BIT::SharedPtr<int> sp(new int);
//	std::thread t1(SharePtrFunc, sp, 10000);
//	std::thread t2(SharePtrFunc, sp, 10000);
//
//	t1.join();
//	t2.join();
//
//	cout << sp.use_count() << endl;
//}