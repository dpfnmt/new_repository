#include<stdio.h>


int main()
{
	int i = 1;
	char j = *(char*)(&i);
	if (j == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;
}