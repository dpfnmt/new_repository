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
//ð������

void Bubblesort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 0; i < end; i++)
		{
			//�Ƚ�ǰһ���Ⱥ�һ����
			if (a[i] > a[i + 1])
			{
				//���н���
				Swep(&a[i], &a[i + 1]);

			}
		}
		--end;
	}
	
}


//��������
//˼��;�������У�������һ����׼��Ȼ��ͨ�������׼�������黮��Ϊ�������֣�һ���Ǳ������׼С��
//���֣�һ���Ǳ������Ĳ��֣�Ȼ��ͨ���ݹ�ķ�ʽ��������������п�������֪������Ϊ����Ϊ0��
//����һ��Ԫ��Ϊֹ
int partsort(int*a, int begin, int end)
{
	//�һ�׼
	int key = begin;
	while (begin < end)
	{
		//����һ��Ԫ�رȻ�׼���ʱ�򣬺�һ����ǰ��һλ
		while (begin < end && a[end] > a[key])
		--end;
		//��ǰһ��Ԫ�رȻ�׼���ʱ�򣬺�һ�������һλ
		while (begin < end && a[begin] > a[key])
		++begin;
		//���������ʱ��ǰһ�����һ�����н���
		Swep(&a[begin], &a[end ]);
	}
	//��
	Swep(&a[begin], &a[key]);
	return end;
}

//����ȡ�з�
//˼�룺���ǿ��ŵ�˼�룬����ĵ������׼������С��������ʱ��.
int GetMidIndex(int *a, int begin, int end)
{
	int mid = begin + ((begin - end) >> 1);
	//����ʼ��ֵ���м�ֵС��ʱ��
	if (a[begin] < a[mid])
	{
		//�м�ֵ�Ⱥ�һλС��ȡ�м�
		if (a[mid] < a[end])
		{
			return mid;
		}
		//���м�һ���������һλ
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
		//���м�һ���������һλ
		 if (a[mid] > a[end])
		{
			return mid;
		}
		 //�м�ֵ�Ⱥ�һλС��ȡ�м�
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
	//�һ�׼���Ҳ�����������Сֵ��
	int mid = GetMidIndex(a, begin, end);
	Swep(&a[begin], &a[mid]);
	int key = begin;
	while (begin < end)
	{
		//����һ��Ԫ�رȻ�׼���ʱ�򣬺�һ����ǰ��һλ
		while (begin < end && a[end] > a[key])
			--end;
		//��ǰһ��Ԫ�رȻ�׼���ʱ�򣬺�һ�������һλ
		while (begin < end && a[begin] > a[key])
			++begin;
		//���������ʱ��ǰһ�����һ�����н���
		Swep(&a[begin], &a[end]);
	}
	//��
	Swep(&a[begin], &a[key]);
	return end;
}
//�ڿӷ�
//��һ����׼mid,Ȼ�����Ƚ����ֵ�ó�����������λ��Ȼ�������ҿ�ʼ�ң�begin��С�ģ�end�Ҵ��

int partsort2(int* a, int begin, int end)
{
	int mid = a[begin];
	while (begin < end)
	{
		//��С
		while (begin<end && a[end]> mid)
			--end;
		a[begin] = a[end];
		//�Ҵ�
		while (begin < end && a[begin] < mid)
			++begin;
		a[end] = a[begin];
	}
	a[begin] = mid;
	return begin;
}

//��������
//˼��;�������У�������һ����׼��Ȼ��ͨ�������׼�������黮��Ϊ�������֣�һ���Ǳ������׼С��
//���֣�һ���Ǳ������Ĳ��֣�Ȼ��ͨ���ݹ�ķ�ʽ��������������п�������֪������Ϊ����Ϊ0��
//����һ��Ԫ��Ϊֹ
void Quicsort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = partsort2(a, left, right);
	//ʹ�õݹ��˼�룬�������ɻ�׼����Ϊ��������
	Quicsort(a, left, div - 1);
	Quicsort(a, div + 1, right);

}


//������
//�������˼���ǣ���������Ҫn-1�ν�������������Ϊ���������ظ��Ľ�������ģ�û�н�֮ǰ�Ľ��б���������
//���Ƕ����򣬿��Խ�֮ǰ������õı������������µĲ�������������ٵ�ʱ��Ͳ��裬�����е���

void AdJustDown(int*a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//���ӱ��Һ��Ӵ󣬼���������
		if (child+1 < n &&a[child + 1]>a[child])
		{
			++child;
		}
		//���ӱȸ��״�
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
	//����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdJustDown(a, n, i);
	}
	//����,��Ϊ�������ڶѶ����������
	int end = n - 1;
	while (end > 0)
	{
		Swep(&a[0], &a[end]);
		AdJustDown(a, end, 0);
		--end;
	}

}

//��������
//����һ��һ������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int  tmp = a[end + 1];
		while (end >= 0)
		{
			//ǰһ��Ԫ�رȺ�һ���󣬽��н���
			if (a[end] > tmp)
			{
				//��ǰһ��Ԫ�ظ���һ��Ԫ��
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//���н���֮�󣬰�֮ǰ��λ�û��Ǹ��������λ�ý��н���
		a[end + 1] = tmp;
	}
}

//ϣ������
//ϣ�������˼�룺��һ�����grep,Ȼ������������н������ٽ������С��Ȼ���ڽ�������ֱ�����Ϊ1��ʱ��
//���������

void Shellsort(int* a, int n)
{
	//�������
	int grep = n;
	while (grep > 1)
	{
		//������ͬ�����
		grep = grep / 3 + 1;
		//���������ѭ��
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


