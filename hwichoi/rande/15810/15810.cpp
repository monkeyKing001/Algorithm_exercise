#include <iostream>

using namespace std;

int n, m;
int arr[1000002];

bool func(long long number) {
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    long long j = number / arr[i];
    cnt += j;
  }
  return cnt >= m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  long long st = 0;
  long long en = 1000000000002;
  while (st != en) {
    long long mid = (st + en) / 2;
    if (func(mid)) en = mid;
    else st = mid+1;
  }
  cout << en;
}
