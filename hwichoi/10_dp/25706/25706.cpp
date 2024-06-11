#include <iostream>

using namespace std;

int n;
int arr[200002];
int dp[400004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  for (int i = n-1; i >= 0; --i) {
    dp[i] = dp[i+arr[i]+1] + 1;
  }

  for (int i = 0; i < n; ++i) cout << dp[i] << ' ';
}
