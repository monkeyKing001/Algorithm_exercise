#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int l;
  string s;
  cin >> l;
  cin >> s;

  long long res = 0;
  for (int i = 0; i < l; ++i) {
    long long tmp = s[i] - 'a' + 1;
    for (int j = 0; j < i; ++j) {
      tmp = tmp * 31 % 1234567891;
    }
    res = (res + tmp) % 1234567891;
  }
  cout << res;
}
