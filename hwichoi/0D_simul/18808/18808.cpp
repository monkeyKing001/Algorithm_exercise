#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m, k;
int board[42][42];
bool stk[4][12][12];
int x, y;
int cnt;

int isIn(int a, int b, int idx) {
	int X, Y;
	if (idx % 2) {
		X = y;
		Y = x;
	}
	else {
		X = x;
		Y = y;
	}
	for (int i = a; i < a+X; ++i)
		for (int j = b; j < b+Y; ++j)
			if (stk[idx][i-a][j-b] && board[i][j]) return 0;
	return 1;
}

int putin(int idx) {
	int X, Y;
	if (idx % 2) {
		X = y;
		Y = x;
	}
	else {
		X = x;
		Y = y;
	}
	if (X > n || Y > m) return 0;
	for (int i = 0; i <= n-X; ++i) {
		for (int j = 0; j <= m-Y; ++j) {
			if (isIn(i, j, idx)) {
				for (int a = i; a < i+X; ++a)
					for (int b = j; b < j+Y; ++b)
						if (stk[idx][a-i][b-j]) board[a][b] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j) {
				cin >> stk[0][i][j];
				stk[1][j][x-i-1] = stk[0][i][j];
				stk[2][x-i-1][y-j-1] = stk[0][i][j];
				stk[3][y-j-1][i] = stk[0][i][j];
			}
		for (int i = 0; i < 4; ++i) {
			if (putin(i)) break;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j]) cnt++;
	cout << cnt << '\n';
	return (0);
}

