//#include<iostream>
//using namespace std;
//
//#include<map>
//#include<set>
//
//
//void test_set()
//{
//	set<int> s;
//	s.insert(1);
//	s.insert(5);
//	s.insert(5);
//	s.insert(3);
//	s.insert(5);
//	s.insert(5);
//	s.insert(4);
//	s.insert(5);
//	s.insert(2);
//	s.insert(5);
//
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it<<" ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto it1 = find(s.begin(), s.end(), 5); //O(N)
//	auto it2 = s.find(5); //O(logN)
//
//}
//int main()
//{
//	test_set();
//	return 0;
//}

//void test_multiset()
//{
//	multiset<int> s;
//	s.insert(4);
//	s.insert(3);
//	s.insert(4);
//	s.insert(2);
//	s.insert(4);
//	s.insert(5);
//	s.insert(4);
//	s.insert(1);
//	s.insert(4);
//
//	multiset<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = s.find(2);
//	cout << *it << endl;
//	++it;
//	cout << *it << endl;
//	++it;
//
//}
#include"BSTree.h"

int main()
{
		//test_set();
	//test_multiset();

	TestBSTree();
	return 0;
}