//#include<string>   //�����û��û��<.h>
//#include<iostream>
//using namespace std;
//#include<cstring>
//
//void TestString()
//{
//	string s("Hello world!!");
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;   //string��ֱ��֧��cin��cout;
//	cout << s << endl; //û���������ͬ�����ͣ�
//
//	s.clear();//����������������֮�󣬳������ַ�������գ����ǵײ�����û�д�ı仯��
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	s.resize(10, 'a'); //��s����Ч�ַ������ӵ�15�����������a����
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;   //Ϊʲô��ӡ��������
//
//	s.resize(15);     //��s�е���Ч�ַ�����15�����������\0���ϣ�
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	s.resize(5);     //��s�е���Ч�ַ����ٵ�5����
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//}
////
//void  TestString2()
//{
//	//����reserve�Ƿ�Ӱ��string����Ч����
//	string s("hello world");
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	//�ж���Сreserve�Ĵ�С���Ƿ��ı������Ĵ�С��
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	//���ǿ����ɲ��Կ��Կ��������ǲ���ı��,����С�������������Ĵ�СҲ����ı䣻
//}
////
//////3.string�����ķ��ʲ�����
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
//	//s2[0] = 'H';  //����ʧ�ܣ���Ϊconst���Ͳ��ܱ��޸ģ�
//}
////
//////4.string�������޸Ĳ���
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
//	//cout << c_str()<<endl;���Ϊʲô�ᱨ����ʵ�����벻ͨ��
//
//	//��ȡ�ļ��ĺ�׺<.cpp>
//	string file("test.cpp");    
//	size_t pos = file.rfind('.');
//	string dpf(file.substr(pos, file.size() - pos));   //�ؼ�ʹ��"substr"�ӿ�
//	cout << dpf << endl;
//
//	//ȡ��dpf�е�����
//	string dpf1("http://www.cplusplus.com/reference/string/string/npos/");
//	cout << dpf1 << endl;
//	size_t start = dpf1.find('://');
//	if (start == string::npos)
//	{
//		cout << "dpf1" << endl;
//		return;
//	}
//	start += 2;  //����Ϊʲô����+3�������Ǳ��᣿
//	size_t finsh = dpf1.find('/', start);    
//	string address = dpf1.substr(start ,finsh - start);
//	cout << address << endl;    //�����ӡ�ľ���ȥ��ǰ���http�����������
//
//	//ɾ��dpf1��Э��ǰ׺��
//	pos = dpf.find("://");
//	dpf1.erase(0, pos + 5);
//	cout << dpf1 << endl;
//}
////
////����reserve���Ч�ʣ����⿪�ռ�����Ŀ�����
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
////string���ģ��ʵ��
//
//#include<string>   //�����û��û��<.h>
//#include<iostream>
//using namespace std;
//#include<cstring>
//#include<assert.h>
//
////�����һ������string�Ļ����ӿ�ʵ�֣�
//
//class String
//{
//public:
//	String(const char* str = "")   //����
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
//	String(const String& s)    //��������
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
//	~String()    //����
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
//////�����ķ�ʽ����ǳ������s1��s2����һ���ڴ棬���ͷ�һ��ʱ����һ��Ҳ���ͷŵ��ˣ����³��������
//int main()
//{
//	String s1("hello world");
//	String s2(s1);
//	return 0;
//}
//
//�ִ���string�Ļ����ӿ�ʵ�֣�
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
//	//String& operator=(const String& s)  // �����ｻ��������ôʵ�ֲ��ˣ�
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
//	String(const char* str)   //����
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

#include<string>   //�����û��û��<.h>
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
			return !(*this < s || *this == s); //��Ϊthis��һ��ָ�룻

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

