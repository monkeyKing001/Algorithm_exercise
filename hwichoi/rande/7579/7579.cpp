#include <iostream>

using namespace std;

int n, m;
int mem[102], c[102];
long long dp[102][10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) cin >> mem[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];

  int res = 10001;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 10000; ++j) {
      if (j < c[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + mem[i]);
      if (dp[i][j] >= m) res = min(res, j);
    }
  }
  cout << res;
}
