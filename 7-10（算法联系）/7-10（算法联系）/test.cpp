#include<iostream>
using namespace std;

int PathThough(int n, int m)
{
	if (n > 1 && m > 1)
	{
		return PathThough(n - 1, m) + PathThough(n, m - 1);
	}
	else if ((n >= 1 && m == 1) || (n == 1 && m >= 1))
	{
		return n + m;
	}
	else
		return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << PathThough(n, m) << endl;
	}
	return 0;
}