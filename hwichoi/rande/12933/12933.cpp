#include <iostream>
#include <algorithm>

using namespace std;

int cnt[6];
int mapper[200];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin >> input;

  mapper['q'] = 1; mapper['u'] = 2; mapper['a'] = 3; mapper['c'] = 4; mapper['k'] = 5;
  cnt[0] = 1000000000;
  int res = 0;
  for (char c : input) {
    if (cnt[mapper[c]-1] == 0) {
      cout << -1;
      return 0;
    }
    cnt[mapper[c]-1]--;
    cnt[mapper[c]]++;
    int tmp = 0;
    for (int i = 1; i <= 4; ++i) tmp += cnt[i];
    res = max(res, tmp);
  }
  for (int i = 1; i <= 4; ++i) {
    if (cnt[i]) {
      cout << -1;
      return 0;
    }
  }
  cout << res;
}
