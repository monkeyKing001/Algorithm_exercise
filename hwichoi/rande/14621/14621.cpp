#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n, m;
char se[1005];
vector<tuple<int, int, int>> e;
int inf = 2147483647;
vector<int> parent(1005, -1);

int f(int x) {
  if (parent[x] < 0) return x;
  return parent[x] = f(parent[x]);
}

bool u(int x, int y) {
  x = f(x);
  y = f(y);

  if (x == y) return 0;
  if (parent[x] == parent[y]) parent[x]--;
  if (x < y) parent[y] = x;
  else parent[x] = y;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> se[i];

  for (int i = 1; i <= m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    if (se[u] == se[v]) continue;
    e.push_back({d, u, v});
  }

  sort(e.begin(), e.end());

  int res = 0;
  int cnt = 0;
  for (tuple<int, int, int> t : e) {
    int a, b, cost;
    tie(cost, a, b) = t;
    if (!u(a, b)) continue;
    res += cost;
    cnt++;
    if (cnt == n-1) break;
  }

  if (cnt == n-1) cout << res;
  else cout << -1;
}
