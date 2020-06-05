#include<iostream>
using namespace std;
#include<map>
#include<string>

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
//统计次数
void test_map2()
{
	string s[] = { "苹果", "苹果", "苹果", "苹果", "橘子", "苹果", "苹果", "香蕉", "苹果", "香蕉", "苹果" };
	map<string, int> countmap;
	for (const auto& e : s)
	{
		map<string, int>::iterator it = countmap.find(e);
		//auto it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}
void test_map3() //统计次数
{
	string s[] = { "苹果", "苹果", "苹果", "苹果", "橘子", "苹果", "苹果", "香蕉", "苹果", "香蕉", "苹果" };
	map<string, int> countmap;
	for (const auto& e : s) //不让用find();
	{
		pair<map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		//auto ret = countmap.insert(make_pair(e, 1));
		//auto缺陷，不容易读取，不知道里面什么内容
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}
void test_map4()
{
	string strs[] = { "苹果", "苹果", "西瓜", "苹果", "西瓜", "草莓", "草莓", "香蕉", "苹果", "苹果", "香蕉", "香蕉", "苹果", "苹果" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		countmap[e]++;
	}

	for (const auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}

}
void test_map5()
{
	map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));
	m[1] = 1;
	//再某一个位置插入一个值
	m.insert(m.find(2), make_pair(6, 6));
	cout << m.size() << endl;
	//将这个程序遍历一遍，打印
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}

	// map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair(7, 7));
	if (ret.second)
		cout << "<7, 7>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->"
		<< ret.first->second << " 插入失败" << endl;
	//将上面的打印出来
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << "————————————" << endl;
	//删除key为4的值
	m.erase(4);
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << "————————————" << endl;

	if (4 == m.count(4))
		cout << "4还在" << endl;
	else
		cout << "4不在了" << endl;
}
// multimap
//不存在operator[],因为key没有唯一性，
//不去重，也有用处，比如在学校登记新生的时候，有两个名字一样，不可能就不插入进去了。

void test_multimap6()
{
	multimap<string, string> m;
	m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	m.insert(make_pair("李逵", "铁牛"));

	cout << m.size() << endl;
	for (auto& e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << endl;
	}
	// key为李逵的元素有多少个
	cout << m.count("李逵") << endl;
}

void test_multimap7()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(pair<int, int>(i, i));
	}
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout <<"——————————————"<< endl;
	// 返回m中大于等于5的第一个元素
	auto it = m.lower_bound(5);

	cout << it->first << "--->" << it->second << endl;
	// 返回m中大于5的元素

	it = m.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;

}
//总结： set - map
/*
   set O(logN)
   1. 快速查找  key在不在？
   2.排序+去重

   map O(logN)
   1.快速查找   通过key查找value；
   2.附带作用，对key进行排序。通过字符串的大小进行排序的

 */
#include"RBTree.h"

   int main()
{
	//test_map1();
	//test_map2();
	//test_map3();
	//test_map4();
	//test_map5();
	//test_multimap6();
	//test_multimap7();
	   TestRBTree();
	return 0;
}

   
