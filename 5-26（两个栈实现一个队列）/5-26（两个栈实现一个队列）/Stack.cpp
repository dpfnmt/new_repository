#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class Queue
{
public:
	//�����
	void push(const T&data){
		stack1.push(data);
	}
	//������
	T&Pop()
	{
		T head;
		//�������ջ���ǿ�ջ����ʱ˵�������ǿյ�
		if (stack1.empty() && stack2.empty())
			cout << "this queue is empty" << endl;
		//���ջ2����Ԫ�أ��ǳ����оͳ�ջ2�е�
		if (!stack2.empty())
		{
			head = stack2.top();
			stack2.pop();
		}
		//��ʱ����ջ2���ǿ�ջ����Ҫ�����еĻ����Ǿ���Ҫ��ջ1�е�����Ԫ
		//����ջ��ջ2��,ע��һ��Ҫ��ջ1�е�����Ԫ�ض���ջ��ջ2��
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
	T & Front()//��ȡ��ͷԪ�أ���ʱ��ͷλ��ջ2��ջ��
	{
		assert(!stack1.empty() || !stack2.empty());
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();

		if (stack2.size() == 0)//��stack2Ϊ��ʱ�����쳣
		{
			throw new exception("queue is empty");
		}
	}
	//�ж��Ƿ�Ϊ��
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
	cout << "����ͷ�ڵ�Ϊ:>  " <<q.Front() << endl;
	cout << "��ͷΪ:>  " << q.Pop() << endl;
	cout << "����ͷ�ڵ�Ϊ:>  " << q.Front() << endl;
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}
