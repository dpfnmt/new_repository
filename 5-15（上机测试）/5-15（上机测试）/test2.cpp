//求最大公约数

#include"test4.h"

void main()
{
	int k, n;
	long a, b, c, r, m[100];
	printf("请输入整数n: ");
	scanf("%d", &n);
	printf("请依次输入%d个整数 ",n);
	for (k = 0; k <= n - 1; k++)
	{
		printf("\n请输入%d个整数： ", k + 1);
		scanf("%ld", &m[k]);
	}
	b = m[0];
	for (k = 1; k <= n - 1; k++)
	{
		a = m[k];
		if (a < b)
		{
			c = a; a = b; b = c;
		}
		r = a%b;
		while (r != 0)
		{
			a = b; b = r;
			r = a%b;
		}
	}
	printf("%ld ", m[0]);
	for (k = 1; k <= n - 1; k++)
		printf(",%ld", m[k]);
	printf(" = %ld\n",b);
}