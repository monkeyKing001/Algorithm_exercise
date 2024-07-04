#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr+n);

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    bool flag = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int num = upper_bound(arr, arr+n, arr[i]-arr[j]) - lower_bound(arr, arr+n, arr[i]-arr[j]);
      if (num > 0) {
        if (arr[i]-arr[j] == arr[i] && arr[i] == arr[j]) {
          if (num > 2) flag = 1;
          continue;
        }
        else if (num > 1) flag = 1;
        else if (arr[i]-arr[j] != arr[i] && arr[i]-arr[j] != arr[j]) flag = 1;
      }
    }
    if (flag) cnt++;
  }

  cout << cnt;
}
