#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
bool board[1002][1002];
int vis[2][1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) board[i][j] = s[j] - '0';
  }

  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  vis[0][0][0] = 1;
  while (!q.empty()) {
    int a, x, y;
    tie(a, x, y) = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny]) {
        if (a) continue;
        vis[1][nx][ny] = vis[0][x][y] + 1;
        q.push({1, nx, ny});
        continue;
      }
      if (vis[a][nx][ny]) continue;
      vis[a][nx][ny] = vis[a][x][y] + 1;
      q.push({a, nx, ny});
    }
  }

  if (vis[1][n-1][m-1]) {
    cout << vis[1][n-1][m-1];
    return 0;
  }
  if (vis[0][n-1][m-1]) {
    cout << vis[0][n-1][m-1];
    return 0;
  }
  cout << -1;
}
