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

  int en = 0;
  int tmp = arr[0];
  int res = 100002;
  for (int st = 0; st < n; ++st) {
    while (en < n && tmp < m) tmp += arr[++en];
    if (en == n) break;
    res = min(en - st + 1, res);
    tmp -= arr[st];
  }
  if (res == 100002) cout << 0;
  else cout << res;
}
