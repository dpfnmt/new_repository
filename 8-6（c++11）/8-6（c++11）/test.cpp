#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ʲô����ֵ   =��߶�����ֵ		 ���Ըı��ֵ
// ʲô����ֵ   =�ұߵĲ�һ������ֵ  �����Ըı��ֵ(���������ʽ����ֵ����ʱ����)
// ��ֵ���� int& lr = a;   ���κʹ�ֵ��λ����ʹ�ã����ٿ��������Ч��  
// ��ֵ���� int&& rr = 10; ��ֵ���غͽ���ֵ���Σ������ƶ�������ƶ���ֵ�����ٿ��������Ч��
// const��ֵ������������ֵ
// ��ֵ����move(��ֵ)
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

	// ��������
	// String s(��ֵ����)
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}