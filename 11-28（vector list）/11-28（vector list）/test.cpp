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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 2;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
	//a._name = "dpfnmt";  //�����ֱ��ʹ�����a���ã���ô�ͻᱨ����ʾ����֪������˭�ģ�ָ������ȷ��

	//����Ҫʹ������ĵ��ã�
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
