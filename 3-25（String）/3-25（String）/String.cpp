//#include<string>   //这个后没有没有<.h>
//#include<iostream>
//using namespace std;
//#include<cstring>
//
//void TestString()
//{
//	string s("Hello world!!");
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;   //string类直接支持cin和cout;
//	cout << s << endl; //没有与这个相同的类型；
//
//	s.clear();//把这里面的内容清空之后，长度与字符个数清空，但是底层容量没有大的变化。
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	s.resize(10, 'a'); //把s中有效字符数增加到15个，多余的用a补上
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;   //为什么打印不出来？
//
//	s.resize(15);     //把s中的有效字符增加15个，多余的用\0补上；
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	s.resize(5);     //把s中的有效字符减少到5个；
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//}
////
//void  TestString2()
//{
//	//测试reserve是否影响string的有效个数
//	string s("hello world");
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	//判断缩小reserve的大小，是否会改变容量的大小；
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	//我们可以由测试可以看见内容是不会改变的,且缩小容量，对容量的大小也不会改变；
//}
////
//////3.string类对象的访问操作符
//void  TestString3()
//{
//	string s1("hello bit");
//	const string s2("hello world");
//	cout << s1 << " " << s2 << endl;
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//
//	//s2[0] = 'H';  //编译失败，因为const类型不能被修改；
//}
////
//////4.string类对象的修改操作
//void  TestString4()
//{
//	string  str;
//	str.push_back(' ');
//	str.append("hello");
//	str.push_back(' ');
//
//	str += 'b';
//	str += 'it';
//	cout << str << endl;
//	//cout << c_str()<<endl;这个为什么会报错，我实在是想不通；
//
//	//获取文件的后缀<.cpp>
//	string file("test.cpp");    
//	size_t pos = file.rfind('.');
//	string dpf(file.substr(pos, file.size() - pos));   //关键使用"substr"接口
//	cout << dpf << endl;
//
//	//取出dpf中的域名
//	string dpf1("http://www.cplusplus.com/reference/string/string/npos/");
//	cout << dpf1 << endl;
//	size_t start = dpf1.find('://');
//	if (start == string::npos)
//	{
//		cout << "dpf1" << endl;
//		return;
//	}
//	start += 2;  //这里为什么会是+3，而不是别尼？
//	size_t finsh = dpf1.find('/', start);    
//	string address = dpf1.substr(start ,finsh - start);
//	cout << address << endl;    //这里打印的就是去掉前面的http后面的域名；
//
//	//删除dpf1的协议前缀；
//	pos = dpf.find("://");
//	dpf1.erase(0, pos + 5);
//	cout << dpf1 << endl;
//}
////
////利用reserve提高效率，避免开空间带来的开销：
//void Testpushback()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s group\n";
//	for(int i = 0 ; i < 100; i++)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity change = " << sz << endl;
//		}
//	}
//}
//void Testpushback_p()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "making s group\n";
//	for (int i = 0; i < 100; i++)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity change = " << sz << endl;
//		}
//	}
//}
//
////
////int main()
////{
////	Testpushback();
////	Testpushback_p();
////	return 0;
////}
//
////string类的模拟实现
//
//#include<string>   //这个后没有没有<.h>
//#include<iostream>
//using namespace std;
//#include<cstring>
//#include<assert.h>
//
////这就是一个完整string的基本接口实现；
//
//class String
//{
//public:
//	String(const char* str = "")   //构造
//	{
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str)+1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s)    //拷贝构造
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pstr = new char[strlen(s._str) + 1];
//			strcpy(pstr, s._str);
//			delete[]_str;
//			_str = pstr;
//		}
//		return *this;
//	}
//
//	~String()    //析构
//	{
//		if (_str)
//		{
//			delete[]_str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
////
//////这样的方式叫做浅拷贝；s1与s2公用一块内存，当释放一块时，另一块也就释放掉了，导致程序崩溃；
//int main()
//{
//	String s1("hello world");
//	String s2(s1);
//	return 0;
//}
//
//现代版string的基本接口实现；
//class String
//{
//public:
//	String(const char* str = " ")
//	{
//		if (str != nullptr)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	//String& operator=(const String& s)  // 在这里交换函数怎么实现不了；
//	//{
//	//	swap(_str, s._str);
//	//	return *this;
//	//}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			/*char* pstr = new char[strlen(s.str) + 1];
//			strcpy(pstr, s._str);
//			delete[]_str;
//			_str = pstr;*/
//			String strTmp(s);
//			swap(_str, strTmp._str);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[]_str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//
//class String
//{
//public:
//	String(const char* str)   //构造
//	{
//		if (str == nullptr)
//		{
//			assert(false);
//			return;
//		}
//		_size = strlen(str);
//		_capacity = _size;
//		_str = new char[_capacity + 1];
//		strcpy(_str, str);
//	}
//
//
//private:
//	char* _str;
//	size_t _capacity;
//	size_t _size;
//};

