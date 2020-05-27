//#include<iostream>
//#include<stack>
//#include<assert.h>
//
//using namespace std;
//
//template<class T>
//class Queue
//{
//public:
//	//入队
//	void push(const T& data)
//	{
//		stack1.push(data);
//	}
//	//出队
//	T &pop()
//	{
//		T head;
//		//当两个栈都是为空的前提之下
//		if (stack1.empty() && stack2.empty())
//		{
//			cout << "this queue is empty" << endl;
//		}
//		//当s2不为空的时候，将栈2顶端元素给头节点
//		if (!stack2.empty())
//		{
//			head = stack2.top();
//			stack2.pop();
//		}
//		//通过这一步，说明栈2肯定为空了，那么我们就需要把栈1的元素放到栈2，是全部的元素
//		else
//		{
//			while (stack1.size() > 0)
//			{
//				stack2.push(stack1.top());
//				stack1.pop();
//			}
//			head = stack2.top();
//			stack2.pop();
//		}
//		return head;
//	}
//	//获取对头
//	T & Front()
//	{
//		//断言两个栈是否为空
//		assert(!stack1.empty() || !stack2.empty());
//		//如果栈2为空，且栈1不为空
//		if (stack2.empty())
//		{
//			while (!stack1.empty())
//			{
//				//将栈1的顶元素插入栈2中
//				stack2.push(stack1.top());
//				//将栈1从队列取出来
//				stack1.pop();
//			}
//		}
//		return stack2.top();
//	}
//	//判断是否为空
//	bool empty()
//	{
//		if (stack1.empty() && stack2.empty())
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//private:
//	stack<T> stack1;
//	stack<T> stack2;
//};
//
//int main()
//{
//	Queue<int> q;
//	q.push(1);
//	q.push(3);
//	q.push(5);
//	q.push(7);
//	//cout << "对头 " << q.pop() << endl;
//	cout << "对头 " << q.Front() << endl;
//	return 0;
//}
//
//

//两个队列完成一个栈

#include<iostream>
#include<queue>
#include<assert.h>

using namespace std;

template <class T>
class Stack
{
public:
	Stack(){};
	~Stack(){};
	//实现栈元素的尾部插入
	void TailAppend(const T& node)
	{
		//数据的插入原则：保持一个队列为空，一个队列不为空，往不为空的队列中插入元素
		//如果队列1不为空，将数据插入到队列1中
		if (!q1.empty())
		{
			q1.push(node);
		}
		//如果队列2不为空，将数据插入到队列2中
		else
		{
			q2.push(node);
		}
	}
    //实现栈元素的删除
	T& HeadDelete()
	{
		//定义一个返回值
		int ret = 0;
		//当队列1不为空，队列2为空，那么将q1的n-1个元素删除并插入到q2中
		//,q1剩下最后一个元素，且为我们要的栈顶元素（也叫栈的头删）
		if (!q1.empty())
		{
			//求出q1的长度-1
			int num = q1.size();
			while (num > 1)
			{
				//将其他删除插入到q2中
				q2.push(q1.front());
				q1.pop();
				--num;
			}
			//最后一个给返回值，并且出队列
			ret = q1.front();
			q1.pop();
		}
		//当q2不为空时，与队列1的做法，定义是一样的
		else
		{
			int num = q2.size();
			while (num > 1)
			{
				q1.push(q2.front());
				q2.pop();
				--num;
			}
			ret = q2.front();
			q2.pop();
		}
		return ret;
	}

private:
	queue<T> q1;
	queue<T> q2;
};

int main()
{
	Stack<int> s;
	s.TailAppend(1);
	s.TailAppend(2);
	s.TailAppend(3);
	cout << "栈顶为： " << s.HeadDelete() << endl;
	cout << "栈顶为： " << s.HeadDelete() << endl;
	cout << "栈顶为： " << s.HeadDelete() << endl;
	return 0;
}

