#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n, m;
int board[302][302];
bool vis[302][302];
int sub[302][302];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}
	int tmp = 1;
	int year = 0;
	while (tmp != 0) {
		year++;
		for (int i = 0; i < n; ++i)
			fill(sub[i], sub[i] + m, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] > 0) continue;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] <= 0) continue;
					sub[nx][ny]++;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				board[i][j] -= sub[i][j];
		}
		for (int i = 0; i < n; ++i)
			fill(vis[i], vis[i] + m, 0);
		tmp = 0;
		for (int i = 1; i < n-1; ++i) {
			for (int j = 1; j < m-1; ++j) {
				if (board[i][j] <= 0 || vis[i][j]) continue;
				++tmp;
				Q.push({i, j});
				vis[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx == 0 || nx == n-1 || ny == 0 || ny == m-1) continue;
						if (board[nx][ny] <= 0 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
		if (tmp > 1) {
			cout << year << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return (0);
}

