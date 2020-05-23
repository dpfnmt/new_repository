//#include<stdio.h>
//
//using namespace std;
//
//void print(int* a, int n)
//{
//	for (int i = 0; i <= n - 1; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//void Swep(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
////ð������
//void BubbleSort(int* a, int n)
//{
//	int end = n - 1;
//	while (end>0)
//	{
//		for (int i = 0; i < end; i++)
//		{
//			if (a[i] > a[i + 1])
//			{
//				Swep(&a[i], &a[i + 1]);
//			}
//		}
//		--end;
//	}
//}
//
////��������
//
//int partsort(int*a, int begin, int end)
//{
//	int key = begin;
//	while (begin < end)
//	{
//		while (begin<end && a[end] > a[key])
//			--end;
//		while (begin<end && a[begin] > a[key])
//			++begin;
//		Swep(&a[begin], &a[end]);
//	}
//	Swep(&a[begin], &a[key]);
//	return end;
//}
//
////����ȥȡ�з�
//int GetMidIndix(int*a, int begin, int end)
//{
//	int mid = begin + ((begin - end) >> 1);
//	if (begin < mid)
//	{
//		if (a[mid] < a[end])
//		{
//			return mid;
//		}
//		if (a[begin] > a[mid])
//		{
//			return begin;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	else
//	{
//		if (a[begin] < a[end])
//		{
//			return begin;
//		}
//		if (a[mid] > a[end])
//		{
//			return mid;
//		}
//		else
//		{
//			return end;
//		}
//	}
//}
//int partsort1(int*a, int begin, int end)
//{
//	int key = GetMidIndix(a,begin,end);
//	while (begin < end)
//	{
//		while (begin<end && a[end] > a[key])
//			--end;
//		while (begin<end && a[begin] > a[key])
//			++begin;
//		Swep(&a[begin], &a[end]);
//	}
//	Swep(&a[begin], &a[key]);
//	return end;
//}
////�ڿӷ�
//int partsort2(int*a, int begin, int end)
//{
//	int mid = a[begin];
//	while (begin < end)
//	{
//		while (begin < end && a[end] > mid)
//			--end;
//		a[begin] = a[end];
//		while (begin<end && a[begin] < mid)
//			++begin;
//		a[end] = a[begin];
//	}
//	a[begin]= mid;
//	return begin;
//}
//void  QuickSort(int* a, int left, int right)
//{
//	if (left > right)
//		return;
//	int div = partsort2(a, left, right);
//	QuickSort(a, left, div - 1);
//	QuickSort(a, div + 1, right);
//}
//
////����
//void AdJustDown(int *a, int  n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child + 1] > a[child])
//			++child;
//		if (a[child] > a[parent])
//		{
//			Swep(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int*a, int n)
//{
//	//����
//	for (int i = (n-2)/2; i >= 0; --i)
//	{
//		AdJustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swep(&a[0], &a[end]);
//		AdJustDown(a, end,0);
//		--end;
//	}
//}
//
////��������
//void InsertSort(int*a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
////ϣ������
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n - gap - 1; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//int main()
//{
//	int a[] = { 1, 4, 2, 5, 3, 7, 0, 8, 6, 9 };
//	//BubbleSort(a, sizeof(a) / sizeof(int));
//	//QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
//	//HeapSort(a, sizeof(a) / sizeof(int));
//	//InsertSort(a, sizeof(a) / sizeof(int));
//	ShellSort(a, sizeof(a) / sizeof(int));
//	print(a, sizeof(a) / sizeof(int));
//	return 0;
//}



//ջʵ�ֶ���
//����ʵ��ջ
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

//  *******����ջʵ��һ������********
typedef int ElemType;
typedef struct {
	stack<ElemType>s1;  //���������
	stack<ElemType>s2;  //���������
}SQueue;

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(SQueue &q) {
	if ((q.s1.empty()) && (q.s2.empty())) {
		return true;
	}
	return false;
}

