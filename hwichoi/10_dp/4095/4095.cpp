#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[1002][1002];
int dp[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  while (n != 0 && m != 0) {
    for (int i = 0; i <= n; ++i) fill(dp[i], dp[i]+m+1, 0);

    int res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        bool input;
        cin >> input;
        if (!input) continue;
        dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        res = max(dp[i][j], res);
      }
    }

    cout << res << '\n';
    cin >> n >> m;
  }
}
