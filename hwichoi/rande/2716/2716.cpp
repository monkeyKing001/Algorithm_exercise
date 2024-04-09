#include <iostream>

using namespace std;

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin.ignore();
  while (n--) {
    long cnt = 0;
    long max = 0;
    string s;
    getline(cin, s);
    for (char c : s) {
      if (c == '[') cnt++;
      else cnt--;
      if (cnt > max) max = cnt;
    }
    cout << (1 << max) << '\n';
  }
}
