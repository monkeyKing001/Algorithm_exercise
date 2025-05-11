# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

dfs, bfs, Dijkstra

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. start point can visit twice </font> </summary>
<div markdown="1">

Not initinalizing start point distance occurs error 
```case
3 3 2 1
1 2
2 1
2 3

wrong ans
1
3

correct ans
1
3

```

</div>
</details>

# Code
```cpp []

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

```

