#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int board[66][66];

void recur(int n, int x, int y) {
	int cur = board[x][y];
	for (int i = x; i < x+n; ++i) {
		for (int j = y; j < y+n; ++j) {
			if (cur != board[i][j]) {
				cout << '(';
				recur(n/2, x, y);
				recur(n/2, x, y + n/2);
				recur(n/2, x + n/2, y);
				recur(n/2, x + n/2, y + n/2);
				cout << ')';
				return;
			}
		}
	}
	cout << cur;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string buf;
	for (int i = 0; i < n; ++i) {
		cin >> buf;
		for (int j = 0; j < n; ++j)
			board[i][j] = buf[j] - '0';
	}
	recur(n, 0, 0);
	cout << '\n';
	return (0);
}

