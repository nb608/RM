#include<iostream>
#include<iostream>
using namespace std;
int main()
{
    int m = 0, t = 0, s = 0;
    cin >> m >> t >> s;
    if (t == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (s % t == 0)
    {
        cout << max(m - s / t, 0) << endl;
    }
    else
    {
        cout << max(m - s / t - 1, 0) << endl;
    }
    return 0;

}