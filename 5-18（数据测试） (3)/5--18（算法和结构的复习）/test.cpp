#include<stdio.h>

/*
����		ʱ�临�Ӷ�	�ռ临�Ӷ�   �ȶ���	     �ص�
ð������	O(N^2)		O(1)		 �ȶ�
����		O(N*logN)	O(logN)		���ȶ�
ֱ�Ӳ���	O(N^2)		O(1)		 �ȶ�		Ԫ����������Խ��
ϣ������   O(N^1.3~N^2)			    ���ȶ�		��ֱ�������һ����������
ֱ��ѡ������ O(N^2)		O(1)		���ȶ�      �ܺ���⣬����Ч�ʲ��Ǻܸ�
������      O(N*logN)   O(1)		���ȶ�		Ч�ʺܿ�
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
	//����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//����ֵ�ѽ��ڶѶ��ˣ�����������һ��
	int end = n - 1;
	while (end > 0)
	{
		Swep(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//ð������
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
	//�ҵ�һ���ؼ�ֵ
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
//��������
void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
		return;
	//�ҵ������׼��������Ԫ�ػ���λ������
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