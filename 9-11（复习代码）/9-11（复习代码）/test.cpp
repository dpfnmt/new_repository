//#include<iostream>
//#include<string>
//#include<assert.h>
//using namespace std;
//
//class String
//{
//public:
//	String(const char* s = " ") 
//		//: str(new char[strlen(s + 1)])
//		:str(new char[strlen(s) + 1])
//	{
//		cout << strlen(s + 1);
//		
//		//str = new char[strlen(s) + 1];
//		strcpy(str, s);
//		cout << *str;
//	}
//
//	String(String& _str)
//		: str(new char[strlen(_str.str)+1])
//	{
//		strcpy(str, _str.str);
//	}
//	String& operator=(const String& _str)
//	{
//		char* s = _str.str;
//		int n = 0;
//		while (*s != '\0')
//		{
//			n++; 
//			s++;
//		}
//		delete(str);
//		str = new char[n];
//
//		for (int i = 0; i < n; i++)
//		{
//			str[i] = _str.str[i];
//		}
//
//		return *this;
//	}
//
//	~String()
//	{
//
//		cout << "\n~String";
//		if (str)
//		{
//			delete(str);
//			str = nullptr;
//		}	
//	}
//
//private:
//	char* str;
//
//};
//
//
//int main()
//{
//	const char* m = "123456";
//	String m2;
//
//	//String m3(m2);
//
//}