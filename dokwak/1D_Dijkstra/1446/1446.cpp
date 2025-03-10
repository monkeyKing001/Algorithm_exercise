#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>; //cost, 
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<int> distance (10001, 1e6);
  vector<map<int, int>> g(10001);
  for (int i = 0; i < n; i++) {
    int u, v, cut_cost;
    cin >> u >> v >> cut_cost;
    if (g[u].find(v) != g[u].end()) g[u][v] = min(g[u][v], cut_cost);
    else g[u][v] = cut_cost;
  }
  priority_queue<info, vector<info>, greater<info>> pq;
  distance[0] = 0;
  pq.push({0, 0});
  while (pq.size()){
    auto [cost, node] = pq.top();
    pq.pop();
    if (distance[node] < cost) continue;
    if (node > m) continue;
    distance[node] = cost;
    if (g[node].size()){// if there is short cur from current node, take it.
      for (auto [next_node, cut_cost] : g[node]){
        if (next_node <= m && distance[next_node] > cost + cut_cost){
          distance[next_node] = cost + cut_cost;
          pq.push({cost + cut_cost, next_node});
        }
      }
    }
    pq.push({cost + 1, node + 1});
  }
  cout << distance[m];
  return (0);
}

