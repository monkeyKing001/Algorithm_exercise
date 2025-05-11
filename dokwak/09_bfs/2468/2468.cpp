#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<int>> area(n, vector<int> (n, 0));
  int max_h = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> area[i][j];
      max_h = max(area[i][j], max_h);
    }
  }
  int sol = 1;
  for (int h = 1; h < max_h; h++) {
    vector<vector<bool>> v(n, vector<bool> (n, false));
    int safe_zone = 0;
    queue<pos> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!v[i][j] && area[i][j] > h) {
          safe_zone++;
          q.push({i, j});
          v[i][j] = true;
          while (q.size()){
            auto [r, c] = q.front();
            q.pop();
            for (int di = 0; di < 4; di++) {
              int next_r = r + dr[di], next_c = c + dc[di];
              if (next_r >= 0 && next_c >= 0 && next_r < n && next_c < n){
                if (!v[next_r][next_c] && area[next_r][next_c] > h){
                  v[next_r][next_c] = true;
                  q.push({next_r, next_c});
                }
              }
            }
          }
        }
      }
    }
    sol = max(sol, safe_zone);
  }
  cout << sol << "\n";
  return (0);
}

