#pragma once

#include<iostream>

using namespace std;
#include<map>
#include<set>
#include<windows.h>
#include <stdlib.h>
#include <assert.h>

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>&kv)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _kv(kv)
	, _bf(0)
	{}

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	K _key;
	V _value;

	int _bf; // balance factor
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	~AVLTree()
	{}

	bool Insert(const K& key , const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			//_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key ,value);
		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)
		{
			// 1.cur是parent的左边--bf cur是parent的右边++bf
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			// 1.parent == 0 高度不变，更新结束
			// 2.parent == 1、-1.高度变了，继续更新
			// 3.parent == 2、-2.不平衡，旋转变成平衡树，降低高度
			if (parent->_bf == 0)
			{
				break;
			}

			// 2.parent == 1、-1.高度变了，继续更新
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}

			// 3.parent == 2、-2.不平衡，旋转变成平衡树，降低高度
			else if (abs(parent->_bf) == 2)
			{
				// 旋转
				if (parent->_bf == 2)
				{
					if (parent->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				//旋转完成，不会影响上层，则结束。
				break;
			}
			else
			{
				assert(false);
			}
		}

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

			subR->_parent = ppnode;
		}

		parent->_bf = subR->_bf = 0;
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
		subL->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		RotateLR(parent->_right);
		RotateL(parent);
	}
		void RotateLR(Node* parent)
     	{
			RotateL(parent->_left);
			RotateR(parent);
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
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
private:
	Node* _root;
};

void TestAVLTree()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int,int> t;
	for (auto e : a)
	{
		t.Insert(e , e);
	}
	t.InOrder();

}

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key, const V& value)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _key(key)
	, _value(value)
	, _bf(0)
	{}

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	K _key;
	V _value;

	int _bf; // balance factor
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	~AVLTree()
	{}

	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			//_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key, value);
		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)
		{
			// 1.cur是parent的左边--bf cur是parent的右边++bf
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			// 1.parent == 0 高度不变，更新结束
			// 2.parent == 1、-1.高度变了，继续更新
			// 3.parent == 2、-2.不平衡，旋转变成平衡树，降低高度
			if (parent->_bf == 0)
			{
				break;
			}

			// 2.parent == 1、-1.高度变了，继续更新
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}

			// 3.parent == 2、-2.不平衡，旋转变成平衡树，降低高度
			else if (abs(parent->_bf) == 2)
			{
				// 旋转
				if (parent->_bf == 2)
				{
					if (parent->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				//旋转完成，不会影响上层，则结束。
				break;
			}
			else
			{
				assert(false);
			}
		}

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

			subR->_parent = ppnode;
		}

		parent->_bf = subR->_bf = 0;
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
		subL->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		RotateLR(parent->_right);
		RotateL(parent);
	}
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
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
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};