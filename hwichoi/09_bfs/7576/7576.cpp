#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
int board[1002][1002];
bool vis[1002][1002] = {};
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> board[x][y];
			if (board[x][y] == 1) {
				vis[x][y] = 1;
				Q.push({x, y});
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0 || vis[nx][ny]) continue;
			board[nx][ny] = board[cur.first][cur.second] + 1;
			Q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}
	int result = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (!board[x][y]) {
				cout << -1 << '\n';
				return 0;
			}
			if (board[x][y] > result) result = board[x][y];
		}
	}
	cout << result-1 << '\n';
	return (0);
}

