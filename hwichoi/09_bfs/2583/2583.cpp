#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
int n, m, k;
int board[102][102];
bool vis[102][102];
queue<pair<int, int>> Q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; ++i)
			for (int j = a; j < c; ++j)
				board[i][j] = 1;
	}
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (vis[i][j] || board[i][j]) continue;
			int size = 1;
			vis[i][j] = 1;
			Q.push({i, j});
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					size++;
					Q.push({nx, ny});
				}
			}
			res.push_back(size);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i : res) cout << i << ' ';
	return (0);
}

