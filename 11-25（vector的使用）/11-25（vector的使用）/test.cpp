#include<iostream>
#include<ostream>
#include<vector>

using namespace std;


int main()
{
	vector<int> v;
	/*for (int i = 0; i <= 10; i++)
	{
		v.push_back(i);
		cout <<"size="<< v.size();
		cout <<"capacity="<< v.capacity() << endl;
	}
	cout << "----------------------------------" << endl;*/
	/*v.resize(10);
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << "size=" << v.size();
		cout << "capacity=" << v.capacity() << endl;
	}*/
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(7);
	v.push_back(8);
	v.push_back(6);
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it <<" ";
		++it;
	}
	cout << endl;*/
	vector<int>::iterator pos = find(v.begin(), v.end(), 4);
	v.insert(pos,30);
	for (auto&e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}

//int main()
//{
//	vector<int> v;
//
//	for (int i = 0; i<30; i++)
//	{
//		v.push_back(i);
//		cout << "size=" << v.size() << endl;
//		cout << "capacity=" << v.capacity() << endl;
//	}
//	cout << "---------------------------------------------" << endl;
//
//	//释放空间
//	v.clear();
//	cout << "size=" << v.size() << endl;//0
//	cout << "capacity=" << v.capacity() << endl;//42
//
//	v.erase(v.begin(), v.end());
//	cout << "size=" << v.size() << endl;//0
//	cout << "capacity=" << v.capacity() << endl;//42   
//	/*
//			第一步：先产生一个和原先一样的临时对象
//			第二步：临时量调用swap()函数两者进行交换。
//			第三步：语句结束，临时量自动析构。
//			*/
//	vector<int>(v).swap(v);
//	/*
//	vector<int>(vec).swap(vec);  ===>   vec.swap(vector<int>())
//	*/
//
//	cout << "size=" << v.size() << endl;//0
//	cout << "capacity=" << v.capacity() << endl;//0
//	return 0;
//}


//int main()
//{
//	vector<int> v(3,100);
//	//vector<int> s(5,200);
//	v.clear();
//	for (unsigned i = 0; i < v.size(); i++)
//		cout << v[i] << " " << endl;
//	return 0;
//}