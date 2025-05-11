#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;//cost,node
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int start, k;
  int max_distance = 1e6+7;
  cin >> n >> m >> k >> start;
  priority_queue<info, vector<info>, greater<info>> pq;
  vector<int> distance(n + 1, max_distance);
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  pq.push({0, start});
  distance[start] = 0;
  set<int> ans;
  while (pq.size()){
    auto [cost, node] = pq.top();
    pq.pop();
    if (distance[node] < cost) continue;
    if (cost == k) {
      ans.insert(node);
      continue;
    }
    for (auto next : g[node]){
      if (distance[next] > cost + 1){
        distance[next] = cost + 1;
        pq.push({distance[next], next});
      }
    }
  }
  if (ans.empty()){
    cout << "-1";
    return (0);
  }
  for (auto a : ans) cout << a << "\n";
  return (0);
}

