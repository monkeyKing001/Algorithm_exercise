#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> arr(n);
  int ans = INT_MIN;
  vector<vector<int>> dp(2, vector<int>(n, 0));
  for (int i = 0; i < n; i++) 
    cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (i > 0){
      dp[1][i] = max(dp[1][i - 1] + arr[i], arr[i]);
      dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
      dp[0][i] = max(dp[0][i], dp[1][i - 1]);
    }
    else{
      dp[1][i] = arr[i];
      dp[0][i] = -1 * 1e9;
    }
    ans = max(ans, dp[1][i]);
    ans = max(ans, dp[0][i]);
  }
  cout << ans;
  return (0);
}

