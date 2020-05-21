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
		//�������С�����ڵĺ��ӣ����Һ�һ����ǰһ����
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//������ӱȸ��״�
		if (a[child] > a[parent])
		{
			//���н���
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
	//����
	for (int i = (n - 2)/2; i>= 0 ; --i)
	{
		AdjustDown(a, n, i);
	}
	//���ڴ�������ѽ��ڶѶ��ˣ��������µ���
	int end = n - 1;
	while (end > 0)
	{
		//�����һ��Ԫ�ؿ�ʼ���Ͻ��н���
		Swep(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//ð������
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

//����
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
int partsort1(int* a, int left, int right) //����ȡ�з�
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
	//�ҵ�һ���ؼ�
	int key = begin;
	while (begin < end)
	{
		//�����һ��Ԫ�رȹؼ�ֵ���ʱ��������һλ
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		//����һ��Ԫ�رȹؼ�ֵ���ʱ��������һλ
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}
		//�������ʱ�����߽���
		Swep(&a[begin], &a[end]);
	}
	Swep(&a[key], &a[end]);
	return end;
}

void QuickSort(int *a, int left ,int right)
{
	//�������Ϊ��
	if (left > right)
		return;
	//�ҵ������׼
	int div = partsort1(a, left, right);
	//�ݹ�
	//�������ݹ�
	QuickSort(a, left, div - 1);
	//�������ݹ�
	QuickSort(a, div + 1,right);
}

//��������

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

//ϣ������

void ShellSort(int *a, int n)
{
	//����һ�����
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //ÿ��ȡ��ͬ��λ��
		for (int i = 0; i <= n - gap - 1; i++) //��������Ҫ�������һ�Σ�ʹ�����һ�������
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap; //ÿһ�ζ��ǰ�����ͬ���������ж�
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