#include"List.h"

ListNode* BuyNode(LTDataType x)
{
	ListNode * node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyNode(-1);
	plist->_head = head;
	head->_next = head;
	head->_prev = head;

}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* next = NULL;
	while (cur != head)
	{
		next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	free(head);
	head = NULL;

}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyNode(x);

	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;

}

void ListPopBack(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;

	free(tail);
	tailprev->_next = head;
	head->_prev = tailprev;
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyNode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;

	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;

	while (next != head)
	{
		if (next->_data == x)
		{
			return next;

		}
		next = next->_next;
	}
}

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;

	free(pos);
	next->_prev = prev;
	prev->_next = next;
}

void ListRemove(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* tmp = NULL;

	while (cur != head)
	{
		tmp = cur->_prev;
		cur->_prev = cur->_next;
		cur->_next = tmp;

		cur = cur->_prev;
	}

	tmp = head->_prev;
	head->_prev = head->_next;
	head->_next = tmp;
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		printf("->%d<-", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


int main()
{
	List s;
	ListInit(&s);
	ListPushBack(&s, 1);
	ListPushBack(&s, 3);
	ListPushBack(&s, 4);
	ListPushBack(&s, 2);
	ListPushBack(&s, 5);
	ListPushBack(&s, 8);
	ListPrint(&s);
	
	ListPopBack(&s);
	ListPrint(&s);

	ListPushFront(&s, 0);
	ListPrint(&s);

	ListPopFront(&s);
	ListPrint(&s);


	ListNode* pos = ListFind(&s, 4);
	ListInsert(pos, 6);
	ListPrint(&s);

	ListNode* pos1 = ListFind(&s, 4);
	ListErase(pos1);
	ListPrint(&s);

	ListRemove(&s);
	ListPrint(&s);


	return 0;
}