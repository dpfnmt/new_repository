#include<iostream>
#include<list>

using namespace std;


template<class T>
struct _ListNode
{
	T _data;
	_ListNode<T>* _prev;
	_ListNode<T>* _next;
	_ListNode<T>(const T& x = T())
		: _data(x)
		, _prev(nullptr)
		, _next(nullptr)
	{}
};

template<class T ,class Ref , class Ptr>
struct _ListIterator
{
	typedef _ListNode<T> Node;
	typedef _ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	_ListIterator(Node* node)
		:_node(node)
	{}

	/*const T& operator*()
	{
		return _node->_data;
	}*/
	Ref operator*()
	{
		return _node->_data;
	}
	//const T* operator->()
	//{
	//   	//return &_node->_data;
	//	return &(operator*());
	//}
      
	Ptr operator->()
	{
		//return &_node->_data;
		return &(operator*());
	}
	Self& operator++()   //前置++
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)   //后置++
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()   //前置--
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)   //后置++
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	bool operator != (const Self& s)
	{
		return _node != s._node;
	}
	bool operator == (const Self& s)
	{
		return _node == s._node;
	}


};


template<class T>
class List
{
	typedef _ListNode<T>  Node;
public:
	typedef _ListIterator<T,T&,T*>  iterator;   //这里调用迭代器的时候出错了，用成_ListNode,导致程序编不过
	typedef _ListIterator<T,const T&,const T*>  const_iterator;
	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end() const
	{
		return const_iterator(_head);
	}
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	} 

	//l2(l1)
	List(const List<T>& l)   //const类型，使用const迭代器；
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		const_iterator it = l.begin();
		while (it != l.end())
		{
			this->PushBack(*it);
			++it;
		}
		cout << endl;
	}

	//l1 =l2
	//List<T>& operator=(const List<T>& l)
	List<T>& operator=(List<T> l)  //现代写法
	{
		swap(_head, l._head);
		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	size_t Size()
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			++size;
		}
		return size;
	}

	bool Empty()
	{
		//return _head->_next = _head;
		return begin() == end();
	}
	void  Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			//cur = next;
			delete cur;
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		/*Node* newnode = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;*/
		Insert(end(), x);
	}
	void PopBack()
	{
		Erase(--end());
	}
	void PushFront(const T& x)
	{
		Insert(begin(), x);
	}
	void PopFront()
	{
		Erase(begin());
	}

	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);

		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}
	//void Erase(iterator pos)
	iterator Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;

		delete cur;


		return  iterator(next);
	}
private:
	Node* _head;
};
