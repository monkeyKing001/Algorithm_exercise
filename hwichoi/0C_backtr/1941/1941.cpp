#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
string board[5];
bool idx[25];
int cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; ++i)
			cin >> board[i];
	fill(idx+7, idx+25, 1);
	do {
		int Y = 0;
		queue<pair<int, int>> Q;
		bool vis[5][5] = {};
		for (int i = 0; i < 25; ++i) {
			if (idx[i]) continue;
			int x = i/5;
			int y = i%5;
			if (board[x][y] == 'Y') Y++;
			if (Q.empty()) {
				Q.push({x, y});
				vis[x][y] = 1;
			}
		}
		if (Y > 3) continue;
		int len = 0;
		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();
			len++;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (vis[nx][ny] || idx[nx*5 + ny]) continue;
				Q.push({nx, ny});
				vis[nx][ny] = 1;
			}
		}
		if (len == 7) cnt++;
	} while (next_permutation(idx, idx+25));
	cout << cnt << '\n';
	return (0);
}

