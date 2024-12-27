# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
1. first, during making graph, detect cycle and cycle start node.
2. find all of cycle member traveling from cycle start node.
3. find distance from all of node to first met cycle member in graph.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">



</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. How to detect cycle </font> </summary>
<div markdown="1">

use union find. if u, v vertices have same parent and some edges connects them again, it has cycle.

</div>
</details>

<details>
<summary> <font size="4"> Tricky point 2. How to find cycle path (cycle nodes) </font> </summary>
<div markdown="1">

use dfs and backtracking. you need cycle_flag arry and visit array

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="4"> Trouble 1. Early break </font> </summary>
<div markdown="1">

 ```c++
bool rec_cycle(int prev, int node){
	visited[node] = true;
	for (int i = 0; i < g[node].size() && !cycle_flag[node]; i++) {
		int c = g[node][i];
		if (c == prev)
			continue;
		if (visited[c]) cycle_flag[node] = true;
		else cycle_flag[node] = rec_cycle(node, c);//if no early break, cycle_flag can be amend (true -> false)
	}
	visited[node] = false;
	return(cycle_flag[node]);
}

 ```

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>

using namespace std;
using info = tuple<int, int, int>;//node, prev, distance;
int n, m;

vector<int> p;
vector<vector<int>> g;
vector<bool> cycle_flag;
unordered_set<int> cycle_member;
vector<bool> visited;

int find_(int u){
	if (p[u] == -1)
		return  u;
	p[u] = find_(p[u]);
	return(p[u]);
}

void union_(int u, int v){
	int p_u = find_(u);
	int p_v = find_(v);
	if (p_v < p_u){
		int temp = p_v;
		p_v = p_u;
		p_u = temp;
	}
	p[p_v] = p_u;
}

bool rec_cycle(int prev, int node){
	visited[node] = true;
	for (int i = 0; i < g[node].size() && !cycle_flag[node]; i++) {
		int c = g[node][i];
		if (c == prev)
			continue;
		if (visited[c]) cycle_flag[node] = true;
		else cycle_flag[node] = rec_cycle(node, c);
	}
	visited[node] = false;
	return(cycle_flag[node]);

}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cycle_start = 0; 
	cin >> n;
	g.resize(n + 1);
	p.resize(n + 1, -1);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		if (find_(u) != find_(v))
			union_(u, v);
		else
			cycle_start = u;
	}

	//find cycle_members
	visited.resize(n + 1, false);
	cycle_flag.resize(n + 1, false);
	rec_cycle(-1, cycle_start);

	for (int i = 0; i < n; i++) {
		int node = i + 1;
		int dist = 0;
		if (!cycle_flag[node]){
			queue<info> q;
			q.push({node, -1, 0});
			while (q.size() && !dist){
				auto [cur, prev, step] = q.front();
				q.pop();
				for (auto c: g[cur]){
					if (c == prev)
						continue;
					if (!cycle_flag[c])
						q.push({c, cur, step + 1});
					else
						dist = step + 1;
				}
			}
		}
		cout << dist << " ";
	}
	return (0);
}

```

