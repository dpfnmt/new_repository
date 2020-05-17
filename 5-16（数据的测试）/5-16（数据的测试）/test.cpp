#include<iostream>
#include<math.h>
using namespace std;

void Swep(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void print(int*a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//冒泡排序

void Bubblesort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 0; i < end; i++)
		{
			//比较前一个比后一个大，
			if (a[i] > a[i + 1])
			{
				//进行交换
				Swep(&a[i], &a[i + 1]);

			}
		}
		--end;
	}
	
}


//快速排序
//思想;在数组中，首先找一个基准，然后通过这个基准，将数组划分为两个部分，一个是比这个基准小的
//部分，一个是比这个大的部分，然后通过递归的方式将这两个数组进行快速排序，知道划分为里面为0个
//或者一个元素为止
int partsort(int*a, int begin, int end)
{
	//找基准
	int key = begin;
	while (begin < end)
	{
		//当后一个元素比基准大的时候，后一个向前走一位
		while (begin < end && a[end] > a[key])
		--end;
		//当前一个元素比基准大的时候，后一个向后走一位
		while (begin < end && a[begin] > a[key])
		++begin;
		//当不满足的时候，前一个与后一个进行交换
		Swep(&a[begin], &a[end ]);
	}
	//将
	Swep(&a[begin], &a[key]);
	return end;
}

//三数取中法
//思想：还是快排的思想，解决的当这个基准不是最小或者虽大的时候.
int GetMidIndex(int *a, int begin, int end)
{
	int mid = begin + ((begin - end) >> 1);
	//当开始的值比中间值小的时候
	if (a[begin] < a[mid])
	{
		//中间值比后一位小，取中间
		if (a[mid] < a[end])
		{
			return mid;
		}
		//当中间一个大于最后一位
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
			return end;
	}
	//a[begin] > a[mid]
	else
	{
		//当中间一个大于最后一位
		 if (a[mid] > a[end])
		{
			return mid;
		}
		 //中间值比后一位小，取中间
		else if (a[begin] < a[end])
		 {
			 return begin;
		 }
		else
			return end;
	}
}
int partsort1(int*a, int begin, int end)
{
	//找基准，且不是最大或者最小值；
	int mid = GetMidIndex(a, begin, end);
	Swep(&a[begin], &a[mid]);
	int key = begin;
	while (begin < end)
	{
		//当后一个元素比基准大的时候，后一个向前走一位
		while (begin < end && a[end] > a[key])
			--end;
		//当前一个元素比基准大的时候，后一个向后走一位
		while (begin < end && a[begin] > a[key])
			++begin;
		//当不满足的时候，前一个与后一个进行交换
		Swep(&a[begin], &a[end]);
	}
	//将
	Swep(&a[begin], &a[key]);
	return end;
}
//挖坑法
//找一个基准mid,然后首先将这个值拿出来，留出空位，然后由左右开始找，begin找小的，end找大的

int partsort2(int* a, int begin, int end)
{
	int mid = a[begin];
	while (begin < end)
	{
		//找小
		while (begin<end && a[end]> mid)
			--end;
		a[begin] = a[end];
		//找大
		while (begin < end && a[begin] < mid)
			++begin;
		a[end] = a[begin];
	}
	a[begin] = mid;
	return begin;
}

//快速排序
//思想;在数组中，首先找一个基准，然后通过这个基准，将数组划分为两个部分，一个是比这个基准小的
//部分，一个是比这个大的部分，然后通过递归的方式将这两个数组进行快速排序，知道划分为里面为0个
//或者一个元素为止
void Quicsort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = partsort2(a, left, right);
	//使用递归的思想，将数组由基准划分为两个部分
	Quicsort(a, left, div - 1);
	Quicsort(a, div + 1, right);

}


//堆排序
//堆排序的思想是：简单排序需要n-1次进行排序，那是因为简单排序是重复的进行排序的，没有将之前的进行保留下来，
//但是堆排序，可以将之前的排序好的保留下来，将新的插入的数据用最少的时间和步骤，来进行调整

void AdJustDown(int*a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//左孩子比右孩子大，继续向下走
		if (child+1 < n &&a[child + 1]>a[child])
		{
			++child;
		}
		//孩子比父亲大
		if (a[child] > a[parent])
		{
			Swep(&a[child], &a[parent]);
			parent = child;
		    child = parent * 2 + 1;
			//parent = child
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdJustDown(a, n, i);
	}
	//调整,因为最大的数在堆顶，下乡调整
	int end = n - 1;
	while (end > 0)
	{
		Swep(&a[0], &a[end]);
		AdJustDown(a, end, 0);
		--end;
	}

}

//插入排序
//就是一个一个插入
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int  tmp = a[end + 1];
		while (end >= 0)
		{
			//前一个元素比后一个大，进行交换
			if (a[end] > tmp)
			{
				//把前一个元素给后一个元素
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//进行交换之后，把之前的位置还是给后面这个位置进行交换
		a[end + 1] = tmp;
	}
}

//希尔排序
//希尔排序的思想：设一个组距grep,然后按照这个组距进行交换，再将组距缩小，然后在进行排序，直到组距为1的时候
//，排序结束

void Shellsort(int* a, int n)
{
	//设置组距
	int grep = n;
	while (grep > 1)
	{
		//设置相同的组距
		grep = grep / 3 + 1;
		//进行组距间的循环
		for (int i = 0; i <= n - grep - 1; i++)
		{
			int end = i;
			int tmp = a[end + grep];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + grep] = a[end];
					end -= grep;
				}
				else
				{
					break;
				}
			}
			a[end + grep] = tmp;

		}
	}
}
int main()
{
	int a[] = { 1, 5, 8, 3, 9, 2, 6, 4, 7 };
	//Bubblesort(a, sizeof(a) / sizeof(int));
	//Quicsort(a, 0, sizeof(a) / sizeof(int)-1);
	//HeapSort(a, sizeof(a) / sizeof(int));
	//HeapSort(a, sizeof(a) / sizeof(int));
	//InsertSort(a, sizeof(a) / sizeof(int));
	Shellsort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int));
	return 0;
}


