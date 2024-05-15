#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1002];
int d[1002];
int di[1002];

void recur(int idx) {
  if (idx == 0) {
    return;
  }
  recur(di[idx]);
  cout << arr[idx] << ' ';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    int mxi = 0;
    for (int j = i-1; j >= 0; --j) {
      if (arr[i] > arr[j] && d[j] > mx) {
        mx = d[j];
        mxi = j;
      }
    }
    d[i] = mx + 1;
    di[i] = mxi;
  }

  int high = max_element(d, d+n+1) - d;
  cout << d[high] << '\n';
  recur(high);
}
