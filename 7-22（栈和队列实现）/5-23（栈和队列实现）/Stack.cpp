#include"Stack.h"

//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//释放栈
void StackDestory(Stack * ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//栈的插入
void StackPush(Stack* ps, STDateType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		 size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		 ps->_a = (STDateType*)realloc(ps->_a,sizeof(STDateType)*newcapacity);
		 if (ps->_top != NULL);
		 ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDateType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);  //这里没有写后面的代码，所以编译不通过；
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

void print(Stack* ps)
{
	assert(ps);
	for (int i = 0; i <= ps->_capacity; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	while (StackEmpty(&s) != 0)
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
		printf("\n");
	}
	//print(&s);
	return 0;
}
