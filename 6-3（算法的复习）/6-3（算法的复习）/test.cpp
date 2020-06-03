#include<stdio.h>


int main()
{
	int i = 1;
	char j = *(char*)(&i);
	if (j == 1)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}

	return 0;
}