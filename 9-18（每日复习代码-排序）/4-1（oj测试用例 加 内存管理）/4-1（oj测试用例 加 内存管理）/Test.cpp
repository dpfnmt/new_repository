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
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//	free(p3);
//	int* p4 = new  int;
//	delete p4;
//	// ������Ҫfree(p2)��?
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
//	// ���뵥��Test���͵Ŀռ�
//
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test3()
//{
//	// ���뵥��Test���͵Ķ���
//	Test* p1 = new Test;
//	delete p1;
//	// ����10��Test���͵Ķ���
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
//		p = allocator<ListNode>().allocate(1);    //�����ڴ棻
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1); //�ͷ�ָ��λ�õ��ڴ棻
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
//	// pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	int* pt = (int*)malloc(sizeof(int));
//	new(pt)int(3); // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
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
//	// 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
//	// 2.������˽��
//	HeapOnly(const HeapOnly& ); // ֻ��������©����copy����ջ���棬����������ֻʵ�ֶ����棬
//	                             // ��Ϊ�����������湲�л����������棬�����Ե��ã���������˽�С�
//		// or
//		// C++11
//	HeapOnly(const HeapOnly&) = delete;  // ����c++11�и������ͣ�delete��ɾ��������
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
//	StackOnly p1 = StackOnly::CreateObject();   //�ڶ������ǲ��ò�ʹ��ָ��ģ� ֱ�Ӷ��庯������
//	//HeapOnly copy(* p1 );
//	return 0;
//}


class  ConfigSingleton
{
public:
	static ConfigSingleton* GetInstance()
	{
		return  &_sinst;  //1.����ָ�룻
	}
	//static ConfigSingleton& GetInstance()
	//{
	//	return  _sinst;  //2.�������ã�
	//}
    
	void  Print()
	{
		cout << _ip << endl;
		cout << _port << endl;
	}
private:
	ConfigSingleton(const char* ip , int port)
		:_ip(ip)
		, _port(port) //��ȡ����
	{

	}
	const char* _ip;
	int _port;
	static ConfigSingleton _sinst;   //��̬���൱��ȫ�ֵģ�
};
ConfigSingleton ConfigSingleton::_sinst("2018.12.3", 80);
int main()
{
	ConfigSingleton::GetInstance()->Print();
	return 0;
}