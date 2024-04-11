#include <iostream>

using namespace std;

int n, m;
int arr[1002];
int arr2[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> arr2[i];
  }
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i] == arr2[j]) {
        cnt++;
        break;
      }
    }
  }
  cout << m-cnt;
}
