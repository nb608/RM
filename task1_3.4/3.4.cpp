#include<iostream>
using namespace std;
int main()
{
	int n = 1, k = 0;
	double s = 0;
	cin >> k;
	do
	{
		s = 1.0 / n + s;
		n++;
	} while (s <= k);
	cout << n - 1;
	return 0;
}