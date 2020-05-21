#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
//int main()
//{
//	//首先创建两个数组
//	std::string s1 = "hello world";
//	std::vector<string> v;
//
//	int though = s1.size();
//	for (int i = 0; i < though - 1; i++)
//	{
//		if (v[i] != ' ' && v[i + 1] != '\0')
//		{
//
//		}
//	}
//	return 0;
//}


//s1 s2
//struct ListNode{
//	int val;
//	struct ListNode * next;
//};
//
//struct ListNode*  hanshu(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL && l2 == NULL)
//		return;
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	struct ListNode* head;
//	struct ListNode* p;
//
//	if (l1->val < l2->val)
//	{
//		head = p = l1;
//		l1 = l1->next;
//	}
//	else
//	{
//		head = p = l2;
//		l2 = l2->next;
//	}
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			p->next = l1;
//			l1 = l1->next;
//		}
//		else
//		{
//			p->next = l2;
//			l2 = l2->next;
//		}
//		p = p->next;
//	}
//	if (l1 == NULL)
//	{
//		p->next = l2;
//	}
//	else
//	{
//		p->next = l1;
//	}
//	return head;
//}


int main()
{
	char a[1000];
	scanf("%s", a);
	int l = strlen(a);//获取字符串长度
	int temp;//定义中变量 
	for (int i = 0; i < l / 2; i++)
	{//中间对折,两边调换 
		temp = a[i];
		a[i] = a[l - i - 1];
		a[l - i - 1] = temp;
	}
	puts(a);

	return 0;
}