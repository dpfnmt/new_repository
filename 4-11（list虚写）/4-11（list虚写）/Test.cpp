#include<iostream>
#include<list>
#include<vector>
using namespace std;

//void PrintList(list<int>& l)
//{
//	for (auto& e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
////push_back/push_front/pop_back/pop_front
//
//int main()
//{
//	int arr[] = {1,2,3,4};
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	PrintList(l);
//
//	//在list尾部插入5，在头部插入0；
//	l.push_back(5);
//	l.push_front(0);
//	PrintList(l);
//	//删除list的头和尾
//	l.pop_back();
//	l.pop_front();
//	PrintList(l);
//
//
//	return 0;
//}


//template <class... Args>
//void emplace_front(Args&&... args) （C++11）
//																	在list第一个元素前根据参
//																	数直接构造元素
//template <class... Args>
//void emplace_back(Args&&... args) （C++11）
//																	在list最后一个元素后根据
//																	参数直接构造元素
//class Date
//{
//public:
//	Date(int year = 1990, int month =1, int day =1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//		{
//		cout << "Date(const Date& d)" << this << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
//// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
//// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
//
//int main()
//{  
//	list<Date> l;  //这里是list<Date>,而不是list<int>;
//	Date d1(2019, 4, 11);
//	l.push_back(d1);
//	l.emplace_back(2019, 4, 12);
//	l.emplace_front(2019, 4, 10);
//	return 0;
//}

//void PrintList(list<int>& l)
//{
//	for(auto& e : l)
//	{
//	cout << e << " ";
//}
//	cout << endl;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	
//	//获取链表中第二个位置；
//	auto pos = ++l.begin();
//	cout << *pos << endl;
//
//	//在pos的位置插入4；
//	l.insert(pos, 4);
//	PrintList(l);
//
//	//在pos的位置插入5个3；
//	l.insert(pos, 5, 3);
//	PrintList(l);
//
//	//在pos的位置上面插入v.begin，v,end
//	vector<int> v{ 5, 6, 7 };
//	l.insert(pos, v.begin(), v.end());
//	PrintList(l);
//
//	//删除pos位置
//	l.erase(pos);
//	PrintList(l);
//
//	//删除list链表的全部
//	l.erase(l.begin(), l.end()); //这里如果前面加上pos，会出现错误，什么导致实例
//	PrintList(l);
//
//	return 0;
//}

//void PrintList(list<int>& l)
//{
//	for (auto& e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	PrintList(l);
//	//增加数组的个数，不够的话，用默认的值来代替；
//	l.resize(10);
//	PrintList(l);
//	//增加到20个,不够的话用5来补充；
//	l.resize(20, 5);
//	PrintList(l);
//	//减少 到5个
//	l.resize(5);
//	PrintList(l);
//	//我们也可以使用vector来构造list。
//	vector<int> v{ 5, 6, 7 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//	//交换l和l2;
//	l.swap(l2);
//	PrintList(l);
//	PrintList(l2);
//	//将l2中的元素清空；
//	l2.clear();
//	cout << l2.size() << endl;
//	return 0;
//}