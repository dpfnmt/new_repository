#include"Heap.h"

void AdjustDown(HPDataType* a, size_t n, int root)
{
	//调整使其成为小堆
	assert(a);
	//找左右孩子小的那个
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	//通过向下调整使其成为小堆
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_size = hp->_capacity = 0;
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void AdjustUp(HPDataType*a, size_t n, size_t child)//向上调整
{
	assert(a);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{

		if (a[child] < a[parent])
		{
			//交换child和parent
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}


void HeapPush(Heap* hp, HPDataType x)//插入数据是在末尾插入
{
	assert(hp);
	if (hp->_size == hp->_capacity)//判断数组空间是否已满
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity*sizeof(HPDataType));//增容
		assert(hp->_array);//判断增容是否失败
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	//调堆 向上调

	AdjustUp(hp->_array , hp->_size, hp->_size - 1);

}

void Swap(HPDataType* p1, HPDataType*p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}

int HeapSize(Heap* hp)
{
	if (hp == NULL){
		return 0;
	}
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	if (hp == NULL){
		return 0;
	}
	return hp->_size == 0 ? 1 : 0;
}

//堆排序
void HeapSort(HPDataType*a, size_t n)
{
	//建小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	size_t end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	Heap hp;
	int a[] = { 1, 4, 3, 6, 5, 2, 9, 7, 8 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 15);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(a,sizeof(a)/sizeof(a[0]));
	HeapPrint(&hp);

	HeapSize(&hp);
	HeapPrint(&hp);

	HeapEmpty(&hp);
	HeapPrint(&hp);

	return 0;
}