//�����Լ��

#include<stdio.h>
//���ú���
long gcb(long a, long b)
{
	long c,r;
	if (a<b)
	{
		c = a; a = b; b = c;
	}
	r = a%b;
	while (r != 0)
	{
		a = b; b = r;
		r = a%b;
	}
	return b;
}
//������
void main()
{
	int k, n;
	long x, y, m[100];
	printf("��������������n: ");
	scanf("%d", &n);
	printf("����������%d������",n);
	for (k = 0; k <= n - 1; k++)
	{
		printf("������%��������",k + 1);
		scanf("%ld", &m[k]);
	}
	x = m[0];
	for (k = 1; k <= n - 1; k++)
	{
		y = m[k];
		x = gcb(x, y);
	}
		printf(",%ld", m[0]);
		for (k = 1; k <= n - 1; k++)
			printf(",%ld", m[k]);
		printf("=%ld\n", x);
}