#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
  dp[1][1] = 1;
  for (int i = 2; i < n + 1; i++){
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] += dp[i - 1][0];
  }
  cout << dp[n][0] + dp[n][1];

  return (0);
}
