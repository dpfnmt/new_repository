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
	QueueNode* _head; //��ͷ
	QueueNode* _tail; //��β
}Queue;

//��ʼ������
void InitQueue(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

//���ٶ���
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

//������
QueueNode* BuyNewNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
//��������
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

//ɾ������
void QueuePop(Queue* pq)
{
	assert(pq);
	//ȫɾ��
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

//���еĸ���
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

//���еĿ�
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == pq->_tail ? 0 : 1;
}

//����ͷ�ڵ�
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_head->_data;
}
//����β�ڵ�
QUDataType QueueTail(Queue* pq)
{
	assert(pq);
	return pq->_tail->_data;
}

//��ӡ����
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
	//��ӡͷ�ڵ�
	printf("%d\n", QueueFront(&q));
	//��ӡβ�ڵ�
	printf("%d\n", QueueTail(&q));
	//��ӡ���еĸ���
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



