#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class A
{
public:
	virtual ~A(){};
};

int main()
{
	/*int*p = (int*)0x1000;
	++p;
	printf("%d", p);*/
	A *p = (A*)0x1000;
	++p;
	printf("%d", p);
	return 0;
}
