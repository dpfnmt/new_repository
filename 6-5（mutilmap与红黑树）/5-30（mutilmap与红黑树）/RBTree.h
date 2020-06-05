#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left; // �ڵ������
	RBTreeNode<K,V>* _right; // �ڵ���Һ���
	RBTreeNode<K,V>* _parent; // �ڵ��˫��(�������Ҫ��ת��Ϊ��ʵ�ּ򵥸������ֶ�)

	pair<K, V> _kv;
	Colour _col;
	RBTreeNode(const pair<K,V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree  //��������д����
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED; 
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		
		//ƽ��
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//��һ���������ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{

					//�����������˫��-������
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}

					//�ڶ������������+��ɫ
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else //parend == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}

		_root->_col = BLACK; //�����ǲ��Ǹ��ڵ㣬����ɺ�ɫ
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subR;
			else
				ppnode->_right = subR;

			//subR->_parent = ppnode;
		}

		subR->_parent = ppnode;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subL;
			else
				ppnode->_right = subL;
		}

		subL->_parent = ppnode;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};

void TestRBTree()
{
	RBTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();

}