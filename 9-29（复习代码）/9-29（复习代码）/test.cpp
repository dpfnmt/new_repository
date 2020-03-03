#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char str[1005];
	char sub[105];
	cin >> str >> sub;
	int i = 0 , j = 0; // 没有初始化
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int t = 0;
	int cnt = 0;
	while (i < lenstr && j < lensub)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
			cnt++;
			t = 0;
		}
		else
		{
			if (sub[j + 1] == str[i])
			{
				i++;
				j += 2;
				t = 0;
				cnt++;
			}
			else if (sub[j] == '?' && t < 3)
			{
				i++;
				cnt++;
				t++;
			}
			else
			{
				break;
			}
		}
	}
	if (j == lensub)
		cout << cnt << endl;
	else
		cout << -1 << endl;
	return 0;
}