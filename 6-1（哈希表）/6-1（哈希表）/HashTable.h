/*
ֱ�Ӷ��Ʒ�--��С��Χ�޶��ľ�������
����������--����Χ�Ĺ㷺����-����ϣ��ͻ����ͬ�� ֵӳ����ͬ��λ��

�����ϣ��ͻ��
			1.��ɢ�� ���Ŷ��Ʒ�

			 a.����̽��
			 b.����̽��

			2. ��ɢ�� ����������ϣͰ��
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