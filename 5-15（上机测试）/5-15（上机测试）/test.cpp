//求最大公约数

#include<stdio.h>
//调用函数
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
//主程序
void main()
{
	int k, n;
	long x, y, m[100];
	printf("请输入整数个数n: ");
	scanf("%d", &n);
	printf("请依次输入%d个数。",n);
	for (k = 0; k <= n - 1; k++)
	{
		printf("请输入%个整数。",k + 1);
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