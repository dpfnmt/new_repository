/*#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

//�ҳ�һ�������е����͵ڶ�����ֵ
void GetMax1AndMax2(int a[], int& max1, int& max2, int n)
{
	max2 = max1 = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max1<a[i])
		{
			max2 = max1;
			max1 = a[i];
		}
		else if (max2<a[i])
		{
			max2 = a[i];
		}
	}
}

int main(){
	int a[] = { 2, 1, 3, 9, 5, 6, 4, 7 };
	int max1, max2;
	GetMax1AndMax2(a, max1, max2, sizeof(a) / sizeof(int));
	cout <<"���ֵ:" <<max1 <<  endl;
	cout << "�ڶ������ֵ:" << max2 << endl;
	return 0;
}*/

//�������Ĳ������

#include<iostream>
#include<queue>
using namespace std;


struct BinaryTreeNode{
	int value;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//����ڵ㣬ʹ������ÿ�����׽ڵ������ߵģ�С���ұߵ�
void AddBTNode(BinaryTreeNode **myBT, int val)
{
	if (*myBT == nullptr)
	{
		*myBT = new BinaryTreeNode();
		(*myBT)->value = val;
		(*myBT)->m_pLeft = nullptr;
		(*myBT)->m_pRight = nullptr;
		return;
	}

	if (val == (*myBT)->value)
	{
		return;
	}
	else if (val < (*myBT)->value)
	{
		AddBTNode(&(*myBT)->m_pLeft, val);
	}
	else
	{
		AddBTNode(&(*myBT)->m_pRight, val);
	}
}

//��α���,���ö���ʵ��
void LevelTraverse_MyTree(BinaryTreeNode *myBT)
{
	if (myBT == nullptr)
		return;

	queue<BinaryTreeNode *> que;  //����һ�������ָ��Ķ���
	que.push(myBT);

	while (!que.empty())
	{

		if ((que.front())->m_pLeft != nullptr)  //que.front()�õ���ǰ��� 
		{
			que.push((que.front())->m_pLeft);
		}

		if ((que.front())->m_pRight != nullptr)
		{
			que.push((que.front())->m_pRight);
		}

		cout << (que.front())->value << " ";
		que.pop();
	}
	cout << endl;
}

int main()
{

	BinaryTreeNode *myBT = nullptr;

	AddBTNode(&myBT, 10);
	AddBTNode(&myBT, 2);
	AddBTNode(&myBT, 3);
	AddBTNode(&myBT, 15);
	AddBTNode(&myBT, 18);
	AddBTNode(&myBT, 1);
	AddBTNode(&myBT, 16);

	cout << "�������:  ";
	LevelTraverse_MyTree(myBT);

	return 0;
}

