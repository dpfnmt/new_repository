#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <time.h>

void menu()
{

	printf("******************************\n");
	printf("********** 1.game ************\n");
	printf("********** 0.quit ************\n");
	printf("******************************\n");
}
void game()
{
	int rand_num = rand() % 100 + 1;
	//char s1[30];
	int input = 0;
	int count = 0;
	while (1)
	{
		printf("\n请输入你猜的数字：>");
		scanf("%d", &input);
		if (input < rand_num)
		{
			printf("\n猜小了！");
			count++;
		}
		else if (input>rand_num)
		{
			printf("\n猜大了！");
			count++;
		}
		else
		{
			count++;
			printf("\n恭喜你，猜对了！");
			printf("\n你一共猜了%d次", count);
			break;
		}
	}
	printf("\n");
}

int main()
{
	
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择1或者0：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("\n请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
