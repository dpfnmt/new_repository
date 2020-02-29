//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (int i = 0; i < s2.size(); i++)
//	{
//		int index;
//		while ((index = s1.find(s2[i])) != -1)
//		{
//			s1.erase(index, 1);
//		}
//	}
//	cout << s1 << endl;
//	return 0;
//}

//连续数字的想和
//#include<iostream>
//#include<vector>
//using  namespace std;
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> nums(n);
//	for (size_t i = 0; i < nums.size(); i++)
//	{
//		cin >> nums[i];
//	}
//	int sum1 = 0;
//	int sum2 = 0;
//	int max = nums[0];
//	for (size_t i = 0; i < nums.size(); i++)
//	{
//		if (sum1 >= 0)
//		{
//			sum2 = sum1 + nums[i];
//		}
//		else
//		{
//			sum2 = nums[i];
//		}
//		if (sum2 > max)
//		{
//			max = sum2;
//		}
//		if (sum2 < 0)
//		{
//			sum2 = 0;
//		}
//		sum1 = sum2;
//	}
//	cout << max << endl;
//	return 0;
//}



//计算24点游戏
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#define N 4
using namespace std;



int flag=0;
int num[N]; 
void solveByDfs(int index,int result,int num[])
{    
	if(result==24)  
	{        
		flag=1;  
		return ;  
	}   
	if(result > 24 || index>=4)  
		return ;  
	for(int choose=0; choose<4; choose++)  
	{       
		switch(choose)  
		{      
		case 0:       
			solveByDfs(index+1,result+num[index],num); 
			break;      
		case 1:          
			solveByDfs(index+1,result-num[index],num);   
			break;      
		case 2:          
			solveByDfs(index+1,result*num[index],num);     
			break;      
		case 3:    
			solveByDfs(index+1,result/num[index],num);     
			break;     
		}       
		if(flag)    
			return; 
	}
} 
int main()
{   
	int test=0; 
	while(cin>>num[0]>>num[1]>>num[2]>>num[3]) 
	{       
		flag=0;      
		test=0;        
		sort(num,num+4);      
		do        
		{        
			solveByDfs(0,test,num);  
		}      
		while(next_permutation(num,num+4));   
		if(flag)         
			cout<<"true"<<endl;  
		else           
			cout<<"false"<<endl; 
	}    
	return 0;
}
