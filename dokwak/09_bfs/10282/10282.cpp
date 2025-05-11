#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>; //time, node;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 0;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    int com, dep, start;
    cin >> com >> dep >> start;
    vector<vector<info>> g(com + 1);
    for (int i = 0; i < dep; i++) {
      int u, v, t;
      cin >> u >> v >> t;
      g[v].push_back({u, t});
    }
    priority_queue<info, vector<info>, greater<info>> pq;
    vector<int> v_time(com + 1, INT_MAX);
    pq.push({0, start});
    v_time[start] = 0;
    int last_time = 0, total_v = 0;
    while (pq.size()){
      auto [time, com] = pq.top();
      pq.pop();
      if (v_time[com] < time) continue;
      total_v++;
      last_time = max(last_time, time);
      for (int i = 0; i < g[com].size(); i++) {
        auto [next, next_time] = g[com][i];
        if (v_time[next] > time + next_time) {
          pq.push({time + next_time, next});
          v_time[next] = time + next_time;
        }
      }
    }
    cout << total_v << " " << last_time << "\n";
  }
  return (0);
}

