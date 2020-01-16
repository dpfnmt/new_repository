#include"list.h"


ListNode* BuyNode(LTDataType x)
{
	assert(x);
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;

	return node;
}

void ListInit(List* list)
{
	assert(list);
	ListNode* head = BuyNode(-1);
	list->_head = head;
	head->_next = head;
	
}


void Destroy(List* list)
{
	assert(list);
	ListNode* head = list->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		free(cur);
		cur = cur->_next;
	}
	free(head);
	head = NULL;
}


void ListPushBack(List* list, LTDataType x)
{
	assert(list);
	ListNode* tail =list->_head ;
	ListNode* newtail;
	
	if (list->_head == NULL)
	{
		list->_head = BuyNode(x);
	}
	else
	{
		while(tail->_next != NULL)
		{
			tail = tail->_next;
		}

		newtail = BuyNode(x);
		tail->_next = newtail;
	}
}

void ListPopBack(List* list)
{
	assert(list);
	ListNode* tail = list->_head;
	ListNode* prev;

	if (list->_head->_next == NULL)
	{
		free(list->_head);
		list->_head = NULL;
	}
	else
	{
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void ListPushFront(List* list, LTDataType x)
{
	assert(list);
	ListNode* head = list->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyNode(x);

	head->_next = newnode;
	newnode->_next = next;
}

void ListPopFront(List* list)
{
	assert(list);
	ListNode* head = list->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;

	free(next);
	head->_next = nextnext;

}

void ListPrint(List* list)
{
	assert(list);
	ListNode* head = list->_head;
	ListNode* cur = head->_next;
	printf("单向链表的结果是：");
	while (cur != head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


ListNode* ListFind(List* list, LTDataType x)
{
	assert(list);
	ListNode* head = list->_head;
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

void ListInsertAfter(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* cur = pos->_next;
	//ListNode* next = cur->_next; 不需要在后面了；
	ListNode* newnode = BuyNode(x);

	pos->_next = newnode;
	newnode->_next = cur;

}
//pos的前面进行删除
void ListEraseAfter(ListNode* pos)
{
	assert(pos && pos->_next);
	ListNode* next = pos->_next;
	ListNode* nextnext = next->_next;
	pos->_next = nextnext;
	free(next);
	next = NULL;

}
void ListRemove(List* list)
{
	assert(list);
	ListNode* head = list->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	ListNode* tmp = NULL;

	while (next != head)
	{
		tmp = head;
		head = nextnext;
		nextnext = tmp;

		next = next->_next;
	}

}

int main()
{
	List s;
	ListInit(&s);

	/*ListPushBack(&s, 7);
	ListPushBack(&s, 8);
	ListPushBack(&s, 9);
	ListPrint(&s);*/

	ListPushFront(&s, 6);
	ListPushFront(&s, 4);
	ListPushFront(&s, 3);
	ListPushFront(&s, 2);
	ListPushFront(&s, 1);
	ListPrint(&s);

	/*ListPopBack(&s);
	ListPrint(&s);*/

	ListPopFront(&s);
	ListPrint(&s);

	ListNode* pos = ListFind(&s, 4);
	ListInsertAfter(pos, 5);
	ListPrint(&s);


	ListNode* pos1 = ListFind(&s, 4);
	ListEraseAfter(pos1);
	//ListRemove(&s);
	ListPrint(&s);

	return 0;
}