#include<iostream>
using namespace std;
int main()
{
    int x = 0;
    cin >> x;
    if (x % 2 == 0 && x > 4 && x <= 12)
    {
        cout << "1" << " ";
    }
    else
    {
        cout << "0" << " ";
    }
    if (x % 2 == 0 || (x > 4 && x <= 12))
    {
        cout << "1" << " ";
    }
    else
    {
        cout << "0 ";
    }
    if (x % 2 == 0 && (x > 4 && x <= 12))
    {
        cout << "0" << " ";
    }
    else if (x % 2 != 0 && (x <= 4 || x > 12))
    {
        cout << "0" << " ";
    }
    else
    {
        cout << "1" << " ";
    }
    if (x % 2 != 0 && (x <= 4 || x > 12))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}