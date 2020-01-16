#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>


typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	ListNode* _next;
};

typedef struct List
{
	struct ListNode* _head;
}List;


void ListInit(ListNode* list);
void Destroy(ListNode* list);

void PushBack(ListNode* list, LTDataType x);
void PopBack(ListNode* list);
void ListPushFront(List* list, LTDataType x);
void ListPopFront(List* list);

ListNode* ListFind(List* list, LTDataType x);
void ListInsertAfter(List* pos, LTDataType x);
void ListErset(List* pos);

void ListRemove(List* list);

void ListPrint(ListNode* list);

