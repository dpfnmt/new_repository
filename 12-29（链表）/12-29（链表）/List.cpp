
#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(-1);
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
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);

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
	ListNode* newnode = BuyListNode(x);
	head->_next = newnode;
	newnode->_next = next;
	newnode->_prev = head;
	next->_prev = newnode;
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode*nextnext = next->_next;
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
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
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos); 
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void ListRemove(List* plist, LTDataType x)
{
	ListNode* node = ListFind(plist,x);
	while (node != plist->_head)
	{
		ListErase(node);
	}


}

void ListReverse(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* tmp = NULL;

	while (cur != head)
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
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
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

	ListErase(pos);
	ListPrint(&s);

	ListReverse(&s);
	ListPrint(&s);


	ListRemove(&s, 5);
	ListPrint(&s);

	return 0;
}