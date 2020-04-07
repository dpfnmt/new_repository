#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;

#include <map>
#include <set>

void test_set()
{
	// 1.�ڲ���
	// 2.����+ȥ��
	// 3.ȥ��
	std::set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(5);
	s.insert(3);
	s.insert(3);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(4);
	s.insert(5);
	s.insert(5);
	s.insert(5);

	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	auto it1 = std::find(s.begin(), s.end(), 5); // O(N)
	auto it2 = s.find(5); // O(logN)
	if (it2 != s.end())
	{
		s.erase(it2);
	}

	s.erase(5);
	s.erase(1);
	s.clear();
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_mutil_set()
{
	std::multiset<int> s;
	typedef std::multiset<int>::iterator msiter;
	s.insert(3);
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(5);
	s.insert(3);
	s.insert(4);

	//msiter it = s.begin();
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.find(2);
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
}

#include "BSTree.h"

void test_map1()
{
	std::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));

	std::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}

void test_map2()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		//std::map<std::string, int>::iterator it = countmap.find(e);
		auto it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}

	std::map<std::string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;
}

//void test_map3()
//{
//	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
//	std::map<std::string, int> countmap;
//	for (const auto& e : strs)
//	{
//		//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
//		auto ret = countmap.insert(make_pair(e, 1));
//		if (ret.second == false)
//		{
//			ret.first->second++;
//		}
//	}
//
//	//std::map<std::string, int>::iterator cit = countmap.begin();
//	auto cit = countmap.begin();
//	while (cit != countmap.end())
//	{
//		cout << cit->first << ":" << cit->second << endl;
//		++cit;
//	}
//	cout << endl;
//}

void test_map4()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		countmap[e]++;
	}

	for (const auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	std::map<std::string, std::string> dict;
	dict.insert(std::make_pair("left", "���"));
	dict.insert(std::make_pair("left", "ʣ��"));
	dict["left"] = "ʣ��";
	dict["string"];
	dict["set"] = "����";
}

int main()
{
	//test_set();
	//test_mutil_set();
	//TestBStree();
	//test_map2();
	//test_map4();

	return 0;
}