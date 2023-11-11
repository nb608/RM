#include<iostream>
using namespace std;
int main()
{
    int a, b = 1;
    cin >> a;
    while (a != 1)
    {
        a = a / 2;
        b++;
    }
    cout << b;
    return 0;
}
