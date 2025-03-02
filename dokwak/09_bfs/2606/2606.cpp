#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<bool> v(n + 1, false);
  queue<int> q;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  q.push(1);
  v[1] = true;
  int contaminated = 0;
  while (q.size()){
    int node = q.front();
    q.pop();
    for (auto next : g[node]){
      if (!v[next]){
        v[next] = true;
        q.push(next);
        contaminated++;
      }
    }
  }
  cout << contaminated;
  return (0);
}

