#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
int n, m;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < k; i++) {
    int x1, y1, x2, y2;
    int r1, c1, r2, c2;
    cin >> x1 >> y1 >> x2 >> y2;
    c1 = x1, c2 = x2 - 1, r1 = n - y2, r2 = n - y1 - 1; 
    for (int r_i = r1; r_i <= r2; r_i++) {
      for (int c_i = c1; c_i <= c2; c_i++) {
        grid[r_i][c_i] = 1;
      }
    }
  }
  queue<info> q;
  multiset<int> area_size_info;
  vector<vector<bool>> v(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!grid[i][j] && !v[i][j]){
        q.push({i, j});
        v[i][j] = true;
        int area_size = 0;
        while (q.size()){
          auto [r, c] = q.front();
          q.pop();
          area_size++;
          for (int di = 0; di < 4; di++) {
            int next_r = r + dr[di];
            int next_c = c + dc[di];
            if (next_r >= 0 && next_r < n \
              && next_c >= 0 && next_c < m \
              && !v[next_r][next_c] && !grid[next_r][next_c]) {
                v[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
          }
        }
        area_size_info.insert(area_size);
      }
    }
  }
  cout << area_size_info.size() << "\n"; 
  for (auto size_ : area_size_info)
    cout << size_ << " "; 
  return (0);
}

