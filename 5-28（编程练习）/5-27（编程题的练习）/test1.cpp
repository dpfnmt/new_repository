//#include<iostream>
//#include<queue>
//#include<assert.h>
//
//using namespace std;
//
//template <class T>
//class stack
//{
//public:
//	//尾部进行插入
//	void TailPush(const T&  data)
//	{
//		if (!q1.empty())
//		{
//			q1.push(data);
//		}
//		else
//		{
//			q2.push(data);
//		}
//	}
//	//头部进行删除
//	T & HeadDelet()
//	{
//		//当队列1不为空
//		int ret = 0;
//		if (!q1.empty())
//		{
//			int num = q1.size();
//			while (num > 1)
//			{
//				q2.push(q1.front());
//				q1.pop();
//				--num;
//			}
//			ret = q1.front();
//			q1.pop();
//		}
//		//当队列2不为空的时候
//		else
//		{
//				int num = q2.size();
//				while (num > 1)
//				{
//					q1.push(q2.front());
//					q2.pop();
//					--num;
//				}
//			ret = q2.front();
//			q2.pop();
//		}
//		return ret;
//	}
//
//private:
//	queue<T> q1;
//	queue<T> q2;
//};
//int main()
//{
//	stack<int> s;
//	s.TailPush(1);
//	s.TailPush(1);
//	s.TailPush(1);
//	cout << "栈顶为 " << s.HeadDelet() << endl;
//	cout << "栈顶为 " << s.HeadDelet() << endl;
//	cout << "栈顶为 " << s.HeadDelet() << endl;
//	return 0;
//}


