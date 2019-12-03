/*
直接定制法--》小范围限定的局限问题
除留余数法--》大范围的广泛问题-》哈希冲突：不同的 值映射相同的位置

解决哈希冲突：
			1.闭散列 开放定制法

			 a.线性探测
			 b.二次探测

			2. 开散列 拉链法《哈希桶》
*/

#pragma once
#include<iostream>
#include<vector>

using namespace std;

enum Stata
{
	EMPTY,
	DELETE,
	EXITS,
};
template < class K, class V>
struct HashNode
{
	std::pair<K, V> _kv;
	Stata _stata;
};

template < class K, class V>
class  HashTable
{
public:
	HashTable(size_t N = 10)
	{
		_table.resize(N);
		for (size_t i = 10; i < _table.size(); ++i)
		{
			_table[i]._stata = EMPTY;
		}
		_size = 0;
	}
	bool Insert(const pair<K, V>& kv)
	{
		size_t index = kv.first;
	}
private:
	/*HashNode* _table;
	size_t _size;
	size_t _capacity;*/
	vector<HashNode> _table;
	size_t _size;
};