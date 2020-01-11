#include<stdio.h>
#include<string.h>

void fanw(char* left, char* right)//对一个单词进行旋装
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

void fans(char * p) //在一个字符串中找一个单词
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
	printf("原字符串为: %s\n", p);
	printf("现字符串为：");
	fanw(p, p + len - 1);
	fans(p);
	printf("%s\n", p);
	return 0;
}