#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	if (buckets == 1)
	{
		return 0;
	}
	int count = minutesToTest / minutesToDie + 1;  //�ܲ��Լ���
	int sum = 1;              //�������
	int num = count;          //�ܹ����Լ�����
	while (num < buckets) {
		num *= count;
		sum++;
	}

	return sum;

}

int main()
{

	int a = poorPigs(1000, 60, 60);
	printf("%d\n", a);
	system("pause");
	return 0;
}