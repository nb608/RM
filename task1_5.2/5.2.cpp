#include<iostream>
#include<conio.h>
using namespace std;
#include<cstdlib>
int main()
{
    int a = 0, b = 0, c = 1, d = 1, i = 0;
    char re = 'a';


    while (re == 'a')
    {
        i = 0;
        cout << "请出题者输入1~100中的一个整数:";
        char num[64], ch;
        while (1)
        {

            ch = getch();
            num[d++] = ch;
            cout << "*";
            if (ch == '\r')
            {
                break;
            }
            i++;
        }
        switch (i)
        {
        case 1:a = num[1] - '0';
            break;
        case 2:a = 10 * (num[1] - '0') + (num[2] - '0');
            break;
        case 3:a = (num[1] - '0') * 100 + (num[2] - '0') + (num[3] - '0');
            break;
        }

        if (a < 1 || a>100)
        {
            cout << "输入错误，请重新输入" << endl;
        }
        else
        {
            re = 'b';
        }
    }
    cout << "请输入你猜的数：";
    cin >> b;
    while (b != a)
    {
        if (b > a)
        {
            cout << "比密码数字大，";
        }
        else {
            cout << "比密码数字小，";
        }
        cout << "再猜一次：";
        cin >> b;
        c++;

    }
    cout << "恭喜猜对了！答案就是" << a << ",共猜测" << c << "次";
    return 0;
}
