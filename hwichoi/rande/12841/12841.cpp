#include <iostream>

using namespace std;

int n;
int a[100002], b[100002], c[100002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n-1; ++i) {
    cin >> b[i];
  }
  long long sum = 0;
  for (int i = 1; i <= n-1; ++i) {
    cin >> c[i];
    sum += c[i];
  }

  int mini = 1;
  sum += a[1];
  long long min = sum;
  for (int i = 2; i <= n; ++i) {
    sum = sum - c[i-1] - a[i-1] + b[i-1] + a[i];
    if (sum < min) {
      min = sum;
      mini = i;
    }
  }
  cout << mini << ' ' << min << '\n';
}
