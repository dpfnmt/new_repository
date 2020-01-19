#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

//¶¯Ì¬Ôö³¤
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; 
	int _capacity; 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void StackPrint();

