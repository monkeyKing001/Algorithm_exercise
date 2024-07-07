#include <iostream>
#include <set>

using namespace std;

int t, n;
int arr[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      s.insert(arr[i]);
    }
    sort(arr, arr+n);
    int res = 0;
    for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
        int diff = arr[j] - arr[i];
        if (s.count(arr[j]+diff)) res++;
      }
    }
    cout << res << '\n';
  }
}
