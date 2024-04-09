#include <iostream>

using namespace std;

int n;
string s = "pPAp";

int main(void) {
  cin >> n;
  string s2;
  cin >> s2;
  int i = 0;
  int cnt = 0;
  for (int idx = 0; idx < n; ++idx) {
    if (s2[idx] == s[i]) i++;
    else {
      if (s2[idx] == 'p') idx--;
      i = 0;
    }
    if (i == 4) {
      cnt++;
      i = 0;
    }
  }
  cout << cnt;
}
