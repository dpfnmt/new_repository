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
//	//���
//	void push(const T& data)
//	{
//		stack1.push(data);
//	}
//	//����
//	T &pop()
//	{
//		T head;
//		//������ջ����Ϊ�յ�ǰ��֮��
//		if (stack1.empty() && stack2.empty())
//		{
//			cout << "this queue is empty" << endl;
//		}
//		//��s2��Ϊ�յ�ʱ�򣬽�ջ2����Ԫ�ظ�ͷ�ڵ�
//		if (!stack2.empty())
//		{
//			head = stack2.top();
//			stack2.pop();
//		}
//		//ͨ����һ����˵��ջ2�϶�Ϊ���ˣ���ô���Ǿ���Ҫ��ջ1��Ԫ�طŵ�ջ2����ȫ����Ԫ��
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
//	//��ȡ��ͷ
//	T & Front()
//	{
//		//��������ջ�Ƿ�Ϊ��
//		assert(!stack1.empty() || !stack2.empty());
//		//���ջ2Ϊ�գ���ջ1��Ϊ��
//		if (stack2.empty())
//		{
//			while (!stack1.empty())
//			{
//				//��ջ1�Ķ�Ԫ�ز���ջ2��
//				stack2.push(stack1.top());
//				//��ջ1�Ӷ���ȡ����
//				stack1.pop();
//			}
//		}
//		return stack2.top();
//	}
//	//�ж��Ƿ�Ϊ��
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
//	//cout << "��ͷ " << q.pop() << endl;
//	cout << "��ͷ " << q.Front() << endl;
//	return 0;
//}
//
//

//�����������һ��ջ

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
	//ʵ��ջԪ�ص�β������
	void TailAppend(const T& node)
	{
		//���ݵĲ���ԭ�򣺱���һ������Ϊ�գ�һ�����в�Ϊ�գ�����Ϊ�յĶ����в���Ԫ��
		//�������1��Ϊ�գ������ݲ��뵽����1��
		if (!q1.empty())
		{
			q1.push(node);
		}
		//�������2��Ϊ�գ������ݲ��뵽����2��
		else
		{
			q2.push(node);
		}
	}
    //ʵ��ջԪ�ص�ɾ��
	T& HeadDelete()
	{
		//����һ������ֵ
		int ret = 0;
		//������1��Ϊ�գ�����2Ϊ�գ���ô��q1��n-1��Ԫ��ɾ�������뵽q2��
		//,q1ʣ�����һ��Ԫ�أ���Ϊ����Ҫ��ջ��Ԫ�أ�Ҳ��ջ��ͷɾ��
		if (!q1.empty())
		{
			//���q1�ĳ���-1
			int num = q1.size();
			while (num > 1)
			{
				//������ɾ�����뵽q2��
				q2.push(q1.front());
				q1.pop();
				--num;
			}
			//���һ��������ֵ�����ҳ�����
			ret = q1.front();
			q1.pop();
		}
		//��q2��Ϊ��ʱ�������1��������������һ����
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
	cout << "ջ��Ϊ�� " << s.HeadDelete() << endl;
	cout << "ջ��Ϊ�� " << s.HeadDelete() << endl;
	cout << "ջ��Ϊ�� " << s.HeadDelete() << endl;
	return 0;
}

