#include <iostream>
#include <queue>

using namespace std;

int n, m;
string board[300];
bool vis[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> board[i];

  int ores = 0; int vres = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j] || board[i][j] == '#') continue;
      int ocnt = 0; int vcnt = 0;
      q.push({i, j});
      vis[i][j] = 1;
      bool flag = 0;
      while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        if (board[tmp.first][tmp.second] == 'o') ocnt++;
        if (board[tmp.first][tmp.second] == 'v') vcnt++;
        for (int dir = 0; dir < 4; ++dir) {
          int nx = tmp.first + dx[dir];
          int ny = tmp.second + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            flag = 1;
            continue;
          }
          if (vis[nx][ny] || board[nx][ny] == '#') continue;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
      if (flag) continue;
      if (ocnt > vcnt) ores += ocnt;
      else vres += vcnt;
    }
  }
  cout << ores << ' ' << vres;
}
