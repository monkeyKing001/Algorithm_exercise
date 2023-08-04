#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;

int board[502][502];
bool vis[502][502];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> board[x][y];
			vis[x][y] = 0;
		}
	}
	int tmp, ret, cnt;
	ret = 0;
	cnt = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (!board[x][y] || vis[x][y]) continue;
			++cnt;
			vis[x][y] = 1;
			Q.push({x, y});
			tmp = 0;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				++tmp;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (!board[nx][ny] || vis[nx][ny]) continue;
					Q.push({nx, ny});
					vis[nx][ny] = 1;
				}
			}
			if (tmp > ret) ret = tmp;
		}
	}
	cout << cnt << endl << ret << endl;
	return (0);
}
