#include<iostream>
using namespace std;
char ch;
int main()
{
	if (cin >> ch)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch += 'A' - 'a';
		}
		cout << ch;
		main();
	}
	return 0;
}