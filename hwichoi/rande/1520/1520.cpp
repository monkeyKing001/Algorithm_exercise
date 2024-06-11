#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[503][503];
int dp[503][503];
bool vis[503][503];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];

  priority_queue<pair<int, pair<int, int>>> q;
  q.push({board[0][0], {0, 0}});
  dp[0][0] = 1;
  while (!q.empty()) {
    pair<int, int> tmp = q.top().second; q.pop();
    if (vis[tmp.first][tmp.second]) continue;
    vis[tmp.first][tmp.second] = 1;
    for (int i = 0; i < 4; ++i) {
      int nx = tmp.first + dx[i];
      int ny = tmp.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || board[tmp.first][tmp.second] <= board[nx][ny]) continue;
      q.push({board[nx][ny], {nx, ny}});
      dp[nx][ny] += dp[tmp.first][tmp.second];
    }
  }
  cout << dp[n-1][m-1];
}
