#include<iostream>

using namespace std;


int NumWa(int n)
{
	int ret = 0;
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
	{
		return 2 * NumWa(n - 1);

	}
	return ret;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumWa(n) << endl;;
	}
}