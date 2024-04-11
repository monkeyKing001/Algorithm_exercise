#include <iostream>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    int n;
    int tmp = 0;
    cin >> n;
    while (n--) {
      int input;
      cin >> input;
      tmp++;
      if (input == tmp) {
        tmp++;
      }
    }
    cout << tmp << '\n';
  }
}