// �����
void EnQueue(SQueue &q, ElemType e) {
	q.s1.push(e);
}

//  ���д�С
int GetQueueSize(SQueue &q) {
	return q.s1.size() + q.s2.size();
}

//������
void DeQueue(SQueue &q) {
	if (q.s2.empty()) {
		while (!q.s1.empty()) {
			q.s2.push(q.s1.top());
			q.s1.pop();
		}
	}
	if (!q.s2.empty()) {  //�ӿ�
		q.s2.pop();  //������
	}
}

//  ȡ������Ԫ��
ElemType GetFront(SQueue &q) {
	if (q.s2.empty()) {
		while (!q.s1.empty()) {
			q.s2.push(q.s1.top());
			q.s1.pop();
		}
	}
	if (q.s2.empty()) {  //�ӿ�
		throw;
	}
	return q.s2.top();
}

int main() {
	SQueue sq;
	EnQueue(sq, 1);
	EnQueue(sq, 2);
	EnQueue(sq, 3);
	EnQueue(sq, 4);
	EnQueue(sq, 5);
	EnQueue(sq, 6);
	cout << GetFront(sq) << endl;
	DeQueue(sq);

	
	cout << GetFront(sq) << endl;
	//DeQueue(sq);
	//cout << GetFront(sq) << endl;
	//DeQueue(sq);
	//cout << GetFront(sq) << endl;
	//cout << GetFront(sq) << endl;

	cout << GetQueueSize(sq) << endl;
	return 0;
}

//#if 1
//  ****��������ʵ��һ��ջ****
//typedef int ElemType;
//typedef struct {
//	queue<ElemType>q1;  //���
//	queue<ElemType>q2;  //��ת
//}QStack;
//
//// ջ�Ƿ�Ϊ��
//bool IsEmpty(QStack s) {
//	if (s.q1.empty()) {
//		return true;
//	}
//	return false;
//}
//
//// ջ��С
//int GetStackSize(QStack s) {
//	return s.q1.size();
//}
////ѹջ
//void Push(QStack &s, ElemType e) {
//	s.q1.push(e);
//}
//
////��ջ
//void Pop(QStack &s) {
//	if (!s.q1.empty()) {
//		while (s.q1.size() != 1) {  //����q1��n-1��Ԫ���ƶ���q2
//			s.q2.push(s.q1.front());
//			s.q1.pop();
//		}
//		s.q1.pop();
//		while (!s.q2.empty()) {
//			s.q1.push(s.q2.front());
//			s.q2.pop();
//		}
//	}
//}
//
////ȡջ��Ԫ��
//int Top(QStack &s) {
//	if (s.q1.empty()) {
//		throw;  //ջ��
//	}
//	while (!s.q1.empty()) {  //����q1��n��Ԫ���ƶ���q2
//		s.q2.push(s.q1.front());
//		s.q1.pop();
//	}
//	ElemType tmp = s.q2.back();  //��ȡ��n��Ԫ��
//	while (!s.q2.empty()) {
//		s.q1.push(s.q2.front());
//		s.q2.pop();
//	}
//	return tmp;
//}
//
//int main() {
//	QStack qs;
//	Push(qs, 1);
//	Push(qs, 2);
//	Push(qs, 3);
//	Push(qs, 4);
//	try {
//		cout << Top(qs) << endl;
//		Pop(qs);
//		cout << Top(qs) << endl;
//		Pop(qs);
//		cout << Top(qs) << endl;
//		Pop(qs);
//		cout << Top(qs) << endl;
//		Pop(qs);
//		cout << "size:" << GetStackSize(qs) << endl;
//	}
//	catch (...) {
//
//	}
//	if (IsEmpty(qs)) {
//		cout << "ջ��" << endl;
//	}
//	else {
//		cout << "ջ�ǿ�" << endl;
//	}
//	return 0;
//}
//#endif // 1

