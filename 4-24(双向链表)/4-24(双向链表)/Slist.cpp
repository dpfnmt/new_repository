#include"Slist.h"

ListNode*BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
void ListInit(List* plist)
{
	ListNode* head = BuyListNode(-1);
	assert(plist);
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}
void ListDestory(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* next = NULL;
	assert(plist);
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
	ListNode*head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	assert(plist);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;
}


void ListPopBack(List* plist)
{
	ListNode*head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;
	assert(plist);
	free(tail);
	tailprev->_next = head;
	head->_prev = tailprev;

}

void ListPushFront(List* plist, LTDataType x)
{
	ListNode*head = plist->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyListNode(x);
	assert(plist);
	head->_next = newnode;
	newnode->_next = next;
	newnode->_prev = head;
	next->_prev = newnode;
}

void ListPopFront(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	assert(plist);
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;

}


ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	assert(plist);
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	assert(pos);
	newnode->_next = pos;
	pos->_prev = newnode;
	prev->_next = newnode;
	newnode->_prev = prev;
}
// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	assert(pos);
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void ListRemove(List* plist, LTDataType x)
{
	ListNode* node = ListFind(plist, x);
	assert(plist);
	if (node != plist->_head)
	{
		ListErase(node);
	}
}

int ListSize(List* plist)
{
	int size = 0;
	ListNode* cur = plist->_head->_next;
	assert(plist);
	while (cur != plist->_head)
	{
		size++;
		cur = cur->_next;
	}
	printf("%d", size);
	return size;

}
int ListEmpty(List* plist)
{
	assert(plist);
	printf("%d", plist->_head->_next == plist->_head ? 0 : -1);
	return 0;
}

void ListReverse(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* tmp = NULL;
	assert(plist);
	while (cur != plist->_head)
	{
		tmp = cur->_next;
		cur->_next = cur->_prev;
		cur->_prev = tmp;
		cur = cur->_prev;
	}
	tmp = head->_next;
	head->_next = head->_prev;
	head->_prev = tmp;
}
void ListPrint(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	assert(plist);
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

int main()
{
	List s;
	ListInit(&s);
	ListPushBack(&s, 1);
	ListPushBack(&s, 2);
	ListPushBack(&s, 3);
	ListPushBack(&s, 4);
	ListPushBack(&s, 5);
	ListPushBack(&s, 6);
	ListPushBack(&s, 7);

	ListPrint(&s);
	ListPopBack(&s);
	ListPrint(&s);
	ListPushFront(&s, 0);
	ListPrint(&s);
	ListPopFront(&s);
	ListPrint(&s);

	ListRemove(&s, 3);
	ListPrint(&s);

	ListNode* pos = ListFind(&s, 5);
	ListInsert(pos, 30);
	ListPrint(&s);


	ListErase(pos);
	ListPrint(&s);

	ListReverse(&s);
	ListPrint(&s);

}