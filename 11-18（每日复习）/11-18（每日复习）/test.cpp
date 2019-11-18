#include<iostream>
#include<stdio.h>
#include<assert.h>

using namespace std;

int PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin<end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
			if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

int  main()
{
	int arr[] = { 3, 4, 1, 6, 7, 0, 5, 8 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}