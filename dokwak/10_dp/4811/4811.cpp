#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<ll>> dp(31, vector<ll> (31, 0));
  //make dp
  for (int i = 1 ; i < 31; i++){
    for (int j = 0; j <= i; j++) {
      if (j != 0) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      else dp[i][j] = 1;
    }
  }
  cin >> n;
  while (n) {
    cout << dp[n][n] << "\n";
    cin >> n;
  }
  return (0);
}
