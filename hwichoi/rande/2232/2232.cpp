#include <iostream>

using namespace std;

int n;
int arr[50002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  arr[0] = 0;
  arr[n+1] = 0;
  
  for (int i = 1; i <= n; ++i) {
    if (arr[i-1] <= arr[i] && arr[i] >= arr[i+1]) {
      cout << i << '\n';
    }
  }
}
