#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<ll>> dp(10001, vector<ll>(4, 0));
  dp[0][1] = 1;
  dp[1][1] = 1;
  dp[2][1] = 1, dp[2][2] = 1;
  for (int i = 3; i < dp.size(); i++){
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= j; k++){
        dp[i][j] += dp[i - j][k];
      }
    }
  }
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    int num;
    cin >> num;
    cout << dp[num][1] + dp[num][2] +  dp[num][3] << "\n";
  }
  return (0);
}

