#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 什么是左值   =左边都是左值		 可以改变的值
// 什么是右值   =右边的不一定是右值  不可以改变的值(常量、表达式返回值、临时对象)
// 左值引用 int& lr = a;   传参和传值的位置是使用，减少拷贝，提高效率  
// 右值引用 int&& rr = 10; 传值返回和将亡值传参，调用移动构造和移动赋值，减少拷贝，提高效率
// const左值引用能引用右值
// 右值引用move(左值)
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 拷贝构造
	// String s(左值对象)
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}