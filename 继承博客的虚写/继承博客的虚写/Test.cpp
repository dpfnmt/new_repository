#include<string>
#include<iostream>
using namespace std;
//
//class Preson{
//public:
//	string _name;
//};
//class Student :public Preson
//{
//protected:
//	int _num;
//};
//class Tearch : public Preson
//{
//protected:
//	int _id;
//};
//class Assistant :public Student, public Tearch
//{
//protected:
//	string _majorCourse;
//};
//void Test()
//{
//	Assistant a;
//	//a._name = "dpfnmt";  //如果我直接使用这个a调用，那么就会报错，显示：不知道调用谁的，指明不明确；
//	
//	//所以要使用下面的调用；
//	a.Student::_name = "dpf";
//	a.Tearch::_name = "nmt";
//
//	cout << a.Student::_name << endl;
//	cout << a.Tearch::_name << endl;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//class Preson{
//public:
//	int _name;
//};
//class Student :virtual public Preson
//{
//public:
//	int _num;
//};
//class Tearch :virtual public Preson
//{
//public:
//	int _id;
//};
//class Assistant :public Student, public Tearch
//{
//public:
//	int _majorCourse;
//};
//
//int main()
//{
//	Assistant a;
//	a.Student::_name = 1;
//	a.Tearch::_name = 2;
//	a._num = 3;
//	a._id = 4;
//	a._majorCourse = 5;
//
//
//	cout << a.Student::_name << endl;
//	cout << a.Tearch::_name << endl;
//	cout << a._num <<" "<< a._id << " " <<a._majorCourse << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	cout << d.B::_a << endl;
//	cout << d.C::_a << endl;
//	cout << d._b << endl;
//	cout << d._c << endl;
//	cout << d._d << endl;
//	return 0;
//}

//class Base1
//{
//public:
//	virtual void fun1() { cout << "Base1::fun1" << endl; };
//};
//
//class Base2
//{
//public:
//	virtual void fun2() { cout << "Base2::fun1" << endl; };
//};
//
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void fun1() { cout << "Derive::fun1" << endl; }
//	virtual void fun2() { cout << "Derive::fun2" << endl; }
//};
//
//int main()
//{
//	Derive oD;
//	Base1 *pB1 = (Base1*)(&oD);
//	Base2 *pB2 = (Base2*)(&oD);
//	cout << "&oD=" << &oD << '\n';
//	cout << "pB1=" << pB1 << '\n';
//	cout << "pB2=" << pB2 << '\n';
//	if (&oD == pB1) cout << "&oD == pB1" << '\n';
//	if (&oD == pB2) cout << "&oD == pB2" << '\n';
//}



