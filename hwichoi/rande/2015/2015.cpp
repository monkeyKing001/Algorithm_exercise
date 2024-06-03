#include <iostream>
#include <map>

using namespace std;

long long n, m;
long long arr[200003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  map<long long, long long> mp;
  for (int i = 1; i <= n; ++i) {
    int input;
    cin >> input;
    arr[i] = arr[i-1] + input;
  }

  long long res = 0;
  for (int i = 0; i <= n; ++i) {
    int tmp = arr[i];
    res += mp[tmp-m];
    mp[tmp]++;
  }
  cout << res;
}
