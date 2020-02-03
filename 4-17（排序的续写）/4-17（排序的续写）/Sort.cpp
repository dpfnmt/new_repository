#include"Sort.h"
//插入排序

void Print(int* a, int n)
{
	int i = 0;
	for (i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
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
	int tmp = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i <= n - gap - 1; i++)
		{
			end = i;
			tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap; //间距是gap，每次比较的也是gap
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

//选择排序
void Swap(int* p1, int * p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelecSort(int* a, int n)
{
	//int i = 0;
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] >= a[max])//这里使用错了，直接用max了，导致程序直接崩了；哈哈
				max = i;
			if (a[i] < a[min])
				min = i;
		}

		Swap(&a[begin], &a[min]);

		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);//不加这句话，出来的是逆序，倒着遍历
		++begin;
		--end;
		//Print(a, n);
	}
}

//堆排序
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  //把这两句话写在了while语句中，初始化的数值不对，导致执行次数不对；
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child; //这里是++child,不是++里面的值，
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
	for (int i = (n - 2) / 2; i >= 0; --i)  //在这里写成了++i,导致程序崩了
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
//优点;算法效率非常的快，O（lgN）;

//冒泡排序

void BubbleSort(int* a, int n)
{
	int i = 0;
	int end = n;
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

void BubbleSort1(int* a, int n)
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

void TestSortOP1()
{
	const int n = 100000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[1];
	}

	size_t begin1 = clock();
	InsertSort(a1, n);
	size_t end1 = clock();

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();

	printf("%u\n", end1 - begin1);
	printf("%u\n", end2 - begin2);
}

void TestSortOP2()
{
	const int n = 100000;
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a3[i] = rand();
		a4[i] = a3[1];

	}

	size_t begin3 = clock();
	SelecSort(a3, n);
	size_t end3 = clock();

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();

	printf("%u\n", end3 - begin3);
	printf("%u\n", end4 - begin4);
}
int main()
{
	int a[] = { 1, 2, 5, 6, 9, 8, 7, 4, 3 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	//ShellSort(a, sizeof(a) / sizeof(int));
	//SelecSort(a, sizeof(a) / sizeof(int));
	//HeapSort(a, sizeof(a) / sizeof(int));
	 //BubbleSort(a, sizeof(a) / sizeof(int));
	 BubbleSort1(a, sizeof(a) / sizeof(int));

	 Print(a, sizeof(a) / sizeof(int));
	//TestSortOP1();//OP表示测试性能；
	//TestSortOP2();
	return 0;
}