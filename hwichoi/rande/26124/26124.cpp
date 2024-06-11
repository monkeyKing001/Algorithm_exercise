#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[1002][1002];
bool vis[1002][1002];
vector<pair<int, pair<int, int>>> sorted;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int func() {
  int mxi, mxy;
  int maxi = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (vis[i][j]) continue;
      if (maxi < board[i][j]) {
        maxi = board[i][j];
        mxi = i;
        mxy = j;
      }
    }
  if (maxi == 0) return 1;
  queue<pair<int, int>> q;
  q.push({mxi, mxy});
  vis[mxi][mxy] = 1;
  while (!q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = tmp.first + dx[i];
      int ny = tmp.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny]) continue;
      int a = board[tmp.first][tmp.second];
      int b = board[nx][ny];
      if (abs(a-b) > 1) return -1;
      if (a - 1 == b || (a == 0 && b == 0)) {
        vis[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      sorted.push_back({board[i][j], {i, j}});
      if (board[i][j] == -1) vis[i][j] = 1;
    }

  int ret = 0;
  while (true) {
    int tmp = func();
    if (func() == 1) break;
    ret++;
  }
  cout << ret;
}
