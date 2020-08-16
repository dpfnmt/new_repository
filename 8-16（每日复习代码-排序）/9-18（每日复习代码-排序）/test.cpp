#include<iostream>
using namespace std;

void print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
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

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//¶ÑÅÅÐò
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//Ã°ÅÝÅÅÐò
void BulleSort(int* a, int n)
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		for (i = 0; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
		--end;
	}
}

int PartSort(int*a, int begin, int end)
{
	int key = begin;
	while (begin < end)
	{
		if (begin < end && a[end] > a[key])
		{
			--end;
		}
		if (begin < end && a[begin] < a[key])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);

	return end;
}

int PartSort2(int*a, int begin, int end)
{
	int mid = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= mid)
			--end;
		a[begin] = a[end];

		while (begin < end && a[begin] <= mid)
			++begin;
		a[end] = a[begin];
	}
	a[begin] = mid;

	return end;
}
void QuickSort(int* a, int left, int right)
{
	if (left > right)
		return;
	//int div = PartSort(a, left, right);
	int div = PartSort2(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

int main()
{
	int a[] = { 5, 6, 7, 4, 2, 0, 9, 8, 1, 3 };
	//HeapSort(a, sizeof(a) / sizeof(int));
	//BulleSort(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	print(a, sizeof(a) / sizeof(int));
	return 0;
}