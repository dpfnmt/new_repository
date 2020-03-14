#include<iostream>
#include <vector>

#define max 100

struct Listnode {

	int data;
	int cur;
};

std::vector<Listnode> list;

//初始化链表
void InitList(std::vector<Listnode>& list)
{
	list.resize(max);
	list[max - 1].cur = 0;
	for (int i = 0; i < max - 2; i++)
	{
		list[i].cur = i + 1;
	}
	list[max - 2].cur = 0;
}

//求静态链表中元素个数，不包括头尾节点
int ListLength(std::vector<Listnode>& list)
{
	int i = list[max - 1].cur;
	int j = 0;
	while (i)
	{
		j++;
		i = list[i].cur;
	}
	return j;
}

//插入元素时，分配空间的下标
int Malloc(std::vector<Listnode>& list)
{
	int i = list[0].cur;
	if (i)
		list[0].cur = list[i].cur;
	return i;
}

//插入元素
bool ListInsert(std::vector<Listnode>& list, int i, int key)
{
	if (i < 1 || i > ListLength(list) + 1)
	{
		return false;
	}
	int j = Malloc(list);
	int k = max - 1;
	if (j)
	{
		for (int l = i; l <= j - 1; l++)
		{
			k = list[k].cur;
		}
		list[j].data = key;
		list[j].cur = list[k].cur;
		list[k].cur = j;
		return true;
	}
}


//删除第i个元素,key值改变
bool ListDelete(std::vector<Listnode>& list, int i, int* key)
{
	if (i < 1 || i >= ListLength(list))
	{
		return false;
	}
	int k = max - 1;
	for (int l = 1; l <= i - 1; l++)
		k = list[k].cur;
	int j = list[k].cur;
	*key = list[j].data;
	list[k].cur = list[j].cur;
	list[j].cur = list[0].cur;
	list[0].cur = j;
	return true;
}

//查找key
int ListSearch(std::vector<Listnode>list, int key)
{
	int i = list[max - 1].cur;
	while (list[i].data == key)
	{
		i = list[i].cur;
	}
	return i;
}

//遍历
void ListPrint(std::vector<Listnode>& list)
{
	int k = max - 1;
	while (list[k].cur)
	{
		k = list[k].cur;
		std::cout << (list[k]).data << '\t';
	}
	printf("\n");
}

//测试
int main()
{
	InitList(list);
	std::cout << "插入的所有元素值是: "<< std::endl;
	ListInsert(list, 1, 1);
	ListInsert(list, 1, 2);
	ListInsert(list, 1, 3);
	ListInsert(list, 1, 4);
	ListInsert(list, 1, 5);
	ListPrint(list);
	std::cout << std::endl;
	int key;
	ListDelete(list, 2, &key);
	std::cout << "删除的元素值是: " << key << std::endl;
	ListPrint(list);

	return 0;
}

