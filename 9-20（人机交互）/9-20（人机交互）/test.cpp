// triangle.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include "math.h"
#include<iostream>
using namespace std;
int main()
{
	int i, j, k;
	int match;
	bool isOK = true;

	for (int m = 0; m<100; m++){
		match = 0;
		isOK = true;
		cout << "�������һ������:";
		cin >> i;
		cout << "������ڶ�������:";
		cin >> j;
		cout << "���������������:";
		cin >> k;
		if (i<1 || i>200){
			cout << "��һ���������벻�Ϸ�\n";
			isOK = false;
		}
		if (j<1 || j>200){
			cout << "�ڶ����������벻�Ϸ�\n";
			isOK = false;
		}
		if (k<1 || k>200){
			cout << "�������������벻�Ϸ�\n";
			isOK = false;
		}
		if (isOK == false){ return 0; }
		if (i == j){ match = match + 1; }
		if (i == k){ match = match + 2; }
		if (j == k){ match = match + 3; }
		if (match == 0){
			if ((i + j <= k)){ cout << "�������������\n"; }
			else{
				if ((k + j <= i)){ cout << "�������������\n"; }
				else{
					if ((k + i <= j)){ cout << "�������������\n"; }
					else{ cout << "��ɵ���һ��������\n"; }
				}
			}
		}
		else{
			if (match == 1){
				if (i + j <= k){ cout << "�������������\n"; }
				else{ cout << "��ɵ��������ǵ���������\n"; }
			}
			else{
				if (match == 2){
					if ((i + k <= j)){ cout << "�������������\n"; }
					else{ cout << "��ɵ��������ǵ���������\n"; }
				}
				else{
					if (match == 3){
						if ((j + k<i)){ cout << "�������������\n"; }
						else{ cout << "��ɵ��������ǵ���������\n"; }
					}
					else{
						cout << "��ɵ��������ǵȱ�������\n";
					}
				}
			}
		}
	}

	return 0;
}