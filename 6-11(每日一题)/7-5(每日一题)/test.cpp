//int first = 0;		
//int last = vec.size() - 1;	
//for (int first = 0; first < vec.size(); ++first) 
//{ 
//	if (first % 2 == 0 && vec[first] % 2 != 0)
//	{ int i = first + 1;			
//	for (; i < vec.size(); ++i) 
//	{ 
//		if (vec[i] % 2 == 0) 
//			break; 
//	}				
//	if (i < vec.size())
//	{ 
//		int tmp = vec[first];			
//		vec[first] = vec[i];			
//		vec[i] = tmp;
//	}
//} 
//	else if (first % 2 != 0 && vec[first] == 0) 
//	{ 
//		int i = first + 1;			
//		for (int i = first + 1; i < vec.size(); ++i)
//		{
//			if (vec[i] % 2 != 0) 
//				break;
//		}				
//		if (i < vec.size())
//		{ 
//			int tmp = vec[first];			
//			vec[first] = vec[i];			
//			vec[i] = tmp;
//		}
//	}
//}


//#include<iostream>
//#include<cmath> 
//using namespace std;    
//int main() 
//{     
//	int n;    
//	while(cin >> n)   
//	{         
//		if(n == 0)   
//			break;        
//		else         
//		{            
//			cout <<pow(5, n) - 4 <<" "<<pow(4, n) + n - 4 << endl;
//		}    
//	}      
//	return 0; 
//}

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:

	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int odd = 1;
		int even = 0;
		while (odd < len && even < len)
		{
			if (arr[odd] % 2 == 0)
			{
				while (arr[even] % 2 == 0)
				{
					even += 2;
				}
				if (even < len)
				{
					int tmp = arr[even];
					arr[even] = arr[odd];
					arr[odd] = tmp;
				}
				else
				{
					break;
				}
			}
			else
			{
				odd += 2;
			}
		}
	}
};
