#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(int* a, int n)
{
	    int i = 0;
	    int end = n ;
		while (end > 0)
		{
			for (i = 1; i <= end - 1; i++)
			{
				if (a[i - 1] > a[i])
				{
					Swap(&a[i - 1], &a[i]);

				}
		     }
			--end;
	    }
}
void BubbleSort2(int* a, int n) //冒泡排序
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		int change = 0;
		for (i = 1; i <= end - 1; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				change = 1;
			}
		}
		if (change = 0)
		{
			break;
		}
		--end;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child + 1] > a[child])
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
void HeapSort(int* a, int n)  //堆排序
{
	for (int i = (n-2)/2; i >=0 ;-- i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0) //这里判断的是end大于0；
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//第一种排序
int PartSort(int* a, int begin, int end)   //让右边先走，相遇的时候，为小，然后在与基准值交换
{
	int key = begin;
	while (begin < end)
	{
		//找小
		while (begin < end && a[end] >= a[key])
			--end;
	    //找大
		while (begin < end && a[begin] <= a[key])
			++begin; 
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);
	return end;
}

int PartSort1(int* a, int begin, int end)
{
	int tmp = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= tmp) //这里是tmp,不是a[tmp];
			--end;
			a[begin] = a[end];
		while (begin < end && a[begin] <= tmp)
			++begin;
			a[end] = a[begin];
	}
	a[begin] = tmp;
	return begin;
}

int PartSort2(int* a, int begin, int end)
{
	int cout = begin;
	int key = begin;
	int prev = begin;
    
}
void QuickSort(int*a, int left, int right)
{
	int div = 0;
	if (left > right)
		return;
	div = PartSort1(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1,right);

}

void PrintSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 3, 4, 6, 8, 7, 2, 1, 9, 0, 5 };
	//BubbleSort2(a, sizeof(a) / sizeof(int));
	//HeapSort(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);

	PrintSort(a, sizeof(a) / sizeof(int));
}