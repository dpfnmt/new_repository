#include<iostream>

using namespace std;
#include <vector>
//void Printf(int* a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//}
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right) 
//		return;
//	int mid = left + ((right - left) >> 1);
//	// [left, mid]
//	// [mid+1, right]
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//}
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	_MergeSort(a, 0, n - 1, tmp);
//	// 这里假设处理了一些其他逻辑
//	vector<int> v(10000000, 10); //只能开这么大的内存了
//	//v.empty();
//	// ...
//	 //free(tmp);
//}
//
//int main()
//{
//	int a[5] = { 4, 5, 2, 3, 1 };
//	MergeSort(a, 5);
//	Printf(a, sizeof(a) / sizeof(int));
//	return 0;
//}

#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
	return 0;
}