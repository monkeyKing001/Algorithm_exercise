#include <iostream>

using namespace std;

int n, p, q;
int a[103], b[103];
int res[103];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> p >> q;

  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int one = p - q;
  for (int i = 0; i < n; ++i) {
    int diff = b[i] - a[i];
    if (one == 0) {
      if (diff != 0) {
        cout << "NO";
        return 0;
      }
      res[i] = 0;
      continue;
    }
    if (one * diff < 0 || diff % one != 0) {
      cout << "NO";
      return 0;
    }
    res[i] = abs(diff) / abs(one);
    if (res[i] > 10000) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << res[i] << ' ';
}
