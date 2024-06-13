#include <iostream>

using namespace std;

int n;
int city[101010], road[101010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; ++i) cin >> road[i];
  for (int i = 0; i < n; ++i) cin >> city[i];

  int mini = city[0];
  long long tmp = 0;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    tmp += road[i];
    if (mini > city[i] || i == n) {
      res += mini * tmp;
      mini = city[i];
      tmp = 0;
    }
  }
  cout << res;
}
