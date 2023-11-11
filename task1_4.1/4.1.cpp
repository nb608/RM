#include<iostream>
using namespace std;
int main()
{
	int s = 0;
	float n, k = 0, j = 2;
	cin >> n;
	while (k < n)
	{
		k = k + j;
		j = j * 0.98;
		s++;
	}
	cout << s;
}