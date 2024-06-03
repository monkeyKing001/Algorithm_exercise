#include <iostream>

using namespace std;

int n;
pair<int, int> arr[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int st, en;
    cin >> st >> en;
    arr[i] = {en, st};
  }
  sort(arr, arr+n);
  int res = 0;
  int tmp = 0;
  for (int i = 0; i < n; ++i) {
    int st = arr[i].second;
    int en = arr[i].first;
    if (st < tmp) continue;
    res++;
    tmp = en;
  }

  cout << res;
}
