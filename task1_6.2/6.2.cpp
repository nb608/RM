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
	cout << "������ٸ�쳲��������е�����\n";
	cin >> n;
	Fibonacii(n);
	system("pause");
	return 0;
}
