#include <iostream>

using namespace std;

int n;
int arr[50505];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int res = 0;
  for (int i = 0; i < n-1; ++i) {
    res += arr[i] * arr[i] * 2 + arr[i+1] * arr[i+1] * 2;
  }

  cout << res;
}
