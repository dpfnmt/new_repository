#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _capacity;
	int  _top;
};

//初始栈
void InitStack(Stack * ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
//销毁栈
void DestoryStack(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//插入数据
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, (sizeof(STDataType)*newcapacity));
		if (ps->_top != NULL);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

//删除栈
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
//栈顶的元素
STDataType StackTop(Stack* ps)
//void StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
//清空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
} 

//栈的数量
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
int main()
{
	Stack s;
	InitStack(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d\n", StackSize(&s));
	printf("%d\n", StackTop(&s));
	while (StackEmpty(&s) != 0)
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
		
	}
	printf("\n");
	return 0;
}

//
//队列 先进先出
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<malloc.h>
//
//typedef int QUDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* _next;
//	QUDataType _data;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* _head;
//	QueueNode* _tail;
//}Queue;
//
//
//首先初始化队列
//
//void InitQueue(Queue* pq)
//{
//	assert(pq);
//	pq->_head = pq->_tail = NULL;
//}
//
//消除队列
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	struct QueueNode* cur = pq->_head;
//	while (cur)
//	{
//		struct QueueNode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	pq->_head = pq->_tail = NULL;
//}
//
//插入
//
//QueueNode* BuyNewNode(QUDataType x)
//{
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
//	node->_data = x;
//	node->_next = 0;
//	return node;
//
//}
//void QueuePush(Queue* pq, QUDataType x)
//{
//	assert(pq);
//	if (pq->_head == NULL)
//	{
//		pq->_head = pq->_tail = BuyNewNode(x);
//	}
//	else
//	{
//		pq->_tail->_next = BuyNewNode(x);
//		pq->_tail = pq->_tail->_next;
//	}
//}
//删除
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	if (pq->_head)
//	{
//		QueueNode* next = pq->_head->_next;
//		free(pq->_head);
//		pq->_head = next;
//		if (pq->_head == NULL)
//		{
//			pq->_tail = NULL;
//		}
//	}
//}
//打印
//void Queueprint(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->_head;
//	while (cur)
//	{
//		printf("%d ", cur->_data);
//		cur = cur->_next;
//	}
//	printf("\n");
//}
//
//int main()
//{
//	Queue q;
//	InitQueue(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 2);
//	QueuePush(&q, 5);
//	Queueprint(&q);
//	QueuePop(&q);
//	Queueprint(&q);
//
//}


