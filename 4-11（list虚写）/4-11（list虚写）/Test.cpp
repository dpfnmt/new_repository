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
//	//��listβ������5����ͷ������0��
//	l.push_back(5);
//	l.push_front(0);
//	PrintList(l);
//	//ɾ��list��ͷ��β
//	l.pop_back();
//	l.pop_front();
//	PrintList(l);
//
//
//	return 0;
//}


//template <class... Args>
//void emplace_front(Args&&... args) ��C++11��
//																	��list��һ��Ԫ��ǰ���ݲ�
//																	��ֱ�ӹ���Ԫ��
//template <class... Args>
//void emplace_back(Args&&... args) ��C++11��
//																	��list���һ��Ԫ�غ����
//																	����ֱ�ӹ���Ԫ��
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
//// push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯��
//// emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
//// emplace_back��push_back����Ч������һ�ο������캯���ĵ���
//
//int main()
//{  
//	list<Date> l;  //������list<Date>,������list<int>;
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
//	//��ȡ�����еڶ���λ�ã�
//	auto pos = ++l.begin();
//	cout << *pos << endl;
//
//	//��pos��λ�ò���4��
//	l.insert(pos, 4);
//	PrintList(l);
//
//	//��pos��λ�ò���5��3��
//	l.insert(pos, 5, 3);
//	PrintList(l);
//
//	//��pos��λ���������v.begin��v,end
//	vector<int> v{ 5, 6, 7 };
//	l.insert(pos, v.begin(), v.end());
//	PrintList(l);
//
//	//ɾ��posλ��
//	l.erase(pos);
//	PrintList(l);
//
//	//ɾ��list�����ȫ��
//	l.erase(l.begin(), l.end()); //�������ǰ�����pos������ִ���ʲô����ʵ��
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
//	//��������ĸ����������Ļ�����Ĭ�ϵ�ֵ�����棻
//	l.resize(10);
//	PrintList(l);
//	//���ӵ�20��,�����Ļ���5�����䣻
//	l.resize(20, 5);
//	PrintList(l);
//	//���� ��5��
//	l.resize(5);
//	PrintList(l);
//	//����Ҳ����ʹ��vector������list��
//	vector<int> v{ 5, 6, 7 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//	//����l��l2;
//	l.swap(l2);
//	PrintList(l);
//	PrintList(l2);
//	//��l2�е�Ԫ����գ�
//	l2.clear();
//	cout << l2.size() << endl;
//	return 0;
//}