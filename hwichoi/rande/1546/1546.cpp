#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int maxi = 0;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    maxi = max(maxi, input);
    total += input;
  }

  double res = total;
  res /= n;
  res = res / maxi * 100;
  cout << res;
}
