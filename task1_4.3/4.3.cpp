#include<iostream>
using namespace std;
int main()
{
	int n = 0, x = 0;
	cin >> n;
	int arr[200];
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			arr[x] = n;
			n = n / 2;
		}
		else
		{
			arr[x] = n;
			n = n * 3 + 1;
		}
		x++;
	}
	arr[x] = 1;
	for (int j = x; j >= 0; j--)
	{
		if (j != 0)
		{
			cout << arr[j] << " ";
		}
		else
		{
			cout << arr[0];
		}
	}
	return 0;
}