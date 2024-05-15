#include <iostream>

using namespace std;

int n;
int q;
bool arr[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    while (a <= n) {
      arr[a] = true;
      a += b;
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!arr[i]) {
      cnt++;
    }
  }
  cout << cnt;
}
