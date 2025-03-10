#include <bits/stdc++.h>

using namespace std;
int n;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<vector<int>> house(n, vector<int>(3, 0));
  vector<vector<int>> dp(n, vector<int>(3, 0));
  for (int i = 0; i < n; i++) 
    cin >> house[i][0] >> house[i][1] >> house[i][2];
  dp[0] = house[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) 
      dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + house[i][j];
  }
  int sol = min(dp[n - 1][0], dp[n - 1][1]);
  sol = min(sol, dp[n - 1][2]);
  cout << sol;
  return (0);
}
