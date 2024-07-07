#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool swc[22];
vector<int> se[22];
bool vis[2000000];
int cache[2000000];

int func() {
  int tmp = 0;
  for (int i = 0; i < n; ++i) {
    tmp += (swc[n-i]<<i);
  }
  if (tmp == (1<<n)-1) {
    return 0;
  }
  if (vis[tmp]) {
    return cache[tmp];
  }
  cout << tmp << ' ';
  vis[tmp] = 1;
  int mini = 2100000000;
  for (int i = 1; i <= n; ++i) {
    if (swc[i]) continue;
    swc[i] = !swc[i];
    for (int j : se[i]) {
      swc[j] = !swc[j];
    }
    mini = min(func()+1, mini);
    swc[i] = !swc[i];
    for (int j : se[i]) {
      swc[j] = !swc[j];
    }
  }
  cache[tmp] = mini;
  return mini;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> swc[i];
  for (int i = 1; i <= n; ++i) {
    int cnt;
    cin >> cnt;
    while (cnt--) {
      int tmp;
      cin >> tmp;
      se[i].push_back(tmp);
    }
  }
  fill(cache, cache+2000000, 2100000000);

  int res = func();
  else cout << res;
}

