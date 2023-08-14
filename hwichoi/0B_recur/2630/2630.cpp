#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int board[130][130];
int cnt[2] = {};

void recur(int n, int x, int y) {
	int flag = 0;
	int cur = board[x][y];
	for (int i = x; i < x+n; ++i) {
		for (int j = y; j < y+n; ++j) {
			if (cur != board[i][j]) {
				recur(n/2, x, y);
				recur(n/2, x + n/2, y);
				recur(n/2, x, y + n/2);
				recur(n/2, x + n/2, y + n/2);
				return;
			}
		}
	}
	if (cur) cnt[1]++;
	else cnt[0]++;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}
	recur(n, 0, 0);
	cout << cnt[0] << '\n' << cnt[1] << '\n';
	return (0);
}

