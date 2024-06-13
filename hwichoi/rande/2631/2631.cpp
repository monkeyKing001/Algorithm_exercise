#include <iostream>

using namespace std;

int n;
int arr[202];
int dp[202];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    int tmp = 0;
    for (int j = i-1; j >= 0; --j) {
      if (arr[j] < arr[i]) tmp = max(tmp, dp[j]);
    }
    dp[i] = tmp + 1;
  }
  cout << n - *max_element(dp, dp+n);
}
