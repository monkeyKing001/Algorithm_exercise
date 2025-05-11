#include <bits/stdc++.h>

using namespace std;
int n, m;
using rc = pair<int, int>;
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int> (m, 0));
  vector<vector<bool>> v(n, vector<bool> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int ocr_count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] && !v[i][j]) {
        ocr_count++;
        queue <rc> q;
        v[i][j] = true;
        q.push({i, j});
        while (q.size()){
          auto [r, c] = q.front();
          q.pop();
          for (int di = 0; di < 8; di++) {
            int next_r = r + dr[di];
            int next_c = c + dc[di];
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m){
              if (!v[next_r][next_c] && arr[next_r][next_c]){
                v[next_r][next_c] = true;
                q.push({next_r, next_c});
              }
            }
          }
        }
      }
    }
  }
  cout << ocr_count;
  return (0);
}

