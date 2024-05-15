#include <iostream>

using namespace std;

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  bool flag = true;
  for (int i = 0; i < n-1; ++i) {
    if (flag) cout << 1 << ' ';
    else cout << 2 << ' ';
    flag = !flag;
  }
  if (n % 2 == 0) cout << 2 << '\n';
  else cout << 3 << '\n';
}
