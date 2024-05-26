#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  sort(arr, arr+n);
  int j = 0;
  int res = 2147483647;
  for (int i = 0; i < n; ++i) {
    while (arr[j] - arr[i] < m) j++;
    if (j >= n) break;
    res = min(res, arr[j] - arr[i]);
  }
  cout << res;
}
