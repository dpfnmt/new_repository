#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

//     派生类   继承方式    基类


class Student : public      Person
{
protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};


int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}