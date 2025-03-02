#include <bits/stdc++.h>

using namespace std;
int n, m;
int dr[3] = {1, 1, 0};
int dc[3] = {0, 1, 1};
using pos = pair<int, int>;

int rec(vector<vector<int>> &grid, vector<vector<int>> &dp, pos now){
  auto [r, c] = now;
  if (r == n - 1 && c == m - 1)
    dp[r][c] = grid[r][c];
  int &candies = dp[r][c];
  if (candies != -1) return (candies);
  for (int di = 0; di < 3; di++) {
    int next_r = r + dr[di];
    int next_c = c + dc[di];
    if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m)
      candies = max(candies, rec(grid, dp, {next_r, next_c}) + grid[r][c]);
  }
  return (candies);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int> (m, 0));
  vector<vector<int>> dp(n, vector<int> (m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int ans = rec(grid, dp, {0, 0});
  cout << ans;
  return (0);
}

