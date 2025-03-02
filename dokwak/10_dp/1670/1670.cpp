#include <bits/stdc++.h>


using namespace std;
int n, m;
int mod = 987654321;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<int>> dp(n / 2 + 1, vector<int>(n / 2 + 1, 0));
  for (int i = 0; i <= n / 2; i++) {
    for (int j = i; j <= n / 2; j++) {
      if (i == 0){
        dp[i][j] = 1;
      }
      else{
        dp[i][j] = (dp[i - 1][j] % mod) + (dp[i][j - 1] % mod);
        dp[i][j] %= mod;
      }  
    }
  }
  cout << dp[n/2][n/2] % mod;
  return (0);
}

