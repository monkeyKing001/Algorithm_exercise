#include <iostream>

using namespace std;

int n, m;
string board[1003];
int dp[1003][1003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> board[i];

  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int tmpi = i+1;
      int tmpj = j+1;
      if (board[i][j] == '0') {
        dp[tmpi][tmpj] = 0;
        continue;
      }
      dp[tmpi][tmpj] = min({dp[tmpi-1][tmpj-1], dp[tmpi][tmpj-1], dp[tmpi-1][tmpj]}) + 1;
      maxi = max(maxi, dp[tmpi][tmpj]);
    }
  }
  cout << maxi*maxi;
}
