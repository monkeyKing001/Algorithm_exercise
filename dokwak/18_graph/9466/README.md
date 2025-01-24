# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Find every node that does not make cycle. 


# Approach
<!-- Describe your approach to solving the problem. -->
In direct graph, there are 3 ways to detect cycle.

1. dfs

2. union-find

3. topology sort

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

In Topology way.
node that has 0 indegree cannot make cycle.

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. queing condition mistake </font> </summary>
<div markdown="1">

wrong code
```
  if (ind[next]) q.push(next);
```

correct code
```
if (!ind[next]) q.push(next);
```

</div>
</details>

<details>
<summary> <font size="3"> Trouble 2. resize static vector undifined behaviour error. </font> </summary>
<div markdown="1">

wrong code
```
  for (int t_i = 0; t_i < T; t_i++) {
    cin >> n;
    //g.clear();
    //ind.clear();
    g.resize(n + 1);
    ind.resize(n + 1, 0);
```

correct code
```
  for (int t_i = 0; t_i < T; t_i++) {
    cin >> n;
    g.clear();
    ind.clear();
    g.resize(n + 1);
    ind.resize(n + 1, 0);
```
### Analyze
static variables remain during whole program runtimes. and .resize doesnt clear the previous datas. initializing with resizing doesnt clear previous memory data.

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> g;
vector<int> ind;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    cin >> n;
    g.clear();
    ind.clear();
    g.resize(n + 1);
    ind.resize(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
      cin >> g[i];
      ind[g[i]]++;
    }
    int ans = 0;
    queue<int> q;
    for (int i = 1; i < n + 1; i++) 
      if (!ind[i]) q.push(i);
    while (q.size()){
      int node = q.front();
      q.pop();
      ans++;
      int next = g[node];
      ind[next]--;
      if (!ind[next]) q.push(next);
    }
    cout << ans << "\n";
  }
	return (0);
}

```

