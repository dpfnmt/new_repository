//#include<iostream>
//using namespace std;
//
//
//int fib(int a)
//{
//	if (a == 0 || a == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		int z = fib(a - 1) + fib(a - 2);
//		if (z)
//	}
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << fib(n) << endl;
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{  
//	int Arr[100001]; 
//	int n = 0;  
//	Arr[0] = 1;   
//	Arr[1] = 1;  
//	for (int i = 2; i <= 100000; i++)   
//	{       
//		Arr[i] = Arr[i - 1] + Arr[i - 2];  
//		Arr[i] = Arr[i] % 1000000;  
//	}    while (scanf("%d",&n) != EOF)
//	{       
//		//前面补0,要用06d   
//		printf((n < 29 ? "%d\n" : "%06d\n"),Arr[n]); 
//	}  
//	return 0;
//}

#include <iostream> 
using namespace std; 
int main()
{   
	int year1, month1, day1, year2, month2, day2; 
	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)   
	{      
		int sum=0; 
		int year = year1;    
		for (int i = year1; i <= year2 - 1; ++i)
		{          
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) 
				sum+=580;  
			else 
				sum += 579;      
		}       
		for (int i = 0; i <= month1 - 1; ++i)
		{         
			int temp = 0;        
			if (i == month1 - 1) 
				temp = day1 - 1;  
			else
				temp = d[i];    
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
			{
				sum -= temp * 2; 
			}           
			else
				sum -= temp; 
		}      
		for (int i = 0; i <= month2 - 1; ++i)
		{           
			int temp = 0;    
			if (i == month2 - 1) 
				temp = day2;    
			else 
				temp = d[i];   
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
			{ 
				sum += temp * 2;
			}         
			else 
				sum += temp;  
		}               
		cout << sum << endl;   
	}     
	return 0;
}