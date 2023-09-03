#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <vector>

using namespace std;
int n, m;
int board[9][9];
int vis[9][9];
pair<int ,int> cctv[10];
int idx;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;
int ret = 100;

void seen(int x, int y, int dir) {
	while (x >= 0 && x < n && y >= 0 && y < m) {
		if (board[x][y] == 6) return;
		vis[x][y]++;
		x += dx[dir];
		y += dy[dir];
	}
}

void del(int x, int y, int dir) {
	while (x >= 0 && x < n && y >= 0 && y < m) {
		if (board[x][y] == 6) return;
		vis[x][y]--;
		x += dx[dir];
		y += dy[dir];
	}
}

void recur(int dep) {
	if (dep == idx) {
		cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!vis[i][j]) cnt++;
		if (cnt < ret) ret = cnt;
		return;
	}
	int x = cctv[dep].first;
	int y = cctv[dep].second;
	int tmp = board[x][y];
	switch (tmp) {
		case 1:
			for (int i = 0; i < 4; ++i) {
				seen(x, y, i);
				recur(dep+1);
				del(x, y, i);
			}
			return;
		case 2:
			for (int i = 0; i < 2; ++i) {
				seen(x, y, i);
				seen(x, y, i+2);
				recur(dep+1);
				del(x, y, i);
				del(x, y, i+2);
			}
			return;
		case 3:
			for (int i = 0; i < 4; ++i) {
				seen(x, y, i);
				seen(x, y, (i+1)%4);
				recur(dep+1);
				del(x, y, i);
				del(x, y, (i+1)%4);
			}
			return;
		case 4:
			for (int i = 0; i < 4; ++i) {
				seen(x, y, i);
				seen(x, y, (i+1)%4);
				seen(x, y, (i+2)%4);
				recur(dep+1);
				del(x, y, i);
				del(x, y, (i+1)%4);
				del(x, y, (i+2)%4);
			}
			return;
		case 5:
			seen(x, y, 0);
			seen(x, y, 1);
			seen(x, y, 2);
			seen(x, y, 3);
			recur(dep+1);
			del(x, y, 0);
			del(x, y, 1);
			del(x, y, 2);
			del(x, y, 2);
			return;
	}
	return;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 6) vis[i][j] = 1;
			if (board[i][j] != 0 && board[i][j] != 6) cctv[idx++] = {i, j};
		}
	recur(0);
	cout << ret << '\n';
	return (0);
}

