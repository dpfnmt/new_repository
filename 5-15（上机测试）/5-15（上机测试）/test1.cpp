//#include<stdio.h>
//
//void main()
//{
//	int g, i, k, s, a[10];
//	long m1, m2, m3;
//	i = 1; a[1] = 1; s = 0;
//	while (1)
//	{
//		g = 1;
//		for (k = i - 1; k >= 1; k--)
//		if (a[i] == a[k]) { g = 0; break; }
//		if (i == 9 && g == 1 && a[1]<a[4])
//		{
//			m1 = a[2] * 10 + a[3];
//			m2 = a[5] * 10 + a[6];
//			m3 = a[8] * 10 + a[9];
//			if (a[1] * m2*m3 + a[4] * m1*m3 == a[7] * m1*m2)
//			{
//				s++; printf("(%2d)", s);
//				printf(" %d/%1d+%d/", a[1], m1, a[4]);
//				printf("%1d=%d/%1d ", m2, a[7], m3);
//				if (s % 2 == 0) printf("\n");
//			}
//		}
//		if (i<9 && g == 1)
//		{
//			i++; a[i] = 1; continue;
//		}
//		while (a[i] == 9 && i>1)i--;
//		if (a[i] == 9 && i == 1)break;
//		else a[i]++;
//	}
//	printf("  ������%d���⡣\n", s);
//}


//�����Լ��

#include<stdio.h>
//���ú���
long gcb(long a, long b)
{
	long c, r;
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
	printf("����������%d������", n);
	for (k = 0; k <= n - 1; k++)
	{
		printf("������%��������", k + 1);
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



////�����Լ��
//
//#include<stdio.h>
//
//void main()
//{
//	int k, n;
//	long a, b, c, r, m[100];
//	printf("����������n: ");
//	scanf("%d", &n);
//	printf("����������%d������ ", n);
//	for (k = 0; k <= n - 1; k++)
//	{
//		printf("\n������%d�������� ", k + 1);
//		scanf("%ld", &m[k]);
//	}
//	b = m[0];
//	for (k = 1; k <= n - 1; k++)
//	{
//		a = m[k];
//		if (a < b)
//		{
//			c = a; a = b; b = c;
//		}
//		r = a%b;
//		while (r != 0)
//		{
//			a = b; b = r;
//			r = a%b;
//		}
//	}
//	printf("%ld ", m[0]);
//	for (k = 1; k <= n - 1; k++)
//		printf(",%ld", m[k]);
//	printf(" = %ld\n", b);
//}