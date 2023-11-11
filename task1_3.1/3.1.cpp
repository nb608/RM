#include<iostream>
using namespace std;
int main()
{
    int arr[99];
    int x, y, z, f = 1000000, d;
    cin >> x;
    for (y = 0; y < x; y++)
    {
        cin >> arr[y];

    }
    for (d = 0; d < x; d++)
    {
        int& z = f;

        if (z > arr[d])
        {
            z = arr[d];
        }
    }
    cout << f;

    return 0;
}