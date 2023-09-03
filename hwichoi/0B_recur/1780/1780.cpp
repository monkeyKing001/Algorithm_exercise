#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int board[5000][5000];
int cnt1, cnt2, cnt3;

void recur(int n, int x, int y) {
	int flag = 0;
	int tmp = board[x][y];
	for (int i = x; i < x+n; ++i) {
		for (int j = y; j < y+n; ++j) {
			if (tmp != board[i][j]){
				flag = 1;
				break;
			}
		}
	}
	if (!flag) {
		switch (tmp) {
			case -1:
				cnt1++;
				break;
			case 0:
				cnt2++;
				break;
			case 1:
				cnt3++;
				break;
		}
		return;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				recur(n/3, x + n/3*i, y + n/3*j);
			}
		}
	}
}


int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	recur(n, 0, 0);
	cout << cnt1 << '\n' << cnt2 << '\n' << cnt3 << '\n';
	return (0);
}

