#pragma once
#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree //Binary search tree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	~BSTree()
	{}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key  < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	Node* Find(const K& key)
	{
		Node*cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
	}

	bool Erase(const K& key)
	{
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
				//1.节点为空，父亲指向节点的右，删除节点
				//2.节点右为空，父亲指向节点的左，删除节点
				//3.节点的左右都不为空，找右数最左节点，或者左数最右节点
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = _root->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{
					//Node* p_replace = nullptr;//这里一定不会为空，因为他不会是根;
					Node* p_replace = cur;
					Node* replace = cur->_right;

					while (replace->_left)
					{
						p_replace = replace;
						replace = replace->_left;
					}
					cur->_key = replace->_key;
					//删除replace节点
					if (p_replace->_left == replace)
					{
						p_replace->_left = replace->_right;
					}
					else
					{
						p_replace->_right = replace->_right;
					}

					del = replace;
				}
				delete del;
				return true;
			}
		}
		return false;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root;
};

int TestBSTree()
{
	/*BSTree<int> t;
	t.Insert(3);
	t.Insert(2);
	t.Insert(4);
	t.Insert(6);
	t.Insert(5);
	t.Insert(1);

	t.InOrder();

	t.Erase(5);*/

	BSTree<int> t;

	int a[] = { 2, 4, 3, 1, 6, 7, 5, 8, 9, 0 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	t.Erase(2);
	t.InOrder();

	t.Erase(8);
	t.Erase(1);
	t.Erase(5);

	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
	}
	t.InOrder();
	return 0;
}