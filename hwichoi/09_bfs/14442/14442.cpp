#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
bool board[1002][1002];
int res[12][1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) board[i][j] = s[j] - '0';
  }

  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  res[0][0][0] = 1;
  while (!q.empty()) {
    int a, x, y;
    tie(a, x, y) = q.front(); q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny]) {
        if (a >= k || res[a+1][nx][ny]) continue;
        res[a+1][nx][ny] = res[a][x][y] + 1;
        q.push({a+1, nx, ny});
        continue;
      }
      if (res[a][nx][ny]) continue;
      res[a][nx][ny] = res[a][x][y] + 1;
      q.push({a, nx, ny});
    }
  }

  int mini = 2147483647;
  for (int i = k; i >= 0; --i) {
    if (res[i][n-1][m-1]) {
      mini = min(mini, res[i][n-1][m-1]);
    }
  }
  if (mini == 2147483647) cout << -1;
  else cout << mini;
}
