#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
char board[10000][10000];

void recur(int n, int x, int y) {
	if (n == 1) {
		board[x][y] = '*';
		return;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != 1 || j != 1)
				recur(n/3, x + n/3*i, y + n/3*j);
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
	for (int i = 0; i < n; ++i)
		fill(board[i], board[i] + n, ' ');
	recur(n, 0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << board[i][j];
		cout << '\n';
	}
	return (0);
}

