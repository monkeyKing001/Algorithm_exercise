#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> arr(n, 0);
  for (auto &a_ : arr) cin >> a_;
  vector<int> dp(n, INT_MIN);
  dp[0] = arr[0];
  int ans = dp[0];
  for (int i = 1; i < n; i++){
    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return (0);
}

