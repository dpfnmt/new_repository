#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head; //队头
	QueueNode* _tail; //队尾
}Queue;

//初始化队列
void InitQueue(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

//销毁队列
void DestoryQueue(Queue* pq)
{
	assert(pq);
	struct QueueNode* cur = pq->_head;
	while (cur)
	{
		free(cur);
		cur = cur->_next;
	}
}

//买数据
QueueNode* BuyNewNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
//插入数据
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = BuyNewNode(x);
	}
	else //(pq->_head != NULL)
	{
		pq->_tail->_next = BuyNewNode(x);
		pq->_tail = pq->_tail->_next;
	}
}

//删除数据
void QueuePop(Queue* pq)
{
	assert(pq);
	//全删除
	//struct QueueNode* cur = pq->_head;
	if (pq->_head)
	{
		QueueNode* next = pq->_head->_next;
		free(pq->_head);
		pq->_head = next;
		if (pq->_head == NULL)
		{
			pq->_tail = NULL;
		}
	}
}

//队列的个数
int  QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->_head;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

//队列的空
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == pq->_tail ? 0 : 1;
}

//返回头节点
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_head->_data;
}
//返回尾节点
QUDataType QueueTail(Queue* pq)
{
	assert(pq);
	return pq->_tail->_data;
}

//打印队列
void Queueprint(Queue* pq)
{
	assert(pq);
	struct QueueNode* cur = pq->_head;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
int main()
{
	Queue q;
	InitQueue(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	Queueprint(&q);
	QueuePop(&q);
	Queueprint(&q);
	//打印头节点
	printf("%d\n", QueueFront(&q));
	//打印尾节点
	printf("%d\n", QueueTail(&q));
	//打印队列的个数
	printf("%d\n", QueueSize(&q));
	//printf("%d ", QueueEmpty(&q));

	while (QueueEmpty(&q) != 0)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	//DestoryQueue(&q);
	return 0;
}



