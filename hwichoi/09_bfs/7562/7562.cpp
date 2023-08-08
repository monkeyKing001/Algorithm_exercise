#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int tc, n, a, b, c, d;
int dist[302][302];
int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			fill(dist[i], dist[i] + n, -1);
		cin >> a >> b;
		dist[a][b] = 0;
		queue<pair<int, int>> Q;
		Q.push({a, b});
		cin >> c >> d;
		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();
			if (cur.first == c && cur.second == d) {
				cout << dist[cur.first][cur.second] << '\n';
				break;
			}
			for (int dir = 0; dir < 8; ++dir) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({nx, ny});
			}
		}
	}
	return (0);
}

