#include<vector>
#include<iostream>
using namespace std;

void PrintVctor(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	
	//PrintVctor(v);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	cout << endl;
	PrintVctor(v);





	return 0;
}