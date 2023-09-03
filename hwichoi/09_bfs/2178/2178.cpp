#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n, m;
int board[102][102];
bool vis[102][102];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int x = 0; x < n; ++x) {
		string input;
		cin >> input;
		for(int y = 0; y < m; ++y) {
			board[x][y] = input[y] - '0';
		}
	}
	vis[0][0] = 1;
	Q.push({0, 0});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (!board[nx][ny] || vis[nx][ny]) continue;
			Q.push({nx, ny});
			board[nx][ny] = board[cur.first][cur.second] + 1;
			if (nx == n - 1 && ny == m - 1)
				cout << board[nx][ny] << '\n';
			vis[nx][ny] = 1;
		}
	}
	return (0);
}

