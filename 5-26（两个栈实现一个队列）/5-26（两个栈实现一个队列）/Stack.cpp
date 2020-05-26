#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class Queue
{
public:
	//入队列
	void push(const T&data){
		stack1.push(data);
	}
	//出队列
	T&Pop()
	{
		T head;
		//如果两个栈都是空栈，此时说明队列是空的
		if (stack1.empty() && stack2.empty())
			cout << "this queue is empty" << endl;
		//如果栈2中有元素，那出队列就出栈2中的
		if (!stack2.empty())
		{
			head = stack2.top();
			stack2.pop();
		}
		//此时表明栈2已是空栈，再要出队列的话，那就需要把栈1中的所有元
		//素入栈到栈2中,注意一定要是栈1中的所有元素都入栈到栈2中
		else
		{
			while (stack1.size() > 0)
			
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			head = stack2.top();
			stack2.pop();
		}
		return head;
	}
	T & Front()//获取队头元素，此时队头位于栈2的栈顶
	{
		assert(!stack1.empty() || !stack2.empty());
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();

		if (stack2.size() == 0)//当stack2为空时，抛异常
		{
			throw new exception("queue is empty");
		}
	}
	//判断是否为空
	bool empty()
	{
		if (stack1.empty() && stack2.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	stack<T> stack1;
	stack<T> stack2;
};
void TestQueue()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << "队列头节点为:>  " <<q.Front() << endl;
	cout << "队头为:>  " << q.Pop() << endl;
	cout << "队列头节点为:>  " << q.Front() << endl;
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}
