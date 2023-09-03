#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>
using namespace std;

char board[1002][1002];
int dis[1002][1002];
int fdis[1002][1002];
bool vis[1002][1002] = {};
bool fvis[1002][1002] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> J, F;
    for (int i = 0; i < n; i++) {
        fill(dis[i], dis[i] + m, -1);
        fill(fdis[i], fdis[i] + m, -1);
    }
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> board[x][y];
			if (board[x][y] == 'J') {
				J.push({x, y});
				vis[x][y] = 1;
				dis[x][y] = 0;
			}
			else if (board[x][y] == 'F') {
				F.push({x, y});
				fvis[x][y] = 1;
				fdis[x][y] = 0;
			}
		}
	}
	while (!F.empty()) {
		pair<int, int> cur = F.front();
		F.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '#' || fvis[nx][ny]) continue;
			fdis[nx][ny] = fdis[cur.first][cur.second] + 1;
			fvis[nx][ny] = 1;
			F.push({nx, ny});
		}
	}
	while (!J.empty()) {
		pair<int, int> cur = J.front();
		J.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dis[cur.first][cur.second]+1 << '\n';
				return 0;
			}
			if (board[nx][ny] == '#' || vis[nx][ny]) continue;
			if (fdis[nx][ny] != -1 && dis[cur.first][cur.second]+1 >= fdis[nx][ny]) continue;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			vis[nx][ny] = 1;
			J.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE\n";
	return (0);
}
