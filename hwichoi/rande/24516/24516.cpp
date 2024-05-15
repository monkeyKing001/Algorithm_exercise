#include <iostream>

using namespace std;

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cout << 2 * i << ' ';   
  }

  cout << '\n';
}
