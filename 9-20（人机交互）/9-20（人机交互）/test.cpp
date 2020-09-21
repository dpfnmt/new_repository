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
		cout << "请输入第一个数字:";
		cin >> i;
		cout << "请输入第二个数字:";
		cin >> j;
		cout << "请输入第三个数字:";
		cin >> k;
		if (i<1 || i>200){
			cout << "第一个数字输入不合法\n";
			isOK = false;
		}
		if (j<1 || j>200){
			cout << "第二个数字输入不合法\n";
			isOK = false;
		}
		if (k<1 || k>200){
			cout << "第三个数字输入不合法\n";
			isOK = false;
		}
		if (isOK == false){ return 0; }
		if (i == j){ match = match + 1; }
		if (i == k){ match = match + 2; }
		if (j == k){ match = match + 3; }
		if (match == 0){
			if ((i + j <= k)){ cout << "不能组成三角形\n"; }
			else{
				if ((k + j <= i)){ cout << "不能组成三角形\n"; }
				else{
					if ((k + i <= j)){ cout << "不能组成三角形\n"; }
					else{ cout << "组成的是一般三角形\n"; }
				}
			}
		}
		else{
			if (match == 1){
				if (i + j <= k){ cout << "不能组成三角形\n"; }
				else{ cout << "组成的三角形是等腰三角形\n"; }
			}
			else{
				if (match == 2){
					if ((i + k <= j)){ cout << "不能组成三角形\n"; }
					else{ cout << "组成的三角形是等腰三角形\n"; }
				}
				else{
					if (match == 3){
						if ((j + k<i)){ cout << "不能组成三角形\n"; }
						else{ cout << "组成的三角形是等腰三角形\n"; }
					}
					else{
						cout << "组成的三角形是等边三角形\n";
					}
				}
			}
		}
	}

	return 0;
}