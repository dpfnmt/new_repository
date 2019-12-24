#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int GetMidindex(int* a, int begin, int end)
{
	int mid = begin + ((begin - end) >> 1);
	if (a[begin] < a[mid])
	{
	   if (a[mid] < a[end])
		{
		   return mid;
		}
	   else if (a[begin] > a[end])
	   {
		   return begin;
	   }
	   else
		   return end;
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
			return end;
	}
}
int PartSort(int* a, int begin, int end)
{
	int mid = GetMidindex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int key = begin;
	while (begin < end)
	{

		while (begin < end && a[end] >= a[key])
			--end;

		while (begin < end && a[begin] <= a[key])
			++begin;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);

	return end;
}

void QuickSort(int* a, int left, int right)
{

	if (left >= right)
		return;
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1 , right);
}

void TestSortOP()
{
	const int n = 100000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	//int* a2 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		//a2[i] = a1[i];
	}

	 size_t begin1 = clock();
	QuickSort(a1, 0, n - 1);
	size_t end1 = clock();
	printf("shengguo\n");
	printf("%u\n", end1 - begin1);

}
int main()
{
	int a[] = { 1, 3, 5, 9, 8, 7, 4, 6, 2 };
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	PrintSort(a, sizeof(a) / sizeof(int));


	TestSortOP();
	return 0;
}