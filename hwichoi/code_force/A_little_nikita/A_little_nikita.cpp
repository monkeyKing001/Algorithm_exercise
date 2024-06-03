#include <iostream>

using namespace std;

int t, n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> m;

    int diff = m - n;
    if (n < m) cout << "No\n";
    else if (diff % 2 == 0) cout << "Yes\n";
    else cout << "No\n";
  }
}
