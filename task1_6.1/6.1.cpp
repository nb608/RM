#include<iostream>
using namespace std;

void year(int a, int b)
{
	int ans[1500];
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			ans[cnt++] = i;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << " ";
	}


}

int main()
{
	int x, y;
	cin >> x >> y;
	year(x, y);
	return 0;
}