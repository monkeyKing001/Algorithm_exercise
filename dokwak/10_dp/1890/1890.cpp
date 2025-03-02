#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<ll>> grid(n, vector<ll>(n, 0));
  vector<vector<ll>> dp(n, vector<ll>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
      if (cur_count == -1 || (i == n - 1 && j == n - 1)) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n){
          if (dp[next_r][next_c] == -1) dp[next_r][next_c] = 0;
          dp[next_r][next_c] += cur_count;
        }
      }
    }
  }
  if (dp[n - 1][n - 1] == -1) dp[n - 1][n - 1] = 0;
  cout << dp[n - 1][n - 1];
  return (0);
}


