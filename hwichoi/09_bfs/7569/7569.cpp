#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n, m, h;
int board[102][102][102];
int dist[102][102][102];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
queue<tuple<int, int, int>> Q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			fill(dist[i][j], dist[i][j] + m, -1);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					Q.push({i, j, k});
					dist[i][j][k] = 0;
				}
			}
	int res = 0;
	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; ++dir) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if (dist[nx][ny][nz] != -1 || board[nx][ny][nz] == -1) continue;
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({nx, ny, nz});
			if (dist[nx][ny][nz] > res) res = dist[nx][ny][nz];
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (dist[i][j][k] == -1 && board[i][j][k] != -1) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << res << '\n';
	return (0);
}

