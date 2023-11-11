#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	int arr[99];
	for (int x = 0; x < 99; x++)
	{
		cin >> arr[x];
		n++;
		if (arr[x] == 0)
		{
			break;
		}
	}
	for (int y = n - 2; y >= 0; y--)
	{
		if (y != 0)
			cout << arr[y] << " ";
		else
		{
			cout << arr[y];
		}
	}
	return 0;
}