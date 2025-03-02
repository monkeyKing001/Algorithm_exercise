# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Visitd with BFS way from node 1.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. Failed to change direct grand to undirect graph </font> </summary>
<div markdown="1">

Counterexample:
```
7
2
1 7
7 2

ans
2

my output
1
```

Simply change direct graph to undirect graph sorted by node number doesnt match with original direct graph.

example:
edge info with
1 7
7 2

change to direct graph sorted by node number
1 -> 7
2 -> 7

is different with 
1 - 7 - 2

</div>
</details>

# Code

```cpp []
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

```

