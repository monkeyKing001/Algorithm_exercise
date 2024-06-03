#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int cray[52];
pair<int, bool> box[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> cray[i];
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int input;
    cin >> input;
    box[i] = {input, 0};
  }
  sort(cray, cray+n);
  sort(box, box+m);
  if (cray[n-1] < box[m-1].first) {
    cout << -1;
    return 0;
  }

  int res = 0;
  int cnt = 0;
  while (cnt < m) {
    int tmp = m-1;
    for (int i = n-1; i >= 0; --i) {
      while (tmp >= 0 && box[tmp].first > cray[i] || box[tmp].second) {
        tmp--;
        if (tmp < 0) break;
      }
      if (tmp < 0) break;
      box[tmp].second = true;
      cnt++;
    }
    res++;
  }
  cout << res;
}
