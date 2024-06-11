#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[503][503];
int dp[503][503];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  priority_queue<tuple<int, int, int>> pq;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      pq.push({board[i][j], i, j});
    }

  dp[0][0] = 1;
  while (!pq.empty()) {
    int tmp, x, y;
    tie(tmp, x, y) = pq.top(); pq.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] > tmp) dp[x][y] += dp[nx][ny];
    }
  }
  cout << dp[n-1][m-1];
}
