#include<iostream>
#include<algorithm>

using namespace std;

bool IsPrime(int n)
{
	int tmp = sqrt(n);
	for (int i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n,m,i;
	while (cin >> n)
	{
		m = n / 2;
		for (i = m; i > 0; i--)
		{
			if (IsPrime(i) && IsPrime(n - i))
				break;
		}
		cout << i << " " << n - i << endl;
	}
	return 0;
}