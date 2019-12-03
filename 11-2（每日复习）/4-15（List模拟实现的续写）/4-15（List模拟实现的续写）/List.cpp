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

//const�ĵ�����
void PrintList(const List<int>& lt)    //������ֵ���const�Ķ��󣬵��÷�const�����ͣ�����
{ 
	List<int>::const_iterator it = lt.begin();   
	while (it != lt.end())
	{
		//*it = 10;        //���ﻹ�����˽������ֵ�ı��ˣ���������Ӧ��ʹ��const�����͵ĵ�������
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
	List<int>::iterator it = l.begin();   //��ͨ�������Ϳ��Ը�ֵ
	while (it != l.end())
	{
		*it = 10;       
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


//ʹ�õ������� ɾ �� �� 
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

//���ÿ������� �� ��ֵ
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

	cout << copy.Size() << endl;  //��ӡ����ĸ�����
}

//ɾ��ż��
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