#include<iostream>
using namespace std;


//int main()
//{
//	int one2ndays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		int n = one2ndays[month - 1];
//		n += day;
//		if ((month > 2) && ((month % 4 == 0 && month % 100 != 0) || (month % 400 == 0)))
//		{
//			n += 1;
//		}
//		cout << n << endl;
//	}
//
//	return 0;
//}

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//	free(p3);
//	int* p4 = new  int;
//	delete p4;
//	// 这里需要free(p2)吗?
//}

//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void Test2()
//{
//	// 申请单个Test类型的空间
//
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//	// 申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test3()
//{
//	// 申请单个Test类型的对象
//	Test* p1 = new Test;
//	delete p1;
//	// 申请10个Test类型的对象
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//int main()
//{
//	Test3();
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _head;
//    ListNode* _prev;
//	ListNode* _next;
//	int _data;
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);    //分配内存；
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1); //释放指定位置的内存；
//		cout << "memory pool deallocate" << endl;
//	}
//};
//class List
//{
//public:
//
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//	List l1;
//
//	return 0;
//}

//#include<malloc.h>
//#include<stdlib.h>
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void Test()
//{
//	// pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	int* pt = (int*)malloc(sizeof(int));
//	new(pt)int(3); // 注意：如果Test类的构造函数有参数时，此处需要传参
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() {}
//	// C++98
//	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
//	// 2.声明成私有
//	HeapOnly(const HeapOnly& ); // 只声明，有漏洞，copy是在栈上面，但是这里是只实现堆上面，
//	                             // 因为不管是类里面共有还是在类外面，都可以调用，除非是在私有。
//		// or
//		// C++11
//	HeapOnly(const HeapOnly&) = delete;  // 这是c++11中给的类型，delete是删除函数。
//};
//
//int main()
//{
//	HeapOnly* p1 = HeapOnly::CreateObject();
//	HeapOnly copy(* p1 );
//	return 0;
//}

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly() {}
//};
//
//int main()
//{
//	StackOnly p1 = StackOnly::CreateObject();   //在堆上面是不用不使用指针的， 直接定义函数名；
//	//HeapOnly copy(* p1 );
//	return 0;
//}


class  ConfigSingleton
{
public:
	static ConfigSingleton* GetInstance()
	{
		return  &_sinst;  //1.返回指针；
	}
	//static ConfigSingleton& GetInstance()
	//{
	//	return  _sinst;  //2.返回引用；
	//}
    
	void  Print()
	{
		cout << _ip << endl;
		cout << _port << endl;
	}
private:
	ConfigSingleton(const char* ip , int port)
		:_ip(ip)
		, _port(port) //获取对象
	{

	}
	const char* _ip;
	int _port;
	static ConfigSingleton _sinst;   //静态的相当于全局的；
};
ConfigSingleton ConfigSingleton::_sinst("2018.12.3", 80);
int main()
{
	ConfigSingleton::GetInstance()->Print();
	return 0;
}