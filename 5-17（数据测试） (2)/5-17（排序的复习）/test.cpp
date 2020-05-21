#include<stdio.h>

void print(int*a, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swep(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//如果孩子小于现在的孩子，并且后一个比前一个大
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//如果孩子比父亲大
		if (a[child] > a[parent])
		{
			//进行交换
			Swep(&a[parent], &a[child]);
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
	//建堆
	for (int i = (n - 2)/2; i>= 0 ; --i)
	{
		AdjustDown(a, n, i);
	}
	//现在大的数据已近在堆顶了，现在向下调整
	int end = n - 1;
	while (end > 0)
	{
		//由最后一个元素开始向上进行交换
		Swep(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int*a, int n)
{
	int end = n -1;
	while (end > 0)
	{
		int chang = 0;
		for (int i = 0; i <= end; i++)
		{
			if (a[i-1] > a[i])
			{
				chang = 1;
				Swep(&a[i-1], &a[i]);
			}
		}
		if (chang == 0)
		{
			break;
		}
		--end;
	}
}

//快排
int GetMidIndex(int *a, int begin, int end)
{
	int mid = begin + ((begin - end) >> 1);
	if(a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return a[mid];
		}
		else if (a[begin] > a[end])
		{
			return a[begin];
		}
		else
		{
			return a[end];
		}
	}
	//a[begin] > a[mid]
	else
	{
		if (a[mid] > a[end])
		{
			return a[mid];
		}
		else if (a[begin] < a[end])
		{
			return a[begin];
		}
		else
		{
			return a[end];
		}
	}
	return end;
}
int partsort1(int* a, int left, int right) //三数取中法
{
	int mid = GetMidIndex(a, left, right);
	Swep(&a[left], &a[mid]);
    int key = left;
	while (left < right)
	{
		while (left < right && a[right] > a[key])
			--right;
		while (left < right && a[left] < a[key])
			++left;
		Swep(&a[left], &a[right]);
	}
	Swep(&a[left], &a[key]);
	return right;
}

int partsort(int *a, int begin, int end)
{
	//找到一个关键
	int key = begin;
	while (begin < end)
	{
		//当最后一个元素比关键值大的时候。向左走一位
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		//当第一个元素比关键值大的时候，向右走一位
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		//不满足的时候，两者交换
		Swep(&a[begin], &a[end]);
	}
	Swep(&a[key], &a[end]);
	return end;
}

void QuickSort(int *a, int left ,int right)
{
	//如果数组为空
	if (left > right)
		return;
	//找到这个基准
	int div = partsort1(a, left, right);
	//递归
	//左子树递归
	QuickSort(a, left, div - 1);
	//右子树递归
	QuickSort(a, div + 1,right);
}

//插入排序

void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
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

void ShellSort(int *a, int n)
{
	//设置一个组距
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //每次取相同的位置
		for (int i = 0; i <= n - gap - 1; i++) //在这里需要排序最后一次，使得最后一次在相等
		{
			int end = i;
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

void  InsertSort1(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end > 0)
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
			a[end + 1] = tmp;
		}
	}
}
int main()
{
	int a[] = { 1, 3, 5, 2, 4, 7, 9, 6, 8 };
	//HeapSort(a, sizeof(a) / sizeof(int));
	//BubbleSort(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0,sizeof(a) / sizeof(int)-1);
	//InsertSort1(a, sizeof(a) / sizeof(int));
	//ShellSort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int));
	return 0;
}