#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n, m, k, tc;
int board[52][52] = {};
bool vis[52][52] = {};
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> m >> n >> k;
		for (int i = 0; i < n; ++i) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, 0);
		}
		while (k--) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int tmp = 0;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (vis[x][y] || board[x][y] == 0) continue;
				++tmp;
				Q.push({x, y});
				vis[x][y] = 1;
				while (!Q.empty()) {
					pair<int ,int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
		cout << tmp << '\n';
	}
	return (0);
}

