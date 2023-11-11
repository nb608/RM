#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    double a = 0, b = 0, c = 0, s = 0, d = 0;
    cin >> a >> b >> c;
    d = (a + b + c) / 2;
    s = sqrt(d * (d - a) * (d - b) * (d - c));
    printf("%.1f\n", s);
    return 0;
}