#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Print(int*a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BulleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		int change = 0;
		for (int i = 0; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i + 1],&a[i]);
				change = 1;
			}

		}
		if (change == 0)
		{
			break;
		}
		--end;
	}
}
int main()
{
	int a[] {2, 4, 6, 8, 7, 9, 3, 1, 5};

	BulleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));

	return 0;
}