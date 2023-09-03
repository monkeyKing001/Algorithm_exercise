#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n;
string board[102];
bool vis[102][102] = {};
bool vis2[102][102] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}
	int tmp = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (vis[x][y]) continue;
			Q.push({x, y});
			vis[x][y] = 1;
			++tmp;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	cout << tmp << " ";
	tmp = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (vis2[x][y]) continue;
			Q.push({x, y});
			vis2[x][y] = 1;
			++tmp;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis2[nx][ny]) continue;
					if ((board[cur.first][cur.second] == 'B' && board[nx][ny] != 'B') || (board[cur.first][cur.second] != 'B' && board[nx][ny] == 'B')) continue;
					vis2[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	cout << tmp << '\n';
	return (0);
}

