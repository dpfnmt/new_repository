#include<stdio.h>

/*
排序		时间复杂度	空间复杂度   稳定性	     特点
冒泡排序	O(N^2)		O(1)		 稳定
快排		O(N*logN)	O(logN)		不稳定
直接插入	O(N^2)		O(1)		 稳定		元素有序，排序越快
希尔排序   O(N^1.3~N^2)			    不稳定		是直接排序的一种优算排序
直接选择排序 O(N^2)		O(1)		不稳定      很好理解，但是效率不是很高
堆排序      O(N*logN)   O(1)		不稳定		效率很快
*/


void print(int*a, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swep(int*p1, int *p2)
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
		if(child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swep(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a,int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//最大的值已近在堆顶了，向下重新走一边
	int end = n - 1;
	while (end > 0)
	{
		Swep(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubblkeSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swep(&a[i], &a[i + 1]);
			}	
		}
		--end;

	}
}

int partsort(int *a, int begin, int end)
{
	//找到一个关键值
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
			--end;
		while (begin < end && a[begin] <= a[key])
			++begin;
		Swep(&a[begin], &a[end]);
	}
	Swep(&a[begin],&a[key]);
	return end;
}
//快速排序
void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
		return;
	//找到这个基准，将数组元素划分位两部分
	int div = partsort(a, begin, end);
	QuickSort(a, begin, div - 1);
	QuickSort(a, div + 1,end);

}
int main()
{
	int a[] = { 1, 5, 3, 7, 6, 2, 4, 0, 8, 9 };
	//HeapSort(a, sizeof(a) / sizeof(int));
	//BubblkeSort(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	print(a, sizeof(a) / sizeof(int));
	return 0;
}