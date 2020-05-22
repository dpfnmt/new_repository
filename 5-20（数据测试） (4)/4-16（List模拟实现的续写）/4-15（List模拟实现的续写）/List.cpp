#include"List.h"

void  TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

//const的迭代器
void PrintList(const List<int>& lt)    //这里出现的是const的对象，调用非const的类型，报错；
{ 
	List<int>::const_iterator it = lt.begin();   
	while (it != lt.end())
	{
		//*it = 10;        //这里还出现了将里面的值改变了，所以我们应该使用const的类型的迭代器；
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void  TestList1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	PrintList(l);
}


void  TestList2()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	List<int>::iterator it = l.begin();   //普通迭代器就可以赋值
	while (it != l.end())
	{
		*it = 10;       
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


//使用迭代器增 删 查 找 
void  TestList3()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	l.PushFront(0);

	l.PopBack();
	l.PopFront();
	List<int>::iterator it = l.begin();  
	while (it != l.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//调用拷贝构造 加 赋值
void  TestList4()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}

	List<int> copy(l);
	PrintList(l);

	List<int> it2;
	it2.PushBack(10);
	it2.PushBack(20);
	copy = it2;
	PrintList(copy);

	cout << copy.Size() << endl;  //打印里面的个数；
}

//删除偶数
void  TestList5()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	auto it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it = l.Erase(it);
		}
		else
		{
			++it;
		}
	 }

	for (auto e : l)
	{
		cout << e << " ";
	}
}
int main()
{
	//TestList();
	//TestList2();
	//TestList3();
	//TestList4();
	TestList5();

	return 0;
}