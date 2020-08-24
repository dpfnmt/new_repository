#include<iostream>
using namespace std;

/*
排序		时间复杂度	空间复杂度   稳定性	     特点
冒泡排序	O(N^2)		O(1)		 稳定
快排		O(N*logN)	O(logN)		 不稳定
直接插入	O(N^2)		O(1)		稳定		元素有序，排序越快
希尔排序   O(N^1.3~N^2)			不稳定		是直接排序的一种优算排序
直接选择排序 O(N^2)		O(1)		不稳定      很好理解，但是效率不是很高
堆排序      O(N*logN)   O(1)		不稳定		效率很快
*/

int print(int* a, int n)
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
//冒泡排序的第一种算法
void BubbleSort(int*a, int n)
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
		end--;
	}
}

//冒泡排序的第二种快速排序
void BubbleSort1(int*a, int n)
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		int chang = 0;
		for (i = 0; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				int chang = 1;
				Swap(&a[i - 1], &a[i]);
			}
		}
		if (chang = 0)
		{
			break;
		}
		end--;
	}
}

//快排的第一种解法，查找关键字
int Partsort(int* a, int begin, int end)
{
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);

	return end;
}

//快排的第二种解法，三数取中法

int GetMidIndix(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[mid] < a[begin])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	if (a[mid] > a[begin])
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
int Partsort2(int* a, int begin, int end)
{
	int mid = GetMidIndix(a, begin, end);
	Swap(&a[begin], &a[mid]);
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);

	return end;
}

//快排的第三种排序——挖坑法
int Partsort3(int* a, int begin, int end)
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

//快排的第四种排序——左右指针法

int Partsort4(int* a, int begin, int end)
{
	int key = begin;
	int cur = begin + 1;
	int prev = begin;
	while (cur <= end)
	{
		if (a[cur] <= a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[key], &a[prev]);
	return key;
}
//快速排序
void QuickSort(int*a, int left, int right)
{
	if (left >= right)
		return;

	//int div = Partsort(a, left, right);
	//int div = Partsort2(a, left, right);
	//int div = Partsort3(a, left, right);
	int div = Partsort4(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

//插入排序

void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int i = 0;
	int gap = n;
	int end = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //每次取相同的位置
		for (i = 0; i <= n - gap - 1; i++) //在这里需要排序最后一次，使得最后一次在相等
		{
			end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap; //每一次都是按照相同的组距进行判断
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//选择的直接排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
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
		Swap(&a[end], &a[max]); //这里写错了，写成了begin，有点失败
		++begin;
		--end;
		print(a, n);
	}
}

//选择排序——堆排序
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) //这里将n写成了child
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
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);//调整
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
int main()
{
	int a[] = { 2, 5, 7, 9, 1, 3, 6, 8, 0, 4 };
	//BubbleSort(a, sizeof(a)/sizeof(int));
	//BubbleSort1(a, sizeof(a) / sizeof(int));
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	//InsertSort(a, sizeof(a) / sizeof(int));
	//ShellSort(a, sizeof(a) / sizeof(int));
	//SelectSort(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int));
	return 0;
}