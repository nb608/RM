#include<iostream>
using namespace std;
int main()
{
	int n, x, t = 0;
	cin >> n >> x;
	for (int j = 1; j <= n; j++)
	{
		int p = j;
		while (p != 0)
		{
			if (p % 10 == x)
			{
				t++;
				p = p / 10;
			}
			else
			{
				p = p / 10;
			}
		}
	}
	cout << t;
	return 0;
}