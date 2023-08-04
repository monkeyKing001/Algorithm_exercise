#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int board[502][502];
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int> > Q;
	vis[0][0] = 1;
	Q.push({0, 0});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		cout << '(' << cur.first << ", " << cur.second << ") -> ";
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}
