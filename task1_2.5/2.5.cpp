#include<iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x;
    y = x * 5;
    z = x * 3 + 11;
    if (y < z)
    {
        cout << "Local";
    }
    else
    {
        cout << "Luogu";
    }
    return 0;
}