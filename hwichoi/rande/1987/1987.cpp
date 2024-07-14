#include <iostream>

using namespace std;
int n, m, maxi;
string s[22];
int vis[22][22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int x, int y, int dep) {
  maxi = max(dep, maxi);
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vis[nx][ny]) continue;
    int bi = s[nx][ny] - 'A';
    if (vis[x][y] & (1 << bi)) continue;
    vis[nx][ny] = vis[x][y] | (1 << bi);
    func(nx, ny, dep+1);
    vis[nx][ny] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  vis[0][0] = 1 << (s[0][0] - 'A');
  func(0, 0, 1);

  cout << maxi;
}
