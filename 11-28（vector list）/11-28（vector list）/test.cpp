#include<iostream>
#include<vector>
#include<string>
using namespace std;


//class Person
//{
//public:
//	Person()
//	{
//		++_count;
//	}
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 2;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	//Person  p0;
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " renshu:" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " renshu:" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	return 0;
//}

class Preson{
public:
	string _name;
};
class Student :public Preson
{
protected:
	int _num;
};
class Tearch : public Preson
{
protected:
	int _id;
};
class Assistant :public Student, public Tearch
{
protected:
	string _majorCourse;
};
void Test()
{
	Assistant a;
	//a._name = "dpfnmt";  //如果我直接使用这个a调用，那么就会报错，显示：不知道调用谁的，指明不明确；

	//所以要使用下面的调用；
	a.Student::_name = "dpf";
	a.Tearch::_name = "nmt";
	cout << a.Student::_name << endl;
	cout << a.Tearch::_name << endl;
}
int main()
{
	Test();
	return 0;
}