#include<string>   //这个后没有没有<.h>
#include<iostream>
using namespace std;
#include<cstring>
#include<assert.h>

namespace bit
{
	class String
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		String(char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// copy(s1)
		String(const String& s)
			:_str(NULL)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}
		// copy = s2;
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}


		~String()
		{
			if (_str)
			{
				delete[] _str;
				_size = 0;
				_capacity = 0;
			}
		}

		bool operator<(const String& s)
		{
			int tmp = 0;
			while (tmp < _size && tmp < s._size)
			{
				if ((*_str + tmp) != (*s._str + tmp))
				{

					if ((*_str + tmp) >= (*s._str + tmp))
					{
						return false;
					}
					else
						return true;
				}
				tmp++;
			}
			if (_size < s._size)
			{
				return true;
			}
			else
			{
				cout << "tem:" << tmp << endl;
				return false;
			}
		}
		bool operator>(const String& s)
		{
			return !(*this < s || *this == s); //因为this是一个指针；

		}
		bool operator<=(const String& s)
		{
			return !(*this > s);
		}
		bool operator>=(const String& s)
		{
			return !(*this < s);
		}
		bool operator==(const String& s)
		{
			int tmp = 0;
			if (_size != s._size)
			{
				return false;
			}
			while (tmp != _size)
			{
				if ((*_str + tmp) != (*s._str + tmp))
				{
					return false;
				}
				tmp++;
			}
			return true;
		}
		bool operator!=(const String& s)
		{
			return !(*this == s);
		}

		void Reserve(size_t n)
		{
			if (n == _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		void PushBack(char ch)
		{
			if (_size >= _capacity)
			{
				Reserve(_capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size + 1] = '\0';

			cout << _str << endl;
		}

		void Append(const char* str)
		{
			size_t n = strlen(str);
			if (_size + n > _capacity)
			{
				Reserve(_size + n);
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
			cout << _str << endl;
		}

		String& operator+=(char ch);
		String& operator+=(const char* str);
		void Insert(size_t pos, char ch)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			String s(*this);
			char* tmp = s._str + pos;
			_str[pos] = ch;
			strcpy(_str + pos + 1, tmp);

			cout << _str << endl;
		}
		void Insert2(size_t pos, const char* str)
		{
			_size += strlen(str);
			while (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			int tmp = _size;
			while (tmp != pos - 1)
			{
				_str[tmp + strlen(str)] = _str[tmp];
				--tmp;
			}
			int tmp2 = 0;
			while (tmp2 < strlen(str))
			{
				_str[pos + tmp2] = str[tmp2];
				tmp2++;
			}
			/*int i=strlen(ch);
			String s(*this);
			char* tmp = s._str + pos;
			strcpy(_str+pos, ch);
			strcpy(_str+pos+i,tmp);*/


			cout << _str << endl;

		}

		void Erase(size_t pos, size_t len);
		size_t Find(char ch, size_t pos = 0)
		{
			int i = 0;
			for (i = 0; i< _size; ++i)
			{
				while (pos < _size)
				{
					if (_str[pos] == ch)
					{
						return pos;
					}
					else
						pos++;
				}
				return -1;
			}
			//cout<<<<endl;
		}
		size_t Find2(const char* str, size_t pos = 0)
		{
			if (strlen(str) > _size)
			{
				return -1;
			}
			int tmp = 0;
			while (pos < _size)
			{
				tmp = 0;
				if (_str[pos] == str[0])
				while (tmp <= strlen(str))
				{
					if (_str[pos + tmp] != str[tmp])
					{
						break;
					}
					tmp++;
					if (tmp == strlen(str))
					{
						return pos;
					}
				}
				pos++;
			}

		}


		char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			//assert(pos < _size);

			return _str[pos];
		}

		size_t Size()
		{
			return _size;
		}

		size_t Capacity()
		{
			return _capacity;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t String::npos = -1;

	void TestString1()
	{
		String s1("hello");
		String s2("word");
		s1.PushBack('h');
		s1.Append("hidasfa");
		s1.Insert2(3,"fdsa");
		//cout << s1.Find2("ll", 0);
		cout<<(s1 < s2)<<endl;
		cout<<(s1 == s2)<<endl;
		cout<<(s1 <= s2)<<endl;
		String copy(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		copy = s1 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		String::iterator it = s1.begin();
		while (it != s1.end())
		{
		cout << *it << " ";
		++it;
		}
		cout << endl;


	}
}
int main()
{
	bit::TestString1();
	return 0;
}

