#include <iostream>

using namespace std;

int n;
long long arr[300000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    total += arr[i];
  }
  long long avr = total / n;
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > avr) {
      long long dif = arr[i] - avr;
      arr[i] = avr;
      arr[i+1] += dif;
      cnt += dif;
    }
    if (arr[i] < avr) {
      long long dif = avr - arr[i];
      arr[i] = avr;
      arr[i+1] -= dif;
      cnt += dif;
    }
  }
  cout << cnt;
}
