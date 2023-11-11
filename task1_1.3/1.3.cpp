#include <iostream>
using namespace std;
int main()
{
    double a = 0, g = 0, b = 0, c = 0, d = 0, f = 0;

    cin >> a;
    b = (a - int(a)) * 10;
    c = int(a) % 10;
    d = int(a) / 10 % 10;
    f = int(a) / 100;
    g = b + c * 0.1 + d * 0.01 + f * 0.001;
    cout << g;
    return 0;


}