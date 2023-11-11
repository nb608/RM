#include <iostream>
#include<conio.h>
using namespace std;
int hhh(int n)
{
	if (n <= 2) {
		return 1;
	}
	else
	{
		return hhh(n - 1) + hhh(n - 2);
	}

}
void Fibonacii(int n)
{
	int a = 1;
	while (a <= n)
	{
		cout << hhh(a) << " ";
		a++;
	}
}
int main()
{
	int n = 0;
	cout << "输出多少个斐波那契数列的数？\n";
	cin >> n;
	Fibonacii(n);
	system("pause");
	return 0;
}
