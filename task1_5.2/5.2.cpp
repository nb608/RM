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
        cout << "�����������1~100�е�һ������:";
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
            cout << "�����������������" << endl;
        }
        else
        {
            re = 'b';
        }
    }
    cout << "��������µ�����";
    cin >> b;
    while (b != a)
    {
        if (b > a)
        {
            cout << "���������ִ�";
        }
        else {
            cout << "����������С��";
        }
        cout << "�ٲ�һ�Σ�";
        cin >> b;
        c++;

    }
    cout << "��ϲ�¶��ˣ��𰸾���" << a << ",���²�" << c << "��";
    return 0;
}
