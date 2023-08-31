#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, ret;
int input[22][22];
int board[22][22];
int buf[22][22];

void rotate(int num) {
	while (num--) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				buf[i][j] = board[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				board[j][n-i-1] = buf[i][j];
	}
}

void act(void) {
	for (int i = 0; i < n; ++i) {
		int idx = 0;
		for (int j = 0; j < n; ++j) {
			if (!board[i][j]) continue;
			int tmp = board[i][j];
			board[i][j++] = 0;
			while (!board[i][j] && j < n) j++;
			if (j == n || tmp != board[i][j]) {
				board[i][idx++] = tmp;
				j--;
				continue;
			}
			board[i][idx++] = tmp + board[i][j];
			board[i][j] = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) cin >> input[i][j];
	for (int i = 0; i < (1 << (2 * 5))-1; ++i) {
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < n; ++y) board[x][y] = input[x][y];
		int tmp = i;
		for (int cnt = 0; cnt < 5; ++cnt) {
			int rot = tmp % 4;
			tmp /= 4;
			rotate(rot);
			act();
			if (rot == 0) continue;
			rotate(4-rot);
		}
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < n; ++y)
				if (ret < board[x][y]) ret = board[x][y];
	}
	cout << ret << '\n';
	return (0);
}

