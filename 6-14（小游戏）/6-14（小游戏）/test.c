#define _CRT_SECURE_NO_WARNINGS 1

#include "Game.h"

void menu()
{
	printf("***** ��ӭ�����ҵ�ɨ������ *****\n");
	printf("********************************\n");
	printf("*****        1. play       *****\n");
	printf("*****        0. quit       *****\n");
	printf("********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ-'0'
	char show[ROWS][COLS] = { 0 };//���Ų�����׵���Ϣ-'*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��1����0:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
