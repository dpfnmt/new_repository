#include<stdio.h>
#include<string.h>

void fanw(char* left, char* right)//��һ�����ʽ�����װ
{
	char* pleft = left;
	char* pright = right;
	char tmp;
	while (pleft < pright)
	{
		tmp = *pleft;
		*pleft = *pright;
		*pright = tmp;
		pleft++;
		pright--;
	}
}

void fans(char * p) //��һ���ַ�������һ������
{
	while (*p != '\0')
	{
		char* pst = p;
		while (*p != '\0' && *p != ' ')
		{
			p++;
		}
		fanw(pst, p - 1);
		p++;
	}
}
int main()
{
	char p[] = "i am a student";
	int len = strlen(p);
	printf("ԭ�ַ���Ϊ: %s\n", p);
	printf("���ַ���Ϊ��");
	fanw(p, p + len - 1);
	fans(p);
	printf("%s\n", p);
	return 0;
}