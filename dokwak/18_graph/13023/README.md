# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1. Find the node if there is any node that has over 5 depth. wrong with 
-> wrong in case 2.
2. Find the all of the distance from one node to another?

# Approach
<!-- Describe your approach to solving the problem. -->
recursion + dfs

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n ^ 3) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n ^ 2) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

 contents

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
<summary> <font size="3"> Trouble 1. TLE </font> </summary>
<div markdown="1">

for starting every point with dfs failed with TLE.
    -> solved with global variable for stop condition.

</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<bool> visited;
vector<vector<int>> g;
int deepest_depth_ = 1;
vector<int> depth;

int rec(int cur, int prev){
  if (deepest_depth_ >= 5)
    return (5);
  visited[cur] = true;
  //cout << "from, to : "<< prev << ", " << cur << "\n";
  depth[cur] = 1;
  for (int i = 0; i < g[cur].size(); i++){
    int fri = g[cur][i];
    if (fri == prev || visited[fri]) continue;
    else{
      depth[cur] = max(depth[cur], rec(fri, cur) + 1);
    }
  }
  deepest_depth_ = max(deepest_depth_, depth[cur]);
  visited[cur] = false;
  return (depth[cur]);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n && deepest_depth_ < 5; i++){
    //cout << "start point : " << i << "\n";
    depth.resize(n, -1);
    visited.resize(n, false);
    rec(i, -1);
  }
  int sol = 0;
  if (deepest_depth_ >= 5) sol = 1;
  cout << sol;
  return (0);
}

```

