# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(nlogn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1. suppose that distance point as node. </font> </summary>
<div markdown="1">

Suppose that node (n), (n + 1)

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
<summary> <font size="3"> Trouble 1. Memoization timing </font> </summary>
<div markdown="1">

2 timing.
1. when pushing pq
2. when poping pq

be careful memoization when it is shortest path.

</div>
</details>

<details>
<summary> <font size="3"> Trouble 2. Early break </font> </summary>
<div markdown="1">

pq stop when point over m shouldn't be considered.

</div>
</details>

# Code
```cpp []

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

```

