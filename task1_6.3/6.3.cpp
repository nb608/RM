#include<iostream>
using namespace std;
void num1(int a, int b, int c)
{
    a *= 2;
    b *= 2;
    c *= 2;
    cout << "��num1������";
    cout << "x=" << a << ",y=" << b << ",z=" << c << endl;
}

void num2(int& a, int& b, int& c)
{
    a *= 2;
    b *= 2;
    c *= 2;
    cout << "��num2������";
    cout << "x=" << a << ",y=" << b << ",z=" << c << endl;
}

int main()
{
    int x = 1, y = 3, z = 7;
    num1(x, y, z);
    cout << "num1�������" << "x=" << x << ",y=" << y << ",z=" << z << endl;
    int d = 1, e = 3, f = 7;
    num2(d, e, f);
    cout << "num2�������" << "x=" << d << ",y=" << e << ",z=" << f;
    return 0;
}
